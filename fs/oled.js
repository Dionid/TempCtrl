load('api_arduino_liquidcrystal_i2c.js');

// LCD
let lcd = null;

function RenderHeaterTurnedOff(turnedOff, hide) {
  if (hide) {
    lcd.setCursor(13,0);
    lcd.print("   ");
  } else {
    lcd.setCursor(13,0);
    lcd.print(turnedOff ? "Off" : "On ");
  }
}
//
function RenderTemp(temp) {
  lcd.setCursor(0,0);
  lcd.print(JSON.stringify(temp) + "C");
}

function RenderHum(hum) {
  lcd.setCursor(0,1);
  lcd.print(JSON.stringify(hum) + "B");
}
//
function RenderMaxTemp(maxTemp, hide) {
  if (hide) {
    lcd.setCursor(4,0);
    lcd.print("       ");
  } else {
    lcd.setCursor(4,0);
    lcd.print(JSON.stringify(maxTemp) + "C max");
  }
}
//
function RenderMinTemp(minTemp, hide) {
  if (hide) {
    lcd.setCursor(4,1);
    lcd.print("       ");
  } else {
    lcd.setCursor(4,1);
    lcd.print(JSON.stringify(minTemp) + "C min");
  }
}

// INIT

let deviceConfigs = {
  NONE: 0,
  POWER: 1,
  MIN_TEMP: 2,
  MAX_TEMP: 3,
};

function INIT_OLED(dhtState, heaterState) {
  print("Started INIT_OLED");

  lcd = LiquidCrystalI2C.create(0x3F,20,4);
  lcd.init();
  lcd.backlight();

  let oledState = {
    isBlinking: false,
    selectedConfig: deviceConfigs.NONE,
  };
  //
  let oledObj = {
    lcd: lcd,
    state: oledState,
    dhtState: dhtState,
    heaterState: heaterState,
  };

  // Timer.set(500 /* milliseconds */, true /* repeat */, function(oledObj) {
  //   let state = oledObj.state;
  //   let selectedConfig = state.selectedConfig;
  //   let isBlinking = state.isBlinking;
  //   let dhtState = oledObj.dhtState;
  //   let heaterState = oledObj.heaterState;
  //   let maxTemp = dhtState.maxTemp;
  //   let minTemp = dhtState.minTemp;
  //   let turnedOff = heaterState.turnedOff;
  //
  //   if (selectedConfig === deviceConfigs.NONE) {
  //     RenderMaxTemp(maxTemp, false);
  //     return;
  //   } else if (selectedConfig === deviceConfigs.POWER) {
  //     RenderHeaterTurnedOff(turnedOff, isBlinking);
  //   } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
  //     RenderHeaterTurnedOff(turnedOff, false);
  //     RenderMinTemp(minTemp, isBlinking);
  //   } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
  //     RenderHeaterTurnedOff(turnedOff, false);
  //     RenderMinTemp(minTemp, false);
  //     RenderMaxTemp(maxTemp, isBlinking);
  //   }
  //
  //   state.isBlinking = !isBlinking;
  // }, oledObj);

  Timer.set(2000 /* milliseconds */, false /* repeat */, function(oledObj) {
    let dhtState = oledObj.dhtState;
    let heaterState = oledObj.heaterState;

    RenderHum(dhtState.hum);
    RenderTemp(dhtState.temp);
    RenderMaxTemp(dhtState.maxTemp, false);
    RenderMinTemp(dhtState.minTemp, false);
    RenderHeaterTurnedOff(heaterState.turnedOff, false);
  }, oledObj);

  print("Ended INIT_OLED");

  return oledObj;
}