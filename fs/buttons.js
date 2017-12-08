
// load('api_gpio.js');

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
  // let DEC_BUTTON_PIN = options.DEC_BUTTON_PIN;
  // let INC_BUTTON_PIN = options.INC_BUTTON_PIN;
  // let SWITCH_BUTTON_PIN = options.SWITCH_BUTTON_PIN;

  // let buttonsState = {
  //
  // };
  let buttonsObj = {
    // state: buttonsState,
    oledState: options.oledState,
    mainDHTId: options.mainDHTId,
  };

  GPIO.set_button_handler(options.SWITCH_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function(pin, buttonsObj) {
    // print(JSON.stringify(buttonsObj));
    SetNextSelectedConfig(buttonsObj);
  }, buttonsObj);

  GPIO.set_button_handler(options.DEC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function(pin, obj) {
    print('DEC_BUTTON');

    let selectedConfig = obj.oledState.selectedConfig;

    if (selectedConfig === deviceConfigs.NONE) {
      return;
    } else if (selectedConfig === deviceConfigs.POWER) {
      // SetHeaterTurnedOff(!state.heaterTurnedOff);
      return;
    } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
      RPC.call(RPC.LOCAL, obj.mainDHTId + '.GetState', {}, function(state, a, b, obj){
        RPC.call(RPC.LOCAL, obj.mainDHTId + '.SetState', {
          minTemp: state.minTemp - 1,
        }, function(){}, null);
      }, obj);
    } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
      RPC.call(RPC.LOCAL, obj.mainDHTId + '.GetState', {}, function(state, a, b, obj){
        RPC.call(RPC.LOCAL, obj.mainDHTId + '.SetState', {
          maxTemp: state.maxTemp - 1,
        }, function(){}, null);
      }, obj);
    }
  }, buttonsObj);
  
  // GPIO.set_button_handler(options.INC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
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
