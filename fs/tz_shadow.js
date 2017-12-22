
let TZShadow = {
  //   _update: ffi("bool mgos_shadow_update(double, char *)"),
  //   get: ffi("bool mgos_shadow_get()"),
  //
  //   update: function(version, data) {
  //     return this._update(version, JSON.stringify(data));
  //   },
  //
  //   eventName: ffi('char *mgos_shadow_event_name(int)'),
  //
  //   CONNECTED: 0,
  //   GET_ACCEPTED: 1,
  //   GET_REJECTED: 2,
  //   UPDATE_ACCEPTED: 3,
  //   UPDATE_REJECTED: 4,
  //   UPDATE_DELTA: 5,
  //

  _version: 0,
  _serverTopicName: "",
  State: {},
  DeviceId: "",

  GetCurrentVersion: function() {
    return this._version;
  },

  SetCurrentVersion: function(version) {
    this._version = version;
  },

  ConnectReport: function() {
    return MQTT.pub(this._serverTopicName + "/update", JSON.stringify({"reported": this.State, version: this.GetCurrentVersion()}), 1);
  },

  GetShadow: function(acceptedCb, rejectedCb) {
    return RPC.call(this._serverTopicName+"/get", obj.deviceId + ".Shadow.Get", null, function(resp, err_code, err_msg, ud) {
      if (err_code) {
        print(err_code);
        rejectedCb(err_code, err_msg, rejectedCb);
        return true;
      } else {
        acceptedCb(resp, obj);
        return true;
      }
    }, null);
  },

  UpdateReportedAndDesire: function() {
    return MQTT.pub(this._serverTopicName + "/update", JSON.stringify({"reported": this.State, "desired": this.State, version: this.GetCurrentVersion()}), 1);
  },

  init: function(options) {
    let deviceId = options.deviceId;
    let serverId = options.serverId;

    this.State = options.state;
    this.ServerId = serverId;
    this.DeviceId = deviceId;
    this._serverTopicName = serverId + "/" + deviceId;

    RPC.addHandler(deviceId + '.Shadow.Update.Accepted', function(args, sm, obj) {
      if (args.version < TZShadow.GetCurrentVersion()) {
        return;
      }
      TZShadow.SetCurrentVersion(args.version);
      return;
    }, null);

    RPC.addHandler(deviceId + '.Shadow.Get.Accepted', function(args, sm, obj) {
      if (args.version < TZShadow.GetCurrentVersion()) {
        return;
      }
      TZShadow.SetCurrentVersion(args.version);
      return;
    }, null);

    MQTT.setEventHandler(function(conn, ev, edata) {
      print("MQTT.setEventHandler");
      print(JSON.stringify(edata));
      if (ev === MQTT.EV_SUBACK) {
        // print(JSON.stringify(edata));
        TZShadow.ConnectReport();
      }
    }, null);

    RPC.addHandler(deviceId + '.Shadow.Delta', function(args, sm, obj) {
      if (args.version < TZShadow.GetCurrentVersion()) {
        return {};
      }

      let state = {};

      TZShadowDeltaCb(args, state);

      TZShadow.SetCurrentVersion(args.version);

      let response = {
        // reported: state,
        reported: TZShadow.State,
        version: args.version
      };

      // RESPONSE to /:server_id/:shadow_id/update {"reported": ...}
      return response;
    }, null);

    RPC.addHandler(deviceId + '.Shadow.LocalDelta', function(args, sm, obj) {
      let state = {};

      TZShadowDeltaCb(args, state);

      let response = {
        // reported: state,
        // desired: state,
        reported: TZShadow.State,
        desired: TZShadow.State,
        version: TZShadow.GetCurrentVersion()
      };

      // RESPONSE to /:server_id/:shadow_id/update {"reported": ...}
      MQTT.pub(obj.serverRoute+"/update", JSON.stringify(response), 1);

      return true;
    }, null);
  }
};

// function ShadowGetCurrentVersion() {
//   return obj.version;
// }
//
// function ShadowSetCurrentVersion(obj, version) {
//   obj.version = version;
// }
//
// function ShadowConnectReport(obj) {
//   return MQTT.pub(obj.serverRoute+"/update", {"reported": obj.deviceState, version: ShadowGetCurrentVersion(obj)});
// }

// function ShadowReportAndDesire(obj, state) {
//   return MQTT.pub(obj.serverRoute+"/update", {"reported": state, "desire": state, version: ShadowGetCurrentVersion(obj)});
// }

// function ShadowGet(obj, acceptedCb, rejectedCb) {
//   return RPC.call(obj.serverRoute+"/get", obj.deviceId + ".Shadow.Get", null, function(resp, err_code, err_msg, ud) {
//     print(err_code);
//     // REJECTED
//     if (err_code) {
//       rejectedCb(err_code, err_msg, rejectedCb);
//       return true;
//     } else {
//       // ACCEPTED
//       acceptedCb(resp, obj);
//       return true;
//     }
//   }, null);
// }

// function ShadowGetAndSyncState(obj) {
//   return ShadowGet(obj, function(resp, obj){}, function(err_code, err_msg, rejectedCb){});
// }

// function INIT_SHADOW(options) {
//   let deviceId = options.deviceId;
//   let serverId = oprions.serverId;
//   let deviceState = options.deviceState;
//   let obj = {
//     deviceId: deviceId,
//     version: 0,
//     serverId: serverId,
//     serverRoute: serverId+"/"+deviceId,
//     deviceState: deviceState,
//   };
//
//   RPC.addHandler(deviceId + '.Shadow.Update.Accepted', function(args, sm, obj) {
//     if (args.version < ShadowGetCurrentVersion(obj)) {
//       return false;
//     }
//     ShadowSetCurrentVersion(obj, args.version);
//     return true;
//   }, obj);
//
//   RPC.addHandler(deviceId + '.Shadow.Get.Accepted', function(args, sm, obj) {
//     if (args.version < ShadowGetCurrentVersion(obj)) {
//       return false;
//     }
//     ShadowSetCurrentVersion(obj, args.version);
//     return true;
//   }, obj);
//
//   MQTT.setEventHandler(function(conn, ev, edata, obj) {
//     if (ev === MQTT.EV_SUBACK) {
//       print(JSON.stringify(edata));
//       ShadowConnectReport(obj);
//     }
//   }, obj);
//
//   RPC.addHandler(deviceId + '.Shadow.Delta', function(args, sm, obj) {
//     if (args.version < ShadowSetCurrentVersion(obj)) {
//       return {};
//     }
//
//     let reported = {};
//
//     obj.deltaCb(args, resported);
//
//     ShadowSetCurrentVersion(obj, args.version);
//
//     let response = {
//       reported: reported,
//       version: args.version
//     };
//
//     // RESPONSE to /:server_id/:shadow_id/update {"reported": ...}
//     return response;
//   }, obj);
//
//   RPC.addHandler(deviceId + '.Shadow.LocalDelta', function(args, sm, obj) {
//     let state = {};
//
//     obj.deltaCb(args, state);
//
//     let response = {
//       reported: state,
//       desired: state,
//       version: ShadowSetCurrentVersion(obj)
//     };
//
//     // RESPONSE to /:server_id/:shadow_id/update {"reported": ...}
//     MQTT.pub(obj.serverRoute+"/update", JSON.stringify(response));
//
//     return true;
//   }, obj);
//
//   return obj;
// }
