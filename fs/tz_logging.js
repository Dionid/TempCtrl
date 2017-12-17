load('api_log.js');

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

  devicesLogs: {},

  sendDeviceLogMsg: function(deviceId, type, msg) {
    let sended = TZ_RPC.main_server_rpc_call(deviceId + '.Log', {msg: msg, type: type});
    if (!sended) {
      print('NOT SENDED');
    }
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

  errorDev: function(deviceId, msg) {
    let newMsg = "[error] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.ERROR, newMsg);
    this.sendDeviceLogMsg(deviceId, 'error', newMsg);
  },

  warnDev: function(deviceId, msg) {
    let newMsg = "[warn] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.WARN, newMsg);
    this.sendDeviceLogMsg(deviceId, 'warn', newMsg);
  },

  infoDev: function(deviceId, msg) {
    let newMsg = "[info] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.INFO, newMsg);
    print(JSON.stringify(this.devicesLogs[deviceId]));
    this.sendDeviceLogMsg(deviceId, 'info', newMsg);
  },

  debugDev: function(deviceId, msg) {
    let newMsg = "[debug] " + msg;
    let deviceLogs = this.getDevLog(deviceId);
    this.preWriteDeviceLogsCheck(deviceId, deviceLogs);
    deviceLogs[deviceLogs.length] = newMsg;
    Log.print(Log.DEBUG, newMsg);
    this.sendDeviceLogMsg(deviceId, 'debug', newMsg);
  },

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

print('Log initialized');
