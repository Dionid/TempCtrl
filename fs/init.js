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
      // TZ_RPC.main_server_rpc_call(globalObjs.mainHeaterObj.deviceId + '.SetState', {temp: temp, hum: hum, t: Timer.now()});
      RenderHeaterTurnedOn(changedProps.turnedOn, false);
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

function TZShadowDeltaCb(args, state) {
  if (args.state.mainHeaterState !== undefined) {
    // state.mainHeaterState = {};
    if (args.state.mainHeaterState.turnedOn !== undefined) {
      SetHeaterModuleTurnedOn(globalObjs.mainHeaterObj, args.state.mainHeaterState.turnedOn);
      // state.mainHeaterState.turnedOn = args.state.mainHeaterState.turnedOn;
    }
    if (args.state.mainHeaterState.heatActive !== undefined) {
      SetHeaterModuleHeatActive(globalObjs.mainHeaterObj, args.state.mainHeaterState.heatActive);
      // state.mainHeaterState.turnedOn = args.state.mainHeaterState.heatActive;
    }
  }
  if (args.state.mainTempAndHumidityState !== undefined) {
    // state.mainTempAndHumidityState = {};
    if (args.state.mainTempAndHumidityState.minTemp !== undefined) {
      SetMinTemp(globalObjs.mainDHTObj, args.state.mainTempAndHumidityState.minTemp);
      // state.mainTempAndHumidityState.minTemp = args.state.mainTempAndHumidityState.minTemp;
    }
    if (args.state.mainTempAndHumidityState.maxTemp !== undefined) {
      SetMaxTemp(globalObjs.mainDHTObj, args.state.mainTempAndHumidityState.maxTemp);
      // state.mainTempAndHumidityState.maxTemp = args.state.mainTempAndHumidityState.maxTemp;
    }
  }
}

Timer.set(500 , false , function() {
  let deviceId = Cfg.get('devices.mainDevice.id');

  // GlobalShadowState = {
  //   mainHeaterState: globalObjs.mainHeaterObj.state,
  //   mainDHTState: globalObjs.mainDHTObj.state,
  // };

  TZShadow.State = {
    mainHeaterState: globalObjs.mainHeaterObj.state,
    mainDHTState: globalObjs.mainDHTObj.state,
  };

  // let shadow = INIT_SHADOW({
  //   deviceId: deviceId,
  //   serverId: serverId,
  //   // deviceState: {
  //   //   mainHeaterState: globalObjs.mainHeaterObj.state,
  //   //   mainDHTState: globalObjs.mainDHTObj.state,
  //   // },
  //   deltaCb: function(args, state) {
  //     if (args.state.mainHeaterState !== undefined) {
  //       state.mainHeaterState = {};
  //       if (args.state.mainHeaterState.turnedOn !== undefined) {
  //         SetHeaterModuleTurnedOn(globalObjs.mainHeaterObj, args.state.mainHeaterState.turnedOn);
  //         state.mainHeaterState.turnedOn = args.state.mainHeaterState.turnedOn;
  //       }
  //       if (args.state.mainHeaterState.heatActive !== undefined) {
  //         SetHeaterModuleHeatActive(globalObjs.mainHeaterObj, args.state.mainHeaterState.heatActive);
  //         state.mainHeaterState.turnedOn = args.state.mainHeaterState.heatActive;
  //       }
  //     }
  //     if (args.state.mainTempAndHumidityState !== undefined) {
  //       state.mainTempAndHumidityState = {};
  //       if (args.state.mainTempAndHumidityState.minTemp !== undefined) {
  //         SetMinTemp(globalObjs.mainDHTObj, args.state.mainTempAndHumidityState.minTemp);
  //         state.mainTempAndHumidityState.minTemp = args.state.mainTempAndHumidityState.minTemp;
  //       }
  //       if (args.state.mainTempAndHumidityState.maxTemp !== undefined) {
  //         SetMaxTemp(globalObjs.mainDHTObj, args.state.mainTempAndHumidityState.maxTemp);
  //         state.mainTempAndHumidityState.maxTemp = args.state.mainTempAndHumidityState.maxTemp;
  //       }
  //     }
  //   }
  // });

}, null);

print('New build');
