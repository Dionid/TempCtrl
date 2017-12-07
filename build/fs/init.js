/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 *
 * This example demonstrates how to use mJS DHT library API
 * to get data from DHTxx temperature and humidity sensors.
 */

// Load Mongoose OS API
load('api_config.js');
load('api_rpc.js');
load('api_gpio.js');
load('api_timer.js');
load('api_dht.js');
load('api_mqtt.js');
load('api_sys.js');
load('api_arduino_liquidcrystal_i2c.js');
load('actions.js');
load('module_dht_sensor.js');

// // Device Id
let deviceId = Cfg.get('app.devId');
let mainDHTId = '123asdzxc';

print("Hello!");

// LCD
let lcd = LiquidCrystalI2C.create(0x3F,20,4);
lcd.init();
lcd.backlight();

// BUTTONS
let DEC_BUTTON_PIN = Cfg.get('pins.DEC_BUTTON');
let INC_BUTTON_PIN = Cfg.get('pins.INC_BUTTON');
let SWITCH_BUTTON_PIN = Cfg.get('pins.SWITCH_BUTTON');

// HEATER
let HEAT_PIN = Cfg.get('pins.HEAT_S');
let POWER_PIN = Cfg.get('pins.POWER');
GPIO.set_mode(HEAT_PIN, GPIO.MODE_OUTPUT);
GPIO.set_mode(POWER_PIN, GPIO.MODE_OUTPUT);
GPIO.write(HEAT_PIN, 0);
GPIO.write(POWER_PIN, 1);

let deviceConfigs = {
  NONE: 0,
  POWER: 1,
  MIN_TEMP: 2,
  MAX_TEMP: 3,
};

let state = {
  // LCD

  // Ctrlls
  selectedConfig: deviceConfigs.NONE,

  // Heater
  heaterTurnedOff: true,
  heaterHeatActive: false,
};

function RenderHeaterTurnedOff(hide) {
  if (hide) {
    lcd.setCursor(13,0);
    lcd.print("   ");
  } else {
    lcd.setCursor(13,0);
    lcd.print(state.heaterTurnedOff ? "Off" : "On ");
  }
}

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

function SetHeaterTurnedOff(heaterTurnedOff) {
  GPIO.write(POWER_PIN, heaterTurnedOff);
  state.heaterTurnedOff = heaterTurnedOff;
  RenderHeaterTurnedOff(false);
}

function SetHeaterHeatActive(heaterHeatActive) {
  GPIO.write(HEAT_PIN, heaterHeatActive);
  state.heaterHeatActive = heaterHeatActive;
}

function GetState() {
  return state;
}

RPC.addHandler(deviceId + '.SetState', function(args) {
  if (args.heaterTurnedOff !== undefined) {
    SetHeaterTurnedOff(args.heaterTurnedOff);
  }
  if (args.heaterHeatActive) {
    SetHeaterHeatActive(args.heaterHeatActive);
  }
  return GetState();
});

RPC.addHandler(deviceId + '.GetState', function() {
  return GetState();
});

let isBlinking = false;


GPIO.set_button_handler(SWITCH_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  SetNextSelectedConfig();
}, null);

let dhtObj = INIT_DHT(mainDHTId, deviceId, Cfg.get('pins.DHT'), 10, 20, [
  {
    method: deviceId + '.SetState',
    args: {
      heaterHeatActive: true
    },
    local: true,
    lastCallTime: 0, // Uptime off last call
    interval: 60,
    // once: true, # if once is true than after first call this action will be deleted
  }
], [
  {
    method: deviceId + '.SetState',
    args: {
      heaterHeatActive: false
    },
    local: true,
    lastCallTime: 0, // Uptime off last call
    interval: 60,
  }
], 60000);

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

RPC.addHandler(mainDHTId + '.StateChanged', function(state) {
  RenderHum();
  RenderTemp();
  RenderMaxTemp(false);
  RenderMinTemp(false);
  RenderHeaterTurnedOff(false);
});

Timer.set(2000 /* milliseconds */, false /* repeat */, function() {
  RenderHum();
  RenderTemp();
  RenderMaxTemp(false);
  RenderMinTemp(false);
  RenderHeaterTurnedOff(false);
}, null);

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
