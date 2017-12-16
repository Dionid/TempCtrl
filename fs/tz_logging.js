load('api_log.js');

let TZLog = {
  // // ## **`Log.print(level, msg)`**
  // // Print message to stderr if provided
  // // level is >= `Cfg.get('debug.level')`. Possible levels are:
  // // - `Log.ERROR` (0)
  // // - `Log.WARN` (1)
  // // - `Log.INFO` (2)
  // // - `Log.DEBUG` (3)
  // // - `Log.VERBOSE_DEBUG` (4)
  // print: function(level, msg) {
  //   let mjs = getMJS();
  //   // Frame number: we're starting from the third frame, ignoring the first
  //   // two:
  //   // - this._off() or this._fn()
  //   // - Log.print()
  //   let cfn = 2;
  //
  //   // bcode offset of interest, and the corresponding function:lineno
  //   let offs, fn, ln;
  //
  //   // We'll go up by call trace until we find the frame not from the current
  //   // file
  //   while (true) {
  //     offs = this._off(mjs, cfn) - 1;
  //     fn = this._fn(mjs, offs);
  //     if (fn !== "api_log.js") {
  //       // Found the first frame from other file, we're done.
  //       break;
  //     }
  //     cfn++;
  //   }
  //   ln = this._ln(mjs, offs);
  //   this._pr(fn, ln, level, msg);
  // },

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

  deviceLogs: {},

  sendDeviceLogMsg: function(deviceId, msg) {
    RPC.call('', deviceId + '.Log', {msg: msg}, function(res, deviceId) {
      TZLog.infoDev(deviceId, JSON.stringify());
    }, deviceId);
  },

  getDevLog: function(deviceId) {
    return this.deviceLogs[deviceId];
  },

  // ## **`Log.error(msg)`**
  // Shortcut for `Log.print(Log.ERROR, msg)`
  errorDev: function(deviceId, msg) {
    let newMsg = "[error] " + msg;
    if (this.deviceLogs[deviceId] === undefined) {
      this.deviceLogs[deviceId] = [];
    } else {
      if (this.deviceLogs[deviceId].length > 200) {
        // this.sendDeviceLog(deviceId);
        this.deviceLogs[deviceId] = [];
      }
    }
    this.deviceLogs[deviceId].push(newMsg);
    Log.print(Log.ERROR, newMsg);
    this.sendDeviceLog(deviceId, newMsg);
  },

  // ## **`Log.warn(msg)`**
  // Shortcut for `Log.print(Log.WARN, msg)`
  warnDev: function(deviceId, msg) {
    let newMsg = "[warn] " + msg;
    if (this.deviceLogs[deviceId] === undefined) {
      this.deviceLogs[deviceId] = [];
    } else {
      if (this.deviceLogs[deviceId].length > 200) {
        // this.sendDeviceLog(deviceId);
        this.deviceLogs[deviceId] = [];
      }
    }
    this.deviceLogs[deviceId].push(newMsg);
    Log.print(Log.WARN, newMsg);
    this.sendDeviceLog(deviceId, newMsg);
  },

  // ## **`Log.info(msg)`**
  // Shortcut for `Log.print(Log.INFO, msg)`
  infoDev: function(deviceId, msg) {
    let newMsg = "[info] " + msg;
    if (this.deviceLogs[deviceId] === undefined) {
      this.deviceLogs[deviceId] = [];
    } else {
      if (this.deviceLogs[deviceId].length > 200) {
        // this.sendDeviceLog(deviceId);
        this.deviceLogs[deviceId] = [];
      }
    }
    this.deviceLogs[deviceId].push(newMsg);
    Log.print(Log.INFO, newMsg);
    this.sendDeviceLog(deviceId, newMsg);
  },

  // ## **`Log.debug(msg)`**
  // Shortcut for `Log.print(Log.DEBUG, msg)`
  debugDev: function(deviceId, msg) {
    let newMsg = "[debug] " + msg;
    if (this.deviceLogs[deviceId] === undefined) {
      this.deviceLogs[deviceId] = [];
    } else {
      if (this.deviceLogs[deviceId].length > 200) {
        // this.sendDeviceLog(deviceId);
        this.deviceLogs[deviceId] = [];
      }
    }
    this.deviceLogs[deviceId].push(newMsg);
    Log.print(Log.DEBUG, newMsg);
    this.sendDeviceLog(deviceId, newMsg);
  },

  // ## **`Log.verboseDebug(msg)`**
  // Shortcut for `Log.print(Log.VERBOSE_DEBUG, msg)`
  verboseDebugDev: function(deviceId, msg) {
    let newMsg = "[verboseDebug] " + msg;
    if (this.deviceLogs[deviceId] === undefined) {
      this.deviceLogs[deviceId] = [];
    } else {
      if (this.deviceLogs[deviceId].length > 200) {
        // this.sendDeviceLog(deviceId);
        this.deviceLogs[deviceId] = [];
      }
    }
    this.deviceLogs[deviceId].push(newMsg);
    Log.print(Log.VERBOSE_DEBUG, newMsg);
    this.sendDeviceLog(deviceId, newMsg);
  },

  // // ERROR: 0,
  // // WARN: 1,
  // // INFO: 2,
  // // DEBUG: 3,
  // // VERBOSE_DEBUG: 4,
  //
  // _pr: ffi('void mgos_log(char *, int, int, char *)'),
  // _fn: ffi('char *mjs_get_bcode_filename_by_offset(void *, int)'),
  // _ln: ffi('int mjs_get_lineno_by_offset(void *, int)'),
  // _off: ffi('int mjs_get_offset_by_call_frame_num(void *, int)'),
};


RPC.addHandler('TZLogs.GetLogs', function(deviceId) {
  return TZLog.getDevLog(args.deviceId);
}, null);
