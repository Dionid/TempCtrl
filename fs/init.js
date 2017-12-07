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
// load('oled.js');
// load('buttons.js');


let heaterDeviceId = Cfg.get('devices.mainHeater.id');
let mainHeaterObj = INIT_HEATER_MODULE({
  heaterDeviceId: heaterDeviceId,
  HEAT_PIN: Cfg.get('devices.mainHeater.HEAT_PIN'),
  POWER_PIN: Cfg.get('devices.mainHeater.POWER_PIN'),
  heaterTurnedOff: Cfg.get('devices.mainHeater.turnedOff'),
  heaterHeatActive: false,
});

globalState.mainHeaterState = mainHeaterObj.state;

StateChangedRpcAddHandler(heaterDeviceId, function(args) {
  let changedProps = args.changedProps;
  if (changedProps.heaterTurnedOff) {
    Cfg.set({devices: {mainHeater: {turnedOff: turnedOff}}}, true);
  }
});


let mainDHTObj = INIT_DHT_MODULE({
  deviceId: Cfg.get('devices.mainDHT.id'),
  DHT_PIN: Cfg.get('devices.mainDHT.DHT_PIN'),
  minTemp: Cfg.get('devices.mainDHT.minTemp'),
  maxTemp: Cfg.get('devices.mainDHT.maxTemp'),
  minTempActions: Cfg.get('devices.mainDHT.minTempActions'),
  maxTempActions: Cfg.get('devices.mainDHT.maxTempActions'),
  mainTimerInterval: Cfg.get('devices.mainDHT.mainTimerInterval')
});

globalState.mainDHTState = mainDHTObj.state;

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
