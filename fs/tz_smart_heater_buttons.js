

function SetNextSelectedConfig(obj) {
  let newState = obj.oledState.selectedConfig + 1;
  if (newState > 3) {
    newState = 0;
  }
  obj.oledState.selectedConfig = newState;
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
    let selectedConfig = obj.oledState.selectedConfig;

    if (selectedConfig === deviceConfigs.NONE) {
      return;
    } else if (selectedConfig === deviceConfigs.POWER) {
      SetHeaterModuleTurnedOn(globalObjs.mainHeaterObj, !globalObjs.mainHeaterObj.state.turnedOn, true);
      return;
    } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
      SetMinTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.minTemp - 1, true);
      return;
    } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
      SetMaxTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.maxTemp - 1, true);
      return;
    }
  }, buttonsObj);

  GPIO.set_button_handler(options.INC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function(pin, obj) {
    let selectedConfig = obj.oledState.selectedConfig;

    if (selectedConfig === deviceConfigs.NONE) {
      return;
    } else if (selectedConfig === deviceConfigs.POWER) {
      SetHeaterModuleTurnedOn(globalObjs.mainHeaterObj, !globalObjs.mainHeaterObj.state.turnedOn, true);
      return;
    } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
      SetMinTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.minTemp + 1, true);
      return;
    } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
      SetMaxTemp(globalObjs.mainDHTObj, globalObjs.mainDHTObj.state.maxTemp + 1, true);
      return;
    }
  }, buttonsObj);

  TZLog.infoDev('buttons', "Ended INIT_BUTTONS");
  return buttonsObj;
}
