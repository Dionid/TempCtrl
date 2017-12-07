load('api_dht.js');
load('actions.js');

function INIT_DHT(deviceId, mainDeviceId, DHT_PIN, minTemp, maxTemp, minTempActions, maxTempActions, mainTimerInterval) {

  let dhtObj = Cfg.get('app.' + deviceId);

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

  function SetTemp(temp) {
    state.temp = temp;
  }

  function SetHum(hum) {
    state.hum = hum;
  }

  function RefreshHumAndTemp() {
    let t = dht.getTemp();
    let h = dht.getHumidity();

    if (isNaN(h) || isNaN(t)) {
      print('Failed to read data from sensor');
      return;
    } else {
      SetTemp(t);
      SetHum(h);
    }
  }

  function SetMinTemp(minTemp) {
    Cfg.set({app: {[deviceId]: {state: {minTemp: minTemp}}}}, true);
    state.minTemp = minTemp;
  }

  function DecrementMinTemp(minTemp) {
    SetMinTemp(state.minTemp - 1);
  }

  function IncrementMinTemp(minTemp) {
    SetMinTemp(state.minTemp + 1);
  }

  function SetMaxTemp(maxTemp) {
    Cfg.set({app: {[deviceId]: {state: {maxTemp: maxTemp}}}}, true);
    state.maxTemp = maxTemp;
  }

  function DecrementMaxTemp(maxTemp) {
    SetMaxTemp(state.maxTemp - 1);
  }

  function IncrementMaxTemp(maxTemp) {
    SetMaxTemp(state.maxTemp + 1);
  }

  dhtObj = {
    state: state,
    SetMinTemp: SetMinTemp,
    DecrementMinTemp: DecrementMinTemp,
    IncrementMinTemp: IncrementMinTemp,
    SetMaxTemp: SetMaxTemp,
    DecrementMaxTemp: DecrementMaxTemp,
    IncrementMaxTemp: IncrementMaxTemp,
  };

  // Cfd.set({app: {[deviceId]: {state: state}}}, true);

  RPC.addHandler(deviceId + '.SetMinTemp', function(args) {
    SetMinTemp(args.value);
    return true;
  });

  RPC.addHandler(deviceId + '.IncrementMinTemp', function() {
    IncrementMinTemp();
    return true;
  });

  RPC.addHandler(deviceId + '.DecrementMinTemp', function() {
    DecrementMinTemp();
    return true;
  });

  RPC.addHandler(deviceId + '.SetMaxTemp', function(args) {
    SetMaxTemp(args.value);
    return true;
  });

  RPC.addHandler(deviceId + '.IncrementMaxTemp', function() {
    print('IncrementMaxTemp');
    IncrementMaxTemp();
    return true;
  });

  RPC.addHandler(deviceId + '.DecrementMaxTemp', function() {
    print('DecrementMaxTemp');
    DecrementMaxTemp();
    return true;
  });

  RPC.addHandler(deviceId + '.SetState', function(args) {
    if (args.minTemp) {
      SetMinTemp(args.minTemp);
    }
    if (args.maxTemp) {
      SetMaxTemp(args.maxTemp);
    }
    return GetState();
  });

  RPC.addHandler(deviceId + '.GetState', function() {
    return state;
  });

  Timer.set(state.mainTimerInterval /* milliseconds */, true /* repeat */, function() {
    RefreshHumAndTemp();
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
  }, null);

  return dhtObj;
}
