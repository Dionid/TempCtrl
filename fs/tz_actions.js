load('api_rpc.js');

let TZ_Actions = {
  DoAction: function(action, deviceId) {
    let now = Timer.now();
    let doCall = true;
    if (action.interval) {
      if (action.lastCallTime) {
        if ((action.lastCallTime + action.interval) > now) {
          doCall = false;
        }
      }
    }
    if (doCall) {
      action.lastCallTime = now;
      if (action.type === "rpc") {
        if (action.local) {
          RPC.call(RPC.LOCAL, action.method, action.args, function(res, err_code, err_msg, ud) {
            if (err_code) {
              TZLog.errorDev(ud.deviceId, 'Error: ' + err_msg);
            } else {
              TZLog.infoDev(ud.deviceId, ud.method + ' call done');
            }
          }, {method: action.method, deviceId: deviceId});
        } else {
          // TZ_RPC.main_server_rpc_call(rpc.method, rpc.args);
          // !!!
        }
      } else {

      }
    }
  },
  DoActions: function(actions, deviceId) {
    for (let i = 0; i < actions.length; i++) {
      this.DoAction(actions[i], deviceId);
    }
  },
};

let StateChangedCbs = {};

// REPLACE RPC.CALL TO NORMAL CALL
function StateChangedRpcCall(deviceId, state, changedProps, report) {
  if (StateChangedCbs[deviceId]) StateChangedCbs[deviceId]({state: state, changedProps: changedProps, report: report});
  // RPC.call(RPC.LOCAL, deviceId + '.StateChanged', {state: state, changedProps: changedProps, report: report}, function(){}, null);
}

function StateChangedRpcAddHandler(deviceId, cb) {
  // if (ud === undefined) {
  //   ud = null;
  // }
  // RPC.addHandler(deviceId + '.StateChanged', cb, ud);
  StateChangedCbs[deviceId] = cb;
}
