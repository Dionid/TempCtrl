// Load Mongoose OS API
load('api_config.js');
load('api_rpc.js');
load('api_gpio.js');
load('api_timer.js');
load('api_dht.js');
load('api_mqtt.js');
load('api_sys.js');
// load('api_dash.js');

load('tz_rpc.js');
load('tz_logging.js');
load('tz_global_state.js');
load('tz_actions.js');
load('tz_shadow.js');

load('tz_module_heater.js');
load('tz_module_dht_sensor.js');
load('tz_smart_heater_oled.js');
load('tz_smart_heater_buttons.js');

Timer.set(100, false, function() {
  let heaterDeviceId = Cfg.get('devices.mainHeater.id');
  globalObjs.mainHeaterObj = INIT_HEATER_MODULE({
    deviceId: heaterDeviceId,
    HEAT_PIN: Cfg.get('devices.mainHeater.HEAT_PIN'),
    POWER_PIN: Cfg.get('devices.mainHeater.POWER_PIN'),
    turnedOn: Cfg.get('devices.mainHeater.turnedOn'),
    heatActive: false,
  });

  StateChangedRpcAddHandler(heaterDeviceId, function(args) {
    let changedProps = args.changedProps;
    if (changedProps.turnedOn !== undefined) {
      Cfg.set({devices: {mainHeater: {turnedOn: changedProps.turnedOn}}}, true);
      RenderHeaterTurnedOn(changedProps.turnedOn, false);
    }
    if (args.report) {
      TZShadow.PublishLocalUpdate({mainHeaterState: changedProps});
    }
    return true;
  });
}, null);

Timer.set(200, false, function() {
  let mainDHTId = Cfg.get('devices.mainDHT.id');
  globalObjs.mainDHTObj = INIT_DHT_MODULE({
    deviceId: mainDHTId,
    DHT_PIN: Cfg.get('devices.mainDHT.DHT_PIN'),
    minTemp: Cfg.get('devices.mainDHT.minTemp'),
    maxTemp: Cfg.get('devices.mainDHT.maxTemp'),
    autoCtrl: Cfg.get('devices.mainDHT.autoCtrl'),
    minTempActions: JSON.parse(Cfg.get('devices.mainDHT.minTempActions')),
    maxTempActions: JSON.parse(Cfg.get('devices.mainDHT.maxTempActions')),
    mainTimerInterval: Cfg.get('devices.mainDHT.mainTimerInterval')
  });

  StateChangedRpcAddHandler(mainDHTId, function(args) {
    let changedProps = args.changedProps;
    if (changedProps.minTemp) {
      Cfg.set({devices: {mainDHT: {minTemp: changedProps.minTemp}}}, true);
      RenderMinTemp(changedProps.minTemp);
    }
    if (changedProps.maxTemp) {
      Cfg.set({devices: {mainDHT: {maxTemp: changedProps.maxTemp}}}, true);
      RenderMaxTemp(changedProps.maxTemp);
    }
    if (changedProps.temp) {
      RenderTemp(changedProps.temp);
    }
    if (changedProps.hum) {
      RenderHum(changedProps.hum);
    }
    if (args.report) {
      TZShadow.PublishLocalUpdate({mainTempAndHumState: changedProps});
    }
    return true;
  });
}, null);

Timer.set(300 , false , function() {
  globalObjs.oledObj = INIT_OLED(globalObjs.mainDHTObj.state, globalObjs.mainHeaterObj.state);
}, null);

Timer.set(400 , false , function() {
  globalObjs.buttonsObj = INIT_BUTTONS({
    oledState: globalObjs.oledObj.state,
    DEC_BUTTON_PIN: Cfg.get('pins.DEC_BUTTON'),
    INC_BUTTON_PIN: Cfg.get('pins.INC_BUTTON'),
    SWITCH_BUTTON_PIN: Cfg.get('pins.SWITCH_BUTTON'),
    mainDHTId: globalObjs.mainDHTObj.deviceId,
    mainHeaterId: globalObjs.mainHeaterObj.deviceId,
  });
}, null);

function TZShadowDeltaCb(args, changedState) {
  if (args.state !== undefined) {
    if (args.state.mainHeaterState !== undefined) {
      let mainHeaterState = {};
      let turnedOn = args.state.mainHeaterState.turnedOn;
      if (turnedOn !== undefined && globalObjs.mainHeaterObj.state.turnedOn !== turnedOn) {
        SetHeaterModuleTurnedOn(globalObjs.mainHeaterObj, turnedOn);
        mainHeaterState.turnedOn = turnedOn;
      }
      let heatActive = args.state.mainHeaterState.heatActive;
      if (heatActive !== undefined && globalObjs.mainHeaterObj.state.heatActive !== heatActive) {
        SetHeaterModuleHeatActive(globalObjs.mainHeaterObj, heatActive);
        mainHeaterState.heatActive = heatActive;
      }
      let empty = true;
      for(let k in mainHeaterState) {
        empty = false;
      }
      if (!empty) {
        changedState.mainHeaterState = mainHeaterState;
      }
    }
    if (args.state.mainTempAndHumState !== undefined) {
      let mainTempAndHumState = {};
      let minTemp = args.state.mainTempAndHumState.minTemp;
      if (minTemp !== undefined && globalObjs.mainDHTObj.state.minTemp !== minTemp) {
        SetMinTemp(globalObjs.mainDHTObj, minTemp);
        mainTempAndHumState.minTemp = minTemp;
      }
      let maxTemp = args.state.mainTempAndHumState.maxTemp;
      if (maxTemp !== undefined && globalObjs.mainDHTObj.state.maxTemp !== maxTemp) {
        SetMaxTemp(globalObjs.mainDHTObj, maxTemp);
        mainTempAndHumState.maxTemp = maxTemp;
      }
      let empty = true;
      for(let k in mainTempAndHumState) {
        empty = false;
      }
      if (!empty) {
        changedState.mainTempAndHumState = mainTempAndHumState;
      }
    }
  }
}

Timer.set(500 , false , function() {
  let deviceId = Cfg.get('devices.mainDevice.id');

  TZShadow.Init({
    deviceId: deviceId,
    serverId: Cfg.get('server.id'),
    state: {
      mainHeaterState: globalObjs.mainHeaterObj.state,
      mainTempAndHumState: globalObjs.mainDHTObj.state,
    },
  });

}, null);

print('Shadow build');
