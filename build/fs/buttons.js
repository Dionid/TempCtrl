
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
  TZLog.infoDev('buttons', "Started INIT_BUTTONS");

  let buttonsObj = {
    oledState: options.oledState,
    mainDHTId: options.mainDHTId,
    mainHeaterId: options.mainHeaterId,
  };

  GPIO.set_button_handler(options.SWITCH_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function(pin, buttonsObj) {
    SetNextSelectedConfig(buttonsObj);
  }, buttonsObj);

  GPIO.set_button_handler(options.DEC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function(pin, obj) {
    print('DEC_BUTTON');

    let selectedConfig = obj.oledState.selectedConfig;

    if (selectedConfig === deviceConfigs.NONE) {
      return;
    } else if (selectedConfig === deviceConfigs.POWER) {
      print(Timer.now());
      // RPC.call(RPC.LOCAL, obj.mainHeaterId + '.ToggleTurnedOn', null, null, null);
      SetHeaterModuleTurnedOn(globalObjs.mainHeaterObj, !globalObjs.mainHeaterObj.state.turnedOn);
      return;
    } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
      SetMinTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.minTemp - 1);
      // RPC.call(RPC.LOCAL, obj.mainDHTId + '.DecrementMinTemp', null, null, null);
      return;
    } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
      SetMaxTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.maxTemp - 1);
      // RPC.call(RPC.LOCAL, obj.mainDHTId + '.DecrementMaxTemp', null, null, null);
      return;
    }
  }, buttonsObj);

  GPIO.set_button_handler(options.INC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function(pin, obj) {
    print('INC_BUTTON');

    let selectedConfig = obj.oledState.selectedConfig;

    if (selectedConfig === deviceConfigs.NONE) {
      return;
    } else if (selectedConfig === deviceConfigs.POWER) {
      print(Timer.now());
      //RPC.call(RPC.LOCAL, obj.mainHeaterId + '.ToggleTurnedOn', null, null, null);
      SetHeaterModuleTurnedOn(globalObjs.mainHeaterObj, !globalObjs.mainHeaterObj.state.turnedOn);
      return;
    } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
      SetMinTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.minTemp + 1);
      // RPC.call(RPC.LOCAL, obj.mainDHTId + '.IncrementMinTemp', null, null, null);
      return;
    } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
      SetMaxTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.maxTemp + 1);
      // RPC.call(RPC.LOCAL, obj.mainDHTId + '.IncrementMaxTemp', null, null, null);
      return;
    }
  }, buttonsObj);

  TZLog.infoDev('buttons', "Ended INIT_BUTTONS");
  return buttonsObj;
}
