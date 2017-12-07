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
  // print(rpc.lastCallTime + rpc.interval);
  // print(now);
  // print((rpc.lastCallTime + rpc.interval) > now);
  if (doCall) {
    rpc.lastCallTime = now;
    RPC.call(dst, rpc.method, rpc.args, function(res, ud) {
      print('Call DONE FROM NEW FILE');
    }, null);
  }
}


// TODO: Change 'args' to 'state, changedProps' and send both of them

function StateChangedRpcCall(deviceId, state, changedProps) {
  RPC.call(RPC.LOCAL, deviceId + '.StateChanged', {state: state, changedProps: changedProps}, function(){}, null);
}
