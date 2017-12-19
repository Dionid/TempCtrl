load('api_log.js');
load('api_rpc.js');

let tz_register_debug_event_handler = ffi('bool tz_register_debug_event_add_handler(void (*)(int, void *, userdata), userdata)');

let TZLog = {

  error: function(msg) {
    Log.print(Log.ERROR, msg);
  },

  warn: function(msg) {
    Log.print(Log.WARN, msg);
  },

  info: function(msg) {
    Log.print(Log.INFO, msg);
  },

  debug: function(msg) {
    Log.print(Log.DEBUG, msg);
  },

  verboseDebug: function(msg) {
    Log.print(Log.VERBOSE_DEBUG, msg);
  },

  // devicesLogs: {},

  sendDeviceLogMsg: function(deviceId, type, msg) {
    // let sended = TZ_RPC.main_server_rpc_call(deviceId + '.Log', {msg: msg, type: type});
    // if (!sended) {
    //   print('NOT SENDED');
    // }
  },

  // getDevLog: function(deviceId) {
  //   let deviceLogs = this.devicesLogs[deviceId];
  //   if (deviceLogs === undefined) {
  //     this.devicesLogs[deviceId] = [];
  //     return this.devicesLogs[deviceId];
  //   }
  //   return deviceLogs;
  // },

  // preWriteDeviceLogsCheck: function(deviceId, deviceLogs) {
  //   if (deviceLogs.length > 30) {
  //     this.devicesLogs[deviceId] = [];
  //     deviceLogs = this.devicesLogs[deviceId];
  //   }
  // },

  errorDev: function(deviceId, msg) {
    let newMsg = "[error] " + msg;
    // let deviceLogs = this.getDevLog(deviceId);
    // this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    // deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.ERROR, newMsg);
    // this.sendDeviceLogMsg(deviceId, 'error', newMsg);
  },

  warnDev: function(deviceId, msg) {
    let newMsg = "[warn] " + msg;
    // let deviceLogs = this.getDevLog(deviceId);
    // this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    // deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.WARN, newMsg);
    // this.sendDeviceLogMsg(deviceId, 'warn', newMsg);
  },

  infoDev: function(deviceId, msg) {
    let newMsg = "[info] " + msg;
    // let deviceLogs = this.getDevLog(deviceId);
    // this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    // deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.INFO, newMsg);
    // this.sendDeviceLogMsg(deviceId, 'info', newMsg);
  },

  debugDev: function(deviceId, msg) {
    let newMsg = "[debug] " + msg;
    // let deviceLogs = this.getDevLog(deviceId);
    // this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    // deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.DEBUG, newMsg);
    // this.sendDeviceLogMsg(deviceId, 'debug', newMsg);
  },

  verboseDebugDev: function(deviceId, msg) {
    let newMsg = "[verboseDebug] " + msg;
    // let deviceLogs = this.getDevLog(deviceId);
    // this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    // deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.VERBOSE_DEBUG, newMsg);
    // this.sendDeviceLogMsg(deviceId, 'verboseDebug', newMsg);
  }
};

// RPC.addHandler('TZLogs.GetLogs', function(args) {
//   return deb_arr;
// }, null);
//
// RPC.addHandler('TZLogs.CallLogs', function(args) {
//   return TZLog.getDevLog(args.deviceId);
// }, null);

// let deb_arr = [];

// tz_register_debug_event_handler(function(ev, data, userdata) {
//   if (deb_arr.length > 30) deb_arr = [];
//   deb_arr[deb_arr.length] = ev;
//   // TZ_RPC.main_server_rpc_call('Main.Log', data.data);
// }, null);
