
// let tz_device_main_mqtt_rpc_topic_name = Cfg.get('rpc.mqtt.topic') || Cfg.get('device.id');

let TZ_RPC = {
  inited: false,
  send_msg_qeue: [],
  main_server_rpc_call_next_id: 872663,
  main_rpc_call_dst: Cfg.get('server.topicName'),
  device_main_mqtt_rpc_topic_name: Cfg.get('rpc.mqtt.topic') || Cfg.get('device.id'),

  send_msgs_from_qeue: function() {
    if (this.send_msg_qeue.length > 0) {
      let old_send_msg_qeue = this.send_msg_qeue;
      // Empty main send_msg_qeue, because it can be filled with new unsended msgs
      this.send_msg_qeue = [];
      for (let i = 0; i < old_send_msg_qeue.length; i++) {
        this.main_server_mqtt_rpc_call(old_send_msg_qeue[i]);
      }
      Timer.set(300, false, function() {
        TZ_RPC.send_msgs_from_qeue();
      }, null);
    }
  },

  main_server_rpc_call: function (method, args, options) {
    if (!options) options = {};
    let rpcData = {
      method: method,
      args: args,
      src: this.device_main_mqtt_rpc_topic_name,
      id: options.id || this.main_server_rpc_call_next_id++,
    };
    return this.main_server_mqtt_rpc_call(rpcData);
  },

  main_server_mqtt_rpc_call: function (rpcData) {
    let sended = MQTT.pub(this.main_rpc_call_dst, JSON.stringify(rpcData), 0);
    // if (!sended) {
    //   if (this.send_msg_qeue.length > 30) {
    //     this.send_msg_qeue = [];
    //   }
    //   this.send_msg_qeue[this.send_msg_qeue.length] = rpcData;
    // }
    return sended;
  },

  init: function() {
    if (this.inited) return;
    MQTT.setEventHandler(function(conn, ev, edata) {
      if (ev === MQTT.EV_CONNACK) {
        print('MQTT CONNECTED');
        if (TZ_RPC.send_msg_qeue.length > 0) {
          let old_send_msg_qeue = this.send_msg_qeue;
          for (let i = 0; i < old_send_msg_qeue.length; i++) {
            TZ_RPC.main_server_mqtt_rpc_call(old_send_msg_qeue[i]);
          }
          TZ_RPC.send_msg_qeue = [];
        }
      }
    }, null);
    this.inited = true;
  }
};

TZ_RPC.init();
