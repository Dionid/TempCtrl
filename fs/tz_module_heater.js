
load('api_config.js');
load('api_gpio.js');
load('api_rpc.js');

load('tz_actions.js');

function SetHeaterModuleTurnedOn(obj, turnedOn, report) {
  GPIO.write(obj.pins.POWER_PIN, turnedOn);
  obj.state.turnedOn = turnedOn;
  StateChangedRpcCall(obj.deviceId, obj.state, {turnedOn:turnedOn}, report);
}

function SetHeaterModuleHeatActive(obj, heatActive, report) {
  GPIO.write(obj.pins.HEAT_PIN, heatActive);
  obj.state.heatActive = heatActive;
  StateChangedRpcCall(obj.deviceId, obj.state, {heatActive:heatActive}, report);
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

  let heaterObj = {
    deviceId: deviceId,
    pins: {
      HEAT_PIN: HEAT_PIN,
      POWER_PIN: POWER_PIN,
    },
    state: heaterState,
  };

  // report = false, because this initial state will we translated
  SetHeaterModuleTurnedOn(heaterObj, options.turnedOn, false);
  SetHeaterModuleHeatActive(heaterObj, options.heatActive, false);

  TZLog.infoDev(deviceId, 'Ended INIT_HEATER_MODULE');

  return heaterObj;
}
