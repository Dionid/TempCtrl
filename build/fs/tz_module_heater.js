
load('api_config.js');
load('api_gpio.js');
load('api_rpc.js');

load('tz_actions.js');

function SetHeaterModuleTurnedOn(obj, turnedOn) {
  GPIO.write(obj.pins.POWER_PIN, turnedOn);
  obj.state.turnedOn = turnedOn;
  StateChangedRpcCall(obj.deviceId, obj.state, {turnedOn:turnedOn});
}

function SetHeaterModuleHeatActive(obj, heatActive) {
  GPIO.write(obj.pins.HEAT_PIN, heatActive);
  obj.state.heatActive = heatActive;
  StateChangedRpcCall(obj.deviceId, obj.state, {heatActive:heatActive});
}

function INIT_HEATER_MODULE(options) {
  let deviceId = options.deviceId;

  TZLog.infoDev(deviceId, 'Started INIT_HEATER_MODULE');

  let HEAT_PIN = options.HEAT_PIN;
  let POWER_PIN = options.POWER_PIN;
  let turnedOn = options.turnedOn;
  let heatActive = options.heatActive;

  let heaterState = {
    turnedOn: turnedOn,
    heatActive: heatActive,
  };

  // HEATER
  GPIO.set_mode(HEAT_PIN, GPIO.MODE_OUTPUT);
  GPIO.set_mode(POWER_PIN, GPIO.MODE_OUTPUT);
  // GPIO.write(HEAT_PIN, 1);
  // GPIO.write(POWER_PIN, 0);

  let heaterObj = {
    deviceId: deviceId,
    pins: {
      HEAT_PIN: HEAT_PIN,
      POWER_PIN: POWER_PIN,
    },
    state: heaterState,
  };

  SetHeaterModuleTurnedOn(heaterObj, options.turnedOn);
  SetHeaterModuleHeatActive(heaterObj, options.heatActive);

  RPC.addHandler(deviceId + '.ToggleTurnedOn', function(args, sm, obj) {
    SetHeaterModuleTurnedOn(obj, !obj.state.turnedOn);
    return true;
  }, heaterObj);

  RPC.addHandler(deviceId + '.SetState', function(args, sm, obj) {
    if (args.turnedOn !== undefined) {
      SetHeaterModuleTurnedOn(obj, args.turnedOn);
    }
    if (args.heatActive !== undefined) {
      SetHeaterModuleHeatActive(obj, args.heatActive);
    }
    return obj.state;
  }, heaterObj);

  RPC.addHandler(deviceId + '.GetState', function(args, sm, obj) {
    return obj.state;
  }, heaterObj);

  TZLog.infoDev(deviceId, 'Ended INIT_HEATER_MODULE');

  return heaterObj;
}
