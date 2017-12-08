
load('api_gpio.js');

function SetSelectedConfig(obj, configNum) {
  obj.oledState.selectedConfig = configNum;
}

function SetNextSelectedConfig(obj) {
  let newState = obj.oledState.selectedConfig + 1;
  if (newState > 3) {
    newState = 0;
  }
  SetSelectedConfig(obj, newState);
  print(obj.oledState.selectedConfig);
}


function INIT_BUTTONS(options) {
  print("Started INIT_BUTTONS");

  // BUTTONS
  let DEC_BUTTON_PIN = options.DEC_BUTTON_PIN;
  let INC_BUTTON_PIN = options.INC_BUTTON_PIN;
  let SWITCH_BUTTON_PIN = options.SWITCH_BUTTON_PIN;
  GPIO.set_mode(DEC_BUTTON_PIN, GPIO.MODE_INPUT);
  GPIO.set_mode(INC_BUTTON_PIN, GPIO.MODE_INPUT);
  GPIO.set_mode(SWITCH_BUTTON_PIN, GPIO.MODE_INPUT);

  // let buttonsState = {
  //
  // };
  let buttonsObj = {
    // state: buttonsState,
    oledState: options.oledState,
  };

  GPIO.set_button_handler(SWITCH_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function(buttonsObj) {
    SetNextSelectedConfig(buttonsObj);
  }, buttonsObj);

  // GPIO.set_button_handler(DEC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  //   print('DEC_BUTTON');
  //
  //   let selectedConfig = state.selectedConfig;
  //
  //   if (selectedConfig === deviceConfigs.NONE) {
  //     return;
  //   } else if (selectedConfig === deviceConfigs.POWER) {
  //     SetHeaterTurnedOff(!state.heaterTurnedOff);
  //     return;
  //   } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
  //     if (dhtObj.state.minTemp > 1) {
  //       // DecrementMinTemp();
  //       RPC.call(RPC.LOCAL, mainDHTId + '.DecrementMinTemp', {}, function(){}, null);
  //     }
  //   } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
  //     if (dhtObj.state.maxTemp <= (dhtObj.state.minTemp + 1)) {
  //       return;
  //     } else {
  //       // DecrementMaxTemp();
  //       RPC.call(RPC.LOCAL, mainDHTId + '.DecrementMaxTemp', {}, function(){}, null);
  //     }
  //   }
  // }, null);
  //
  // GPIO.set_button_handler(INC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  //   print('INC_BUTTON');
  //   let selectedConfig = state.selectedConfig;
  //
  //   if (selectedConfig === deviceConfigs.NONE) {
  //     return;
  //   } else if (selectedConfig === deviceConfigs.POWER) {
  //     SetHeaterTurnedOff(!state.heaterTurnedOff);
  //     return;
  //   } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
  //     if (dhtObj.state.minTemp >= (dhtObj.state.maxTemp - 1)) {
  //       return;
  //     } else {
  //       // IncrementMinTemp();
  //       RPC.call(RPC.LOCAL, mainDHTId + '.IncrementMinTemp', {}, function(){}, null);
  //     }
  //   } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
  //     if (dhtObj.state.maxTemp < 50) {
  //       // IncrementMaxTemp();
  //       RPC.call(RPC.LOCAL, mainDHTId + '.IncrementMaxTemp', {}, function(){}, null);
  //     }
  //   }
  // }, null);

  print("Ended INIT_BUTTONS");
  return buttonsObj;
}
