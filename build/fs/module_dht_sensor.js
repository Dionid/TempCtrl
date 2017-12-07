load('api_config.js');
load('api_timer.js');
load('api_dht.js');
load('actions.js');

function SetTemp(obj, temp) {
  obj.state.temp = temp;
}

function SetHum(obj, hum) {
  obj.state.hum = hum;
}

function RefreshHumAndTemp(obj) {
  let t = obj.dht.getTemp();
  let h = obj.dht.getHumidity();

  if (isNaN(h) || isNaN(t)) {
    print('Failed to read data from sensor');
    return;
  } else {
    SetTemp(obj, t);
    SetHum(obj, h);
  }
}

function SetMinTemp(obj, minTemp) {
  // Cfg.set({app: {[deviceId]: {state: {minTemp: minTemp}}}}, false);
  obj.state.minTemp = minTemp;
}

function DecrementMinTemp(obj, minTemp) {
  SetMinTemp(obj, obj.state.minTemp - 1);
}

function IncrementMinTemp(obj, minTemp) {
  SetMinTemp(obj, obj.state.minTemp + 1);
}

function SetMaxTemp(obj, maxTemp) {
  // Cfg.set({app: {[deviceId]: {state: {maxTemp: maxTemp}}}}, false);
  obj.state.maxTemp = maxTemp;
}

function DecrementMaxTemp(obj, maxTemp) {
  SetMaxTemp(obj, obj.state.maxTemp - 1);
}

function IncrementMaxTemp(obj, maxTemp) {
  SetMaxTemp(obj, obj.state.maxTemp + 1);
}

function INIT_DHT(deviceId, mainDeviceId, DHT_PIN, minTemp, maxTemp, minTempActions, maxTempActions, mainTimerInterval) {
  print('Started INIT_DHT');

  let modules = JSON.parse(Cfg.get('app.modules'));

  let dhtObj = modules[deviceId];

  // Initialize DHT library
  let dht = DHT.create(DHT_PIN, DHT.DHT11);

  let state = dhtObj ? dhtObj.state : {
    temp: 0,
    hum: 0,
    minTemp: minTemp,
    maxTemp: maxTemp,
    minTempActions: minTempActions,
    maxTempActions: maxTempActions,
    mainTimerInterval: mainTimerInterval,
  };

  dhtObj = {
    dht: dht,
    state: state
  };

  RPC.addHandler(deviceId + '.SetMinTemp', function(args, sm, dhtObj) {
    SetMinTemp(dhtObj, args.value);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.IncrementMinTemp', function(args, sm, dhtObj) {
    IncrementMinTemp(dhtObj);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.DecrementMinTemp', function(args, sm, dhtObj) {
    DecrementMinTemp(dhtObj);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.SetMaxTemp', function(args, sm, dhtObj) {
    SetMaxTemp(dhtObj, args.value);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.IncrementMaxTemp', function(args, sm, dhtObj) {
    print('IncrementMaxTemp');
    IncrementMaxTemp(dhtObj);
    return true;
  }, dhtObj);

  RPC.addHandler(deviceId + '.DecrementMaxTemp', function(args, sm, dhtObj) {
    print('DecrementMaxTemp');
    DecrementMaxTemp(dhtObj);
    return true;
  }, dhtObj);

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
    print(JSON.stringify(sm));
    return state;
  }, dhtObj.state);

  Timer.set(state.mainTimerInterval /* milliseconds */, true /* repeat */, function(obj) {
    RefreshHumAndTemp(obj);
    let state = obj.state;
    let temp = state.temp;
    let maxTemp = state.maxTemp;
    let minTemp = state.minTemp;

    if (temp > maxTemp) {
      print('More');
      for (let i = 0; i < state.maxTempActions.length; i++) {
        DoAction(state.maxTempActions[i]);
      }
    } else if (temp < minTemp) {
      for (let i = 0; i < state.minTempActions.length; i++) {
        DoAction(state.minTempActions[i]);
      }
    }

    print('Temperature:', temp, '*C');
    print('Humidity:', state.hum, '%');
    print(Timer.now());
  }, dhtObj);

  print('Ended INIT_DHT');

  // let forSave = {
  //   app: {},
  // };
  //
  // forSave.app[deviceId] = {state: dhtObj.state};
  //
  // Cfg.set(forSave, false);

  modules[deviceId] = {
    state: state,
  };

  Cfg.set({app: {modules: JSON.stringify(modules)}});

  return dhtObj;
}
