load('api_rpc.js');

let TZ_Actions = {
  DoAction: function(rpc, deviceId) {
    let now = Timer.now();
    let doCall = true;
    if (rpc.interval) {
      if (rpc.lastCallTime) {
        if ((rpc.lastCallTime + rpc.interval) > now) {
          doCall = false;
        }
      }
    }
    if (doCall) {
      rpc.lastCallTime = now;
      if (rpc.local) {
        RPC.call(RPC.LOCAL, rpc.method, rpc.args, function(res, err_code, err_msg, ud) {
          if (err_code) {
            TZLog.errorDev(ud.deviceId, 'Error: ' + err_msg);
          } else {
            TZLog.infoDev(ud.deviceId, ud.method + ' call done');
          }
        }, {method: rpc.method, deviceId: deviceId});
      } else {
        TZ_RPC.main_server_rpc_call(rpc.method, rpc.args);
      }
    }
  },
  DoActions: function(actions, deviceId) {
    for (let i = 0; i < actions.length; i++) {
      this.DoAction(actions[i], deviceId);
    }
  },
};

// REPLACE RPC.CALL TO NORMAL CALL

function StateChangedRpcCall(deviceId, state, changedProps) {
  RPC.call(RPC.LOCAL, deviceId + '.StateChanged', {state: state, changedProps: changedProps}, function(){}, null);
}

function StateChangedRpcAddHandler(deviceId, cb, ud) {
  if (ud === undefined) {
    ud = null;
  }
  RPC.addHandler(deviceId + '.StateChanged', cb, ud);
}
