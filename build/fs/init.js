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
// load('buttons.js');


let heaterDeviceId = Cfg.get('devices.mainHeater.id');
let mainHeaterObj = INIT_HEATER_MODULE({
  deviceId: heaterDeviceId,
  HEAT_PIN: Cfg.get('devices.mainHeater.HEAT_PIN'),
  POWER_PIN: Cfg.get('devices.mainHeater.POWER_PIN'),
  turnedOff: Cfg.get('devices.mainHeater.turnedOff'),
  heaterHeatActive: false,
});

globalState.mainHeaterState = mainHeaterObj.state;

StateChangedRpcAddHandler(heaterDeviceId, function(args) {
  let changedProps = args.changedProps;
  if (changedProps.turnedOff) {
    Cfg.set({devices: {mainHeater: {turnedOff: changedProps.turnedOff}}}, true);
  }
});


let mainDHTId = Cfg.get('devices.mainDHT.id');
let mainDHTObj = INIT_DHT_MODULE({
  deviceId: mainDHTId,
  DHT_PIN: Cfg.get('devices.mainDHT.DHT_PIN'),
  minTemp: Cfg.get('devices.mainDHT.minTemp'),
  maxTemp: Cfg.get('devices.mainDHT.maxTemp'),
  minTempActions: JSON.parse(Cfg.get('devices.mainDHT.minTempActions')),
  maxTempActions: JSON.parse(Cfg.get('devices.mainDHT.maxTempActions')),
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

let oledObj = INIT_OLED(mainDHTObj.state, mainHeaterObj.state);

// // // Device Id
// let deviceId = Cfg.get('app.devId');
// let mainDHTId = '123asdzxc';
//
// print("Hello!");
//
// let deviceConfigs = {
//   NONE: 0,
//   POWER: 1,
//   MIN_TEMP: 2,
//   MAX_TEMP: 3,
// };
//
// let state = {
//   // Ctrlls
//   selectedConfig: deviceConfigs.NONE,
//
//   // Heater
//   heaterTurnedOff: true,
//   heaterHeatActive: false,
// };
//
// // TODO: Find way to store data of this device
//
// let dhtObj = INIT_DHT(
//   mainDHTId,
//   deviceId,
//   Cfg.get('pins.DHT'),
//   10,
//   20,
//   [
//     {
//       method: deviceId + '.SetState',
//       args: {
//         heaterHeatActive: true
//       },
//       local: true,
//       lastCallTime: 0, // Uptime off last call
//       interval: 60,
//       // once: true, # if once is true than after first call this action will be deleted
//     }
//   ], [
//     {
//       method: deviceId + '.SetState',
//       args: {
//         heaterHeatActive: false
//       },
//       local: true,
//       lastCallTime: 0, // Uptime off last call
//       interval: 60,
//     }
//   ],
//   60000
// );
//
// RPC.addHandler(deviceId + '.SetState', function(args) {
//   if (args.heaterTurnedOff !== undefined) {
//     SetHeaterTurnedOff(args.heaterTurnedOff);
//   }
//   if (args.heaterHeatActive) {
//     SetHeaterHeatActive(args.heaterHeatActive);
//   }
//   return GetState();
// });
//
// RPC.addHandler(deviceId + '.GetState', function() {
//   return GetState();
// });
//
// function GetState() {
//   return state;
// }
