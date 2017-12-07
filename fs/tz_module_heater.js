
load('api_config.js');
load('api_gpio.js');
load('api_rpc.js');

load('tz_actions.js');

function SetHeaterModuleTurnedOff(obj, heaterTurnedOff) {
  GPIO.write(obj.pins.POWER_PIN, heaterTurnedOff);
  obj.state.heaterTurnedOff = heaterTurnedOff;
  StateChangedRpcCall(obj.deviceId, obj.state, {heaterTurnedOff:heaterTurnedOff});
}

function SetHeaterModuleHeatActive(obj, heaterHeatActive) {
  GPIO.write(obj.pins.HEAT_PIN, heaterHeatActive);
  obj.state.heaterHeatActive = heaterHeatActive;
  StateChangedRpcCall(obj.deviceId, obj.state, {heaterHeatActive:heaterHeatActive});
}

function INIT_HEATER_MODULE(options) {

  let heaterDeviceId = options.heaterDeviceId;
  let HEAT_PIN = options.HEAT_PIN;
  let POWER_PIN = options.POWER_PIN;
  let heaterTurnedOff = options.heaterTurnedOff;
  let heaterHeatActive = options.heaterHeatActive;

  let heaterState = {
    heaterTurnedOff: heaterTurnedOff,
    heaterHeatActive: heaterHeatActive,
  };

  // HEATER
  GPIO.set_mode(HEAT_PIN, GPIO.MODE_OUTPUT);
  GPIO.set_mode(POWER_PIN, GPIO.MODE_OUTPUT);
  GPIO.write(HEAT_PIN, 0);
  GPIO.write(POWER_PIN, 1);

  let heaterObj = {
    deviceId: heaterDeviceId,
    pins: {
      HEAT_PIN: HEAT_PIN,
      POWER_PIN: POWER_PIN,
    },
    state: heaterState,
  };

  RPC.addHandler(heaterDeviceId + '.SetState', function(args, sm, obj) {
    if (args.heaterTurnedOff !== undefined) {
      SetHeaterModuleTurnedOff(obj, args.heaterTurnedOff);
    }
    if (args.heaterHeatActive) {
      SetHeaterModuleHeatActive(obj, args.heaterHeatActive);
    }
    return obj.state;
  }, heaterObj);

  RPC.addHandler(heaterDeviceId + '.GetState', function(args, sm, obj) {
    return obj.state;
  }, heaterObj);

  return heaterObj;
}
