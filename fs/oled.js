load('api_arduino_liquidcrystal_i2c.js');

// LCD
let lcd = LiquidCrystalI2C.create(0x3F,20,4);
lcd.init();
lcd.backlight();

function RenderHeaterTurnedOff(hide) {
  if (hide) {
    lcd.setCursor(13,0);
    lcd.print("   ");
  } else {
    lcd.setCursor(13,0);
    lcd.print(state.heaterTurnedOff ? "Off" : "On ");
  }
}

function RenderTemp() {
  lcd.setCursor(0,0);
  lcd.print(JSON.stringify(dhtObj.state.temp) + "C");
}

function RenderHum() {
  lcd.setCursor(0,1);
  lcd.print(JSON.stringify(dhtObj.state.hum) + "B");
}

function RenderMaxTemp(hide) {
  if (hide) {
    lcd.setCursor(4,0);
    lcd.print("       ");
  } else {
    lcd.setCursor(4,0);
    lcd.print(JSON.stringify(dhtObj.state.maxTemp) + "C max");
  }
}

function RenderMinTemp(hide) {
  if (hide) {
    lcd.setCursor(4,1);
    lcd.print("       ");
  } else {
    lcd.setCursor(4,1);
    lcd.print(JSON.stringify(dhtObj.state.minTemp) + "C min");
  }
}

RPC.addHandler(mainDHTId + '.StateChanged', function(args) {
  let changedProps = args.changedProps;
  if (changedProps.hum) {
    RenderHum();
  }
  if (changedProps.temp) {
    RenderTemp();
  }
  if (changedProps.maxTemp) {
    RenderMaxTemp(false);
  }
  if (changedProps.minTemp) {
    RenderMinTemp(false);
  }
});

let isBlinking = false;

Timer.set(500 /* milliseconds */, true /* repeat */, function() {
  let selectedConfig = state.selectedConfig;

  if (selectedConfig === deviceConfigs.NONE) {
    RenderMaxTemp(false);
    return;
  } else if (selectedConfig === deviceConfigs.POWER) {
    RenderHeaterTurnedOff(isBlinking);
  } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
    RenderHeaterTurnedOff(false);
    RenderMinTemp(isBlinking);
  } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
    RenderHeaterTurnedOff(false);
    RenderMinTemp(false);
    RenderMaxTemp(isBlinking);
  }
  isBlinking = !isBlinking;
}, null);

// INIT

Timer.set(2000 /* milliseconds */, false /* repeat */, function() {
  RenderHum();
  RenderTemp();
  RenderMaxTemp(false);
  RenderMinTemp(false);
  RenderHeaterTurnedOff(false);
}, null);
