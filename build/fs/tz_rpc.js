
function tz_get_server_mqtt_rpc_call_topic_name() {
  return 'qweyuiasdhjky/p/smart_heater/asdqwezxc/s/rpc';
}

function tz_get_main_rpc_call_dst() {
  // mqtt://iot.eclipse.org:1883/esp8266_238084
  return 'qweyuiasdhjky/p/smart_heater/asdqwezxc/s/rpc';
}

function tz_main_server_rpc_call(method, args) {
  return MQTT.pub(tz_get_server_mqtt_rpc_call_topic_name(), JSON.stringify({
    method: method,
    args: args
  }), 1);
}
