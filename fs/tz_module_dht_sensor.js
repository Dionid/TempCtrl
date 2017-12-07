load('api_config.js');
load('api_timer.js');
load('api_dht.js');
load('actions.js');

function SetDHTModuleTemp(obj, temp) {
  obj.state.temp = temp;
  StateChangedRpcCall(obj.deviceId, obj.state, {temp: t});
}

function SetDHTModuleHum(obj, hum) {
  obj.state.hum = hum;
  StateChangedRpcCall(obj.deviceId, obj.state, {hum: h});
}

function DHTModuleRefreshHumAndTemp(obj) {
  let t = obj.dht.getTemp();
  let h = obj.dht.getHumidity();

  if (isNaN(h) || isNaN(t)) {
    print('Failed to read data from sensor');
    return;
  } else {
    SetDHTModuleTemp(obj, t);
    SetDHTModuleHum(obj, h);
  }
}

function SetMinTemp(obj, minTemp) {
  obj.state.minTemp = minTemp;
  StateChangedRpcCall(obj.deviceId, obj.state, {minTemp:minTemp});
}

function SetMaxTemp(obj, maxTemp) {
  obj.state.maxTemp = maxTemp;
  StateChangedRpcCall(obj.deviceId, obj.state, {maxTemp:maxTemp});
}

function INIT_DHT_MODULE(options) {

  let deviceId = options.deviceId;
  let DHT_PIN = options.DHT_PIN;
  let minTemp = options.minTemp;
  let maxTemp = options.maxTemp;
  let minTempActions = options.minTempActions;
  let maxTempActions = options.maxTempActions;
  let mainTimerInterval = options.mainTimerInterval;

  print('Started INIT_DHT');

  // Initialize DHT library
  let dht = DHT.create(DHT_PIN, DHT.DHT11);

  let dhtState = {
    temp: 0,
    hum: 0,
    minTemp: minTemp,
    maxTemp: maxTemp,
    minTempActions: minTempActions,
    maxTempActions: maxTempActions,
    mainTimerInterval: mainTimerInterval,
  };

  let dhtObj = {
    dht: dht,
    deviceId: deviceId,
    state: dhtState,
  };

  RPC.addHandler(deviceId + '.SetState', function(args, sm, dhtObj) {
    if (args.minTemp) {
      SetMinTemp(dhtObj, args.minTemp);
    }
    if (args.maxTemp) {
      SetMaxTemp(dhtObj, args.maxTemp);
    }
    return GetState();
  }, dhtObj);

  RPC.addHandler(deviceId + '.GetState', function(args, sm, state) {
    return state;
  }, dhtObj.state);

  Timer.set(mainTimerInterval /* milliseconds */, true /* repeat */, function(obj) {
    DHTModuleRefreshHumAndTemp(obj);

    let state = obj.state;

    let temp = state.temp;
    let maxTemp = state.maxTemp;
    let minTemp = state.minTemp;

    if (temp > maxTemp) {
      print('temp > maxTemp');
      for (let i = 0; i < state.maxTempActions.length; i++) {
        DoAction(state.maxTempActions[i]);
      }
    } else if (temp < minTemp) {
      print('temp < minTemp');
      for (let i = 0; i < state.minTempActions.length; i++) {
        DoAction(state.minTempActions[i]);
      }
    }

    print('Temperature:', temp, '*C');
    print('Humidity:', state.hum, '%');
  }, dhtObj);

  return dhtObj;
}
