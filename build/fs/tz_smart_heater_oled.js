load('api_arduino_liquidcrystal_i2c.js');

// LCD
let lcd = null;

let RenderHeaterTurnedOnHide = false;

function RenderHeaterTurnedOn(turnedOn, hide) {
  if (hide) {
    if (!RenderHeaterTurnedOnHide) {
      lcd.setCursor(13,0);
      lcd.print("   ");
      RenderHeaterTurnedOnHide = true;
    }
  } else {
    lcd.setCursor(13,0);
    lcd.print(turnedOn ? "On " : "Off ");
    RenderHeaterTurnedOnHide = false;
  }
  return true;
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

let RenderMaxTempHide = true;

function RenderMaxTemp(maxTemp, hide) {
  if (hide) {
    // if ()
    if(!RenderMaxTempHide) {
      lcd.setCursor(4,0);
      lcd.print("       ");
      RenderMaxTempHide = true;
    }
  } else {
    lcd.setCursor(4,0);
    lcd.print(JSON.stringify(maxTemp) + "C max");
    RenderMaxTempHide = false;
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
  TZLog.infoDev('oled', "Started INIT_OLED");

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

  Timer.set(1200 /* milliseconds */, true /* repeat */, function(oledObj) {
    if (oledObj.state.selectedConfig === deviceConfigs.NONE) {
      RenderMaxTemp(oledObj.dhtState.maxTemp, false);
      return;
    } else if (oledObj.state.selectedConfig === deviceConfigs.POWER) {
      RenderHeaterTurnedOn(oledObj.heaterState.turnedOn, oledObj.state.isBlinking);
    } else if (oledObj.state.selectedConfig === deviceConfigs.MIN_TEMP) {
      RenderHeaterTurnedOn(oledObj.heaterState.turnedOn, false);
      RenderMinTemp(oledObj.dhtState.minTemp, oledObj.state.isBlinking);
    } else if (oledObj.state.selectedConfig === deviceConfigs.MAX_TEMP) {
      RenderMinTemp(oledObj.dhtState.minTemp, false);
      RenderMaxTemp(oledObj.dhtState.maxTemp, oledObj.state.isBlinking);
    }

    oledObj.state.isBlinking = !oledObj.state.isBlinking;
  }, oledObj);

  Timer.set(2000 /* milliseconds */, false /* repeat */, function(oledObj) {
    let dhtState = oledObj.dhtState;
    let heaterState = oledObj.heaterState;

    RenderHum(dhtState.hum);
    RenderTemp(dhtState.temp);
    RenderMaxTemp(dhtState.maxTemp, false);
    RenderMinTemp(dhtState.minTemp, false);
    RenderHeaterTurnedOn(heaterState.turnedOn, false);
  }, oledObj);

  TZLog.infoDev('oled', "Ended INIT_OLED");

  return oledObj;
}
