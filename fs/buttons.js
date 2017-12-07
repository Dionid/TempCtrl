// BUTTONS
let DEC_BUTTON_PIN = Cfg.get('pins.DEC_BUTTON');
let INC_BUTTON_PIN = Cfg.get('pins.INC_BUTTON');
let SWITCH_BUTTON_PIN = Cfg.get('pins.SWITCH_BUTTON');

function SetSelectedConfig(configNum) {
  state.selectedConfig = configNum;
}

function SetNextSelectedConfig() {
  let newState = state.selectedConfig + 1;
  if (newState > 3) {
    newState = 0;
  }
  SetSelectedConfig(newState);
  print(state.selectedConfig);
}

GPIO.set_button_handler(SWITCH_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  SetNextSelectedConfig();
}, null);

GPIO.set_button_handler(DEC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  print('DEC_BUTTON');

  let selectedConfig = state.selectedConfig;

  if (selectedConfig === deviceConfigs.NONE) {
    return;
  } else if (selectedConfig === deviceConfigs.POWER) {
    SetHeaterTurnedOff(!state.heaterTurnedOff);
    return;
  } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
    if (dhtObj.state.minTemp > 1) {
      // DecrementMinTemp();
      RPC.call(RPC.LOCAL, mainDHTId + '.DecrementMinTemp', {}, function(){}, null);
    }
  } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
    if (dhtObj.state.maxTemp <= (dhtObj.state.minTemp + 1)) {
      return;
    } else {
      // DecrementMaxTemp();
      RPC.call(RPC.LOCAL, mainDHTId + '.DecrementMaxTemp', {}, function(){}, null);
    }
  }
}, null);

GPIO.set_button_handler(INC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  print('INC_BUTTON');
  let selectedConfig = state.selectedConfig;

  if (selectedConfig === deviceConfigs.NONE) {
    return;
  } else if (selectedConfig === deviceConfigs.POWER) {
    SetHeaterTurnedOff(!state.heaterTurnedOff);
    return;
  } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
    if (dhtObj.state.minTemp >= (dhtObj.state.maxTemp - 1)) {
      return;
    } else {
      // IncrementMinTemp();
      RPC.call(RPC.LOCAL, mainDHTId + '.IncrementMinTemp', {}, function(){}, null);
    }
  } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
    if (dhtObj.state.maxTemp < 50) {
      // IncrementMaxTemp();
      RPC.call(RPC.LOCAL, mainDHTId + '.IncrementMaxTemp', {}, function(){}, null);
    }
  }
}, null);
