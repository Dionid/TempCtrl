
load('api_config.js');
load('api_gpio.js');
load('api_rpc.js');

load('tz_actions.js');

function SetHeaterModuleTurnedOff(obj, turnedOff) {
  GPIO.write(obj.pins.POWER_PIN, turnedOff);
  obj.state.turnedOff = turnedOff;
  StateChangedRpcCall(obj.deviceId, obj.state, {turnedOff:turnedOff});
}

function SetHeaterModuleHeatActive(obj, heatActive) {
  GPIO.write(obj.pins.HEAT_PIN, heatActive);
  obj.state.heatActive = heatActive;
  StateChangedRpcCall(obj.deviceId, obj.state, {heatActive:heatActive});
}

function INIT_HEATER_MODULE(options) {

  print('Started INIT_DHT_MODULE');

  let heaterDeviceId = options.deviceId;
  let HEAT_PIN = options.HEAT_PIN;
  let POWER_PIN = options.POWER_PIN;
  let turnedOff = options.turnedOff;
  let heatActive = options.heatActive;

  let heaterState = {
    turnedOff: turnedOff,
    heatActive: heatActive,
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
    if (args.turnedOff !== undefined) {
      SetHeaterModuleTurnedOff(obj, args.turnedOff);
    }
    if (args.heatActive !== undefined) {
      SetHeaterModuleHeatActive(obj, args.heatActive);
    }
    return obj.state;
  }, heaterObj);

  RPC.addHandler(heaterDeviceId + '.GetState', function(args, sm, obj) {
    return obj.state;
  }, heaterObj);

  print('Ended INIT_DHT_MODULE');

  return heaterObj;
}
