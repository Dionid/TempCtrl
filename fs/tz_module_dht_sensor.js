// load('api_config.js');
// load('api_timer.js');
// load('api_dht.js');

// load('tz_actions.js');

function SetDHTModuleTemp(obj, temp) {
  obj.state.temp = temp;
  StateChangedRpcCall(obj.deviceId, obj.state, {temp: t});
}

function SetDHTModuleHum(obj, hum) {
  obj.state.hum = hum;
  StateChangedRpcCall(obj.deviceId, obj.state, {hum: h});
}

function DHTModuleRefreshHumAndTemp(obj) {
  obj.state.temp = 0;
  obj.state.hum = 0;
  let t = obj.dht.getTemp();
  let h = obj.dht.getHumidity();

  if (isNaN(h) || isNaN(t)) {
    TZLog.errorDev(obj.deviceId, 'Failed to read data from sensor');
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
  let autoCtrl = options.autoCtrl;
  let minTempActions = options.minTempActions;
  let maxTempActions = options.maxTempActions;
  let mainTimerInterval = options.mainTimerInterval;

  TZLog.infoDev(deviceId, 'Started INIT_DHT_MODULE');

  // Initialize DHT library
  let dht = DHT.create(DHT_PIN, DHT.DHT11);

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

    

    // ShadowReportAndDesire()
    // TZ_RPC.main_server_rpc_call(obj.deviceId + '.SaveData', {temp: temp, hum: hum, t: Timer.now()});
  }, dhtObj);

  Timer.set(3000 /* milliseconds */, false /* repeat */, function(obj) {
    DHTModuleRefreshHumAndTemp(obj);
  }, dhtObj);

  TZLog.infoDev(deviceId, 'Ended INIT_DHT_MODULE');

  return dhtObj;
}
