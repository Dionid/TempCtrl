load('api_log.js');
load('api_rpc.js');

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

  errorDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+Timer.now()+"][error]" + msg;
    // Log.print(Log.ERROR, newMsg);
    print(newMsg);
  },

  warnDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+Timer.now()+"][warn]" + msg;
    // Log.print(Log.WARN, newMsg);
    print(newMsg);
  },

  infoDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+Timer.now()+"][info]" + msg;
    // Log.print(Log.INFO, newMsg);
    print(newMsg);
  },

  debugDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+Timer.now()+"][debug]" + msg;
    // Log.print(Log.DEBUG, newMsg);
    print(newMsg);
  },

  verboseDebugDev: function(deviceId, msg) {
    let newMsg = "[" + deviceId + "]["+Timer.now()+"][verboseDebug]" + msg;
    // Log.print(Log.VERBOSE_DEBUG, newMsg);
    print(newMsg);
  }
};
