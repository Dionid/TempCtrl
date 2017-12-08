/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 *
 * This example demonstrates how to use mJS DHT library API
 * to get data from DHTxx temperature and humidity sensors.
 */

// Load Mongoose OS API
load('api_config.js');
load('api_rpc.js');
load('api_gpio.js');
load('api_timer.js');
load('api_dht.js');
load('api_mqtt.js');
load('api_sys.js');

load('tz_global_state.js');
load('tz_actions.js');

load('tz_module_heater.js');
load('tz_module_dht_sensor.js');
load('oled.js');
load('buttons.js');

let mainHeaterObj = null;

Timer.set(100, false, function() {
  let heaterDeviceId = Cfg.get('devices.mainHeater.id');
  mainHeaterObj = INIT_HEATER_MODULE({
    deviceId: heaterDeviceId,
    HEAT_PIN: Cfg.get('devices.mainHeater.HEAT_PIN'),
    POWER_PIN: Cfg.get('devices.mainHeater.POWER_PIN'),
    turnedOff: Cfg.get('devices.mainHeater.turnedOff'),
    heatActive: false,
  });

  StateChangedRpcAddHandler(heaterDeviceId, function(args) {
    let changedProps = args.changedProps;
    if (changedProps.turnedOff) {
      Cfg.set({devices: {mainHeater: {turnedOff: changedProps.turnedOff}}}, true);
    }
  });

  globalState.mainHeaterState = mainHeaterObj.state;
}, null);

let mainDHTObj = null;

Timer.set(100, false, function() {
  let mainDHTId = Cfg.get('devices.mainDHT.id');
  mainDHTObj = INIT_DHT_MODULE({
    deviceId: mainDHTId,
    DHT_PIN: Cfg.get('devices.mainDHT.DHT_PIN'),
    minTemp: Cfg.get('devices.mainDHT.minTemp'),
    maxTemp: Cfg.get('devices.mainDHT.maxTemp'),
    minTempActions: [],
    maxTempActions: [],
    // minTempActions: JSON.parse(Cfg.get('devices.mainDHT.minTempActions')),
    // maxTempActions: JSON.parse(Cfg.get('devices.mainDHT.maxTempActions')),
    mainTimerInterval: Cfg.get('devices.mainDHT.mainTimerInterval')
  });

  globalState.mainDHTState = mainDHTObj.state;

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
    // if (changedProps.minTempActions) {
    //   Cfg.set({devices: {mainDHT: {minTempActions: JSON.stringify(changedProps.minTempActions)}}}, true);
    // }
    // if (changedProps.maxTempActions) {
    //   Cfg.set({devices: {mainDHT: {maxTempActions: JSON.stringify(changedProps.maxTempActions)}}}, true);
    // }
  });
}, null);


Timer.set(300 /* milliseconds */, false /* repeat */, function() {
  let oledObj = INIT_OLED(mainDHTObj.state, mainHeaterObj.state);

  let buttonsObj = INIT_BUTTONS({
    oledState: oledObj.state,
    DEC_BUTTON_PIN: Cfg.get('pins.DEC_BUTTON'),
    INC_BUTTON_PIN: Cfg.get('pins.INC_BUTTON'),
    SWITCH_BUTTON_PIN: Cfg.get('pins.SWITCH_BUTTON'),
  });
}, null);
