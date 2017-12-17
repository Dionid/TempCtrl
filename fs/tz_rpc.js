
// let tz_device_main_mqtt_rpc_topic_name = Cfg.get('rpc.mqtt.topic') || Cfg.get('device.id');

let TZ_RPC = {
  inited: false,
  send_msg_qeue: [],
  main_server_rpc_call_next_id: 872663,
  main_rpc_call_dst: 'qweyuiasdhjky/p/smart_heater/asdqwezxc/s/rpc',
  device_main_mqtt_rpc_topic_name: Cfg.get('rpc.mqtt.topic') || Cfg.get('device.id'),

  send_msgs_from_qeue: function() {
    if (this.send_msg_qeue.length > 0) {
      let old_send_msg_qeue = this.send_msg_qeue;
      // Empty main send_msg_qeue, because it can be filled with new unsended msgs
      this.send_msg_qeue = [];
      for (let i = 0; i < old_send_msg_qeue.length; i++) {
        this.main_server_mqtt_rpc_call(old_send_msg_qeue[i]);
      }
      this.send_msgs_from_qeue();
    }
  },

  main_server_rpc_call: function (method, args, id) {
    let rpcData = {
      method: method,
      args: args,
      src: this.device_main_mqtt_rpc_topic_name,
      id: id || this.main_server_rpc_call_next_id++,
    };
    return this.main_server_mqtt_rpc_call(rpcData);
  },

  main_server_mqtt_rpc_call: function (rpcData) {
    let sended = MQTT.pub(this.main_rpc_call_dst, JSON.stringify(rpcData), 0);
    if (!sended) {
      this.send_msg_qeue[this.send_msg_qeue.length] = rpcData;
    }
    return sended;
  },

  init: function() {
    if (this.inited) return;
    MQTT.setEventHandler(function(conn, ev, edata) {
      if (ev === MQTT.EV_CONNACK) {
        print('MQTT CONNECTED');
        if (this.send_msg_qeue.length > 0) {
          let old_send_msg_qeue = this.send_msg_qeue;
          for (let i = 0; i < old_send_msg_qeue.length; i++) {
            this.main_server_mqtt_rpc_call(old_send_msg_qeue[i]);
          }
          this.send_msg_qeue = [];
        }
      }
    }, null);
    this.inited = true;
  }
};

TZ_RPC.init();

// let tz_send_msg_qeue = [];
//
// function tz_send_msgs_from_qeue() {
//   if (tz_send_msg_qeue.length > 0) {
//     let old_tz_send_msg_qeue = tz_send_msg_qeue;
//     tz_send_msg_qeue = [];
//     for (let i = 0; i < old_tz_send_msg_qeue.length; i++) {
//       tz_main_server_mqtt_rpc_call(old_tz_send_msg_qeue[i]);
//     }
//     tz_send_msgs_from_qeue();
//   }
// }

// let tz_main_server_rpc_call_next_id = 872663;
//
// function tz_main_server_rpc_call(method, args, id) {
//   let rpcData = {
//     method: method,
//     args: args,
//     src: tz_device_main_mqtt_rpc_topic_name,
//     id: id || tz_main_server_rpc_call_next_id++,
//   };
//   return tz_main_server_mqtt_rpc_call(rpcData);
// }
//
// function tz_main_server_mqtt_rpc_call(rpcData) {
//   let sended = MQTT.pub(tz_get_server_mqtt_rpc_call_topic_name(), JSON.stringify(rpcData), 0);
//   if (!sended) {
//     tz_send_msg_qeue[tz_send_msg_qeue.length] = rpcData;
//   }
//   return sended;
// }
