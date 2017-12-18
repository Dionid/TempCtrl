load('api_rpc.js');

function DoAction(rpc) {
  let dst = rpc.local ? RPC.LOCAL : '';
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
    RPC.call(dst, rpc.method, rpc.args, function(res, ud) {
      print('Call DONE FROM NEW FILE');
    }, null);
  }
}

let TZ_Actions = {
  DoAction: function(rpc, deviceId) {
    let dst = rpc.local ? RPC.LOCAL : '';
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
      RPC.call(dst, rpc.method, rpc.args, function(res, err_code, err_msg, ud) {
        if (err_code) {
          TZLog.errorDev(ud.deviceId, 'Error: ' + err_msg);
        } else {
          TZLog.infoDev(ud.deviceId, ud.method + ' call done');
        }
      }, {method: rpc.method, deviceId: deviceId});
    }
  },
  DoActions: function(actions, deviceId) {
    for (let i = 0; i < actions.length; i++) {
      this.DoAction(actions[i], deviceId);
    }
  },
};

function StateChangedRpcCall(deviceId, state, changedProps) {
  RPC.call(RPC.LOCAL, deviceId + '.StateChanged', {state: state, changedProps: changedProps}, function(){}, null);
}

function StateChangedRpcAddHandler(deviceId, cb, ud) {
  if (ud === undefined) {
    ud = null;
  }
  RPC.addHandler(deviceId + '.StateChanged', cb, ud);
}
