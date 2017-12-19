load('api_config.js');
load('api_timer.js');
load('api_dht.js');

load('tz_actions.js');

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

function CreateDHT(DHT_PIN) {
  return DHT.create(DHT_PIN, DHT.DHT11);
}

function INIT_DHT_MODULE(options) {

  let deviceId = options.deviceId;
  let DHT_PIN = options.DHT_PIN;
  let minTemp = options.minTemp;
  let maxTemp = options.maxTemp;
  let autoCtrl = options.autoCtrl;
  let minTempActions = options.minTempActions;
  let maxTempActions = options.maxTempActions;
  let mainTimerInterval = options.mainTimerInterval;

  print('Started INIT_DHT_MODULE');

  // Initialize DHT library
  let dht = CreateDHT(DHT_PIN);

  let dhtState = {
    temp: 0,
    hum: 0,
    minTemp: minTemp,
    maxTemp: maxTemp,
    autoCtrl: autoCtrl,
    minTempActions: minTempActions,
    maxTempActions: maxTempActions,
    mainTimerInterval: mainTimerInterval,
  };

  let dhtObj = {
    dht: dht,
    deviceId: deviceId,
    state: dhtState,
    pins: {
      DHT_PIN: DHT_PIN,
    }
  };

  RPC.addHandler(deviceId + '.InitDHT', function(args, sm, dhtObj) {
    dhtObj.dht = CreateDHT(dhtObj.pins.DHT_PIN);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.SetState', function(args, sm, dhtObj) {
    if (args.minTemp) {
      SetMinTemp(dhtObj, args.minTemp);
    }
    if (args.maxTemp) {
      SetMaxTemp(dhtObj, args.maxTemp);
    }
    return dhtObj.state;
  }, dhtObj);

  RPC.addHandler(deviceId + '.IncrementMaxTemp', function(args, sm, dhtObj) {
    SetMaxTemp(dhtObj, dhtObj.state.maxTemp + 1);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.IncrementMinTemp', function(args, sm, dhtObj) {
    SetMinTemp(dhtObj, dhtObj.state.minTemp + 1);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.DecrementMaxTemp', function(args, sm, dhtObj) {
    SetMaxTemp(dhtObj, dhtObj.state.maxTemp - 1);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.DecrementMinTemp', function(args, sm, dhtObj) {
    SetMinTemp(dhtObj, dhtObj.state.minTemp - 1);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.GetState', function(args, sm, dhtObj) {
    DHTModuleRefreshHumAndTemp(dhtObj);
    return dhtObj.state;
  }, dhtObj);

  Timer.set(mainTimerInterval /* milliseconds */, true /* repeat */, function(obj) {
    DHTModuleRefreshHumAndTemp(obj);

    let state = obj.state;
    let temp = state.temp;
    let hum = state.hum;

    if (state.autoCtrl) {
      let maxTemp = state.maxTemp;
      let minTemp = state.minTemp;

      if (temp >= maxTemp) {
        TZ_Actions.DoActions(state.maxTempActions, obj.deviceId);
      } else if (temp <= minTemp) {
        TZ_Actions.DoActions(state.minTempActions, obj.deviceId);
      }
    }

    TZ_RPC.main_server_rpc_call(obj.deviceId + '.SaveData', {temp: temp, hum: hum, t: Timer.now()});
    // Dash.send("temperature", temp);
    // Dash.send("humidity", hum);

    // print('Temperature:', temp, '*C');
    // print('Humidity:', hum, '%');
  }, dhtObj);

  Timer.set(1000 /* milliseconds */, false /* repeat */, function(obj) {
    DHTModuleRefreshHumAndTemp(obj);
  }, dhtObj);

  print('Ended INIT_DHT_MODULE');

  return dhtObj;
}
