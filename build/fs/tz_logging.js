load('api_log.js');

let TZLog = {
  // ## **`Log.error(msg)`**
  // Shortcut for `Log.print(Log.ERROR, msg)`
  error: function(msg) {
    Log.print(Log.ERROR, msg);
  },

  // ## **`Log.warn(msg)`**
  // Shortcut for `Log.print(Log.WARN, msg)`
  warn: function(msg) {
    Log.print(Log.WARN, msg);
  },

  // ## **`Log.info(msg)`**
  // Shortcut for `Log.print(Log.INFO, msg)`
  info: function(msg) {
    Log.print(Log.INFO, msg);
  },

  // ## **`Log.debug(msg)`**
  // Shortcut for `Log.print(Log.DEBUG, msg)`
  debug: function(msg) {
    Log.print(Log.DEBUG, msg);
  },

  // ## **`Log.verboseDebug(msg)`**
  // Shortcut for `Log.print(Log.VERBOSE_DEBUG, msg)`
  verboseDebug: function(msg) {
    Log.print(Log.VERBOSE_DEBUG, msg);
  },

  devicesLogs: {},

  sendDeviceLogMsg: function(deviceId, type, msg) {
    let sended = tz_main_server_rpc_call(deviceId + '.Log', {msg: msg, type: type});
    if (sended === false) {
      print('NOT SENDED');
    }
    // RPC.call(tz_get_main_rpc_call_dst(), deviceId + '.Log', {msg: msg, type: type}, function(res, deviceId) {
    //   // TZLog.infoDev(deviceId, JSON.stringify());
    //   print(JSON.stringify(res));
    //   print(deviceId);
    // }, deviceId);
  },

  getDevLog: function(deviceId) {
    let deviceLogs = this.devicesLogs[deviceId];
    if (deviceLogs === undefined) {
      this.devicesLogs[deviceId] = [];
      return this.devicesLogs[deviceId];
    }
    return deviceLogs;
  },

  preWriteDeviceLogsCheck: function(deviceId, deviceLogs) {
    if (deviceLogs.length > 200) {
      this.devicesLogs[deviceId] = [];
      deviceLogs = this.devicesLogs[deviceId];
    }
  },

  // ## **`Log.error(msg)`**
  // Shortcut for `Log.print(Log.ERROR, msg)`
  errorDev: function(deviceId, msg) {
    let newMsg = "[error] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.ERROR, newMsg);
    this.sendDeviceLogMsg(deviceId, 'error', newMsg);
  },

  // ## **`Log.warn(msg)`**
  // Shortcut for `Log.print(Log.WARN, msg)`
  warnDev: function(deviceId, msg) {
    let newMsg = "[warn] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.WARN, newMsg);
    this.sendDeviceLogMsg(deviceId, 'warn', newMsg);
  },

  // ## **`Log.info(msg)`**
  // Shortcut for `Log.print(Log.INFO, msg)`
  infoDev: function(deviceId, msg) {
    let newMsg = "[info] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.INFO, newMsg);
    print(JSON.stringify(this.devicesLogs[deviceId]));
    this.sendDeviceLogMsg(deviceId, 'info', newMsg);
  },

  // ## **`Log.debug(msg)`**
  // Shortcut for `Log.print(Log.DEBUG, msg)`
  debugDev: function(deviceId, msg) {
    let newMsg = "[debug] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.DEBUG, newMsg);
    this.sendDeviceLogMsg(deviceId, 'debug', newMsg);
  },

  // ## **`Log.verboseDebug(msg)`**
  // Shortcut for `Log.print(Log.VERBOSE_DEBUG, msg)`
  verboseDebugDev: function(deviceId, msg) {
    let newMsg = "[verboseDebug] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.VERBOSE_DEBUG, newMsg);
    this.sendDeviceLogMsg(deviceId, 'verboseDebug', newMsg);
  }
};


RPC.addHandler('TZLogs.GetLogs', function(args) {
  return TZLog.getDevLog(args.deviceId);
}, null);

RPC.addHandler('TZLogs.CallLogs', function(args) {
  return TZLog.getDevLog(args.deviceId);
}, null);
