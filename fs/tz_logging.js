load('api_log.js');
load('api_rpc.js');

let TZLog = {

  // error: function(msg) {
  //   Log.print(Log.ERROR, msg);
  // },
  //
  // warn: function(msg) {
  //   Log.print(Log.WARN, msg);
  // },
  //
  // info: function(msg) {
  //   Log.print(Log.INFO, msg);
  // },
  //
  // debug: function(msg) {
  //   Log.print(Log.DEBUG, msg);
  // },
  //
  // verboseDebug: function(msg) {
  //   Log.print(Log.VERBOSE_DEBUG, msg);
  // },

  errorDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+JSON.stringify(Timer.now())+"][error]: " + msg;
    print(newMsg);
  },

  warnDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+JSON.stringify(Timer.now())+"][warn]: " + msg;
    print(newMsg);
  },

  infoDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+JSON.stringify(Timer.now())+"][info]: " + msg;
    print(newMsg);
  },

  debugDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+JSON.stringify(Timer.now())+"][debug]: " + msg;
    print(newMsg);
  },

  verboseDebugDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+JSON.stringify(Timer.now())+"][verboseDebug]: " + msg;
    print(newMsg);
  }
};
