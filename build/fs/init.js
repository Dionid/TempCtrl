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

function RenderTemp() {
  lcd.setCursor(0,0);
  // lcd.print(JSON.stringify(state.temp) + "C");
}

function RenderHum() {
  lcd.setCursor(0,1);
  // lcd.print(JSON.stringify(state.hum) + "B");
}

function RenderMaxTemp(hide) {
  if (hide) {
    lcd.setCursor(4,0);
    lcd.print("       ");
  } else {
    lcd.setCursor(4,0);
    // lcd.print(JSON.stringify(state.maxTemp) + "C max");
  }
}

function RenderMinTemp(hide) {
  if (hide) {
    lcd.setCursor(4,1);
    lcd.print("       ");
  } else {
    lcd.setCursor(4,1);
    // lcd.print(JSON.stringify(state.minTemp) + "C min");
  }
}

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

// function SetTemp(temp) {
//   state.temp = temp;
//   RenderTemp();
// }
//
// function SetHum(hum) {
//   state.hum = hum;
//   RenderHum();
// }
//
// function RefreshHumAndTemp() {
//   let t = dht.getTemp();
//   let h = dht.getHumidity();
//
//   if (isNaN(h) || isNaN(t)) {
//     print('Failed to read data from sensor');
//     return;
//   } else {
//     SetTemp(t);
//     SetHum(h);
//   }
// }
//
// function SetMinTemp(minTemp) {
//   Cfg.set({app: {minTemp: minTemp}}, true);
//   state.minTemp = minTemp;
//   RenderMinTemp();
// }
//
// function DecrementMinTemp(minTemp) {
//   SetMinTemp(state.minTemp - 1);
// }
//
// function IncrementMinTemp(minTemp) {
//   SetMinTemp(state.minTemp + 1);
// }
//
// function SetMaxTemp(maxTemp) {
//   Cfg.set({app: {maxTemp: maxTemp}}, true);
//   state.maxTemp = maxTemp;
//   RenderMaxTemp();
// }
//
// function DecrementMaxTemp(maxTemp) {
//   SetMaxTemp(state.maxTemp - 1);
// }
//
// function IncrementMaxTemp(maxTemp) {
//   SetMaxTemp(state.maxTemp + 1);
// }

function GetState() {
  // RefreshHumAndTemp();
  return state;
}

// RPC.addHandler(deviceId + '.SetMinTemp', function(args) {
//   SetMinTemp(args.value);
//   return true;
// });
//
// RPC.addHandler(deviceId + '.IncrementMinTemp', function() {
//   IncrementMinTemp();
//   return true;
// });
//
// RPC.addHandler(deviceId + '.DecrementMinTemp', function() {
//   DecrementMinTemp();
//   return true;
// });
//
// RPC.addHandler(deviceId + '.SetMaxTemp', function(args) {
//   SetMaxTemp(args.value);
//   return true;
// });
//
// RPC.addHandler(deviceId + '.IncrementMaxTemp', function() {
//   print('IncrementMaxTemp');
//   IncrementMaxTemp();
//   return true;
// });
//
// RPC.addHandler(deviceId + '.DecrementMaxTemp', function() {
//   print('DecrementMaxTemp');
//   DecrementMaxTemp();
//   return true;
// });

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

GPIO.set_button_handler(DEC_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  print('DEC_BUTTON');

  let selectedConfig = state.selectedConfig;

  if (selectedConfig === deviceConfigs.NONE) {
    return;
  } else if (selectedConfig === deviceConfigs.POWER) {
    SetHeaterTurnedOff(!state.heaterTurnedOff);
    return;
  } else if (selectedConfig === deviceConfigs.MIN_TEMP) {
    if (state.minTemp > 1) {
      DecrementMinTemp();
    }
  } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
    if (state.maxTemp <= (state.minTemp + 1)) {
      return;
    } else {
      DecrementMaxTemp();
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
    if (state.minTemp >= (state.maxTemp - 1)) {
      return;
    } else {
      IncrementMinTemp();
    }
  } else if (selectedConfig === deviceConfigs.MAX_TEMP) {
    if (state.maxTemp < 50) {
      IncrementMaxTemp();
    }
  }
}, null);


GPIO.set_button_handler(SWITCH_BUTTON_PIN, GPIO.PULL_UP, GPIO.INT_EDGE_NEG, 200, function() {
  SetNextSelectedConfig();
}, null);

// Timer.set(1000 /* milliseconds */, false /* repeat */, function() {
//   RefreshHumAndTemp();
//   RenderMaxTemp(false);
//   RenderMinTemp(false);
//   RenderHeaterTurnedOff(false);
// }, null);

INIT_DHT(mainDHTId, deviceId, Cfg.get('pins.DHT'), 10, 20, [
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
], 5000);
