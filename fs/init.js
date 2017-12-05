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

// // Device Id
let deviceId = Cfg.get('app.devId');

print("Hello!");

// LCD
let lcd = LiquidCrystalI2C.create(0x3F,20,4);
lcd.init();
lcd.backlight();
lcd.print("Hello!");

// GPIO

// BUTTONS
let DEC_BUTTON_PIN = Cfg.get('pins.DEC_BUTTON');
let INC_BUTTON_PIN = Cfg.get('pins.INC_BUTTON');
let SWITCH_BUTTON_PIN = Cfg.get('pins.SWITCH_BUTTON');

// DHT
let DHT_PIN = Cfg.get('pins.DHT');

// HEATER
let HEAT_PIN = Cfg.get('pins.HEAT_S');
let POWER_PIN = Cfg.get('pins.POWER');
GPIO.set_mode(HEAT_PIN, GPIO.MODE_OUTPUT);
GPIO.set_mode(POWER_PIN, GPIO.MODE_OUTPUT);
GPIO.write(HEAT_PIN, 0);
GPIO.write(POWER_PIN, 1);


// Initialize DHT library
let dht = DHT.create(DHT_PIN, DHT.DHT11);

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

  temp: 0,
  hum: 0,
  minTemp: 10,
  maxTemp: 20,
  minTempActions: [],
  maxTempActions: [],
};

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
}

function SetHeaterHeatActive(heaterHeatActive) {
  GPIO.write(HEAT_PIN, heaterHeatActive);
  state.heaterHeatActive = heaterHeatActive;
}

function SetTemp(temp) {
  state.temp = temp;
}

function SetHum(hum) {
  state.hum = hum;
}

// function GetHumAndTempData() {
//   let t = dht.getTemp();
//   let h = dht.getHumidity();
//
//   if (isNaN(h) || isNaN(t)) {
//     print('Failed to read data from sensor');
//     return;
//   }
//
//   return [t, h];
// }

function SetMinTemp(minTemp) {
  state.minTemp = minTemp;
}

function DecrementMinTemp(minTemp) {
  SetMinTemp(state.minTemp - 1);
}

function IncrementMinTemp(minTemp) {
  SetMinTemp(state.minTemp + 1);
}

function SetMaxTemp(maxTemp) {
  state.maxTemp = maxTemp;
}

function DecrementMaxTemp(maxTemp) {
  SetMaxTemp(state.maxTemp - 1);
}

function IncrementMaxTemp(maxTemp) {
  SetMaxTemp(state.maxTemp + 1);
}

function GetState() {
  let t = dht.getTemp();
  let h = dht.getHumidity();

  if (isNaN(h) || isNaN(t)) {
    print('Failed to read data from sensor');
    return;
  } else {
    SetTemp(t);
    SetHum(h);
  }

  return state;
}

RPC.addHandler(deviceId + '.SetMinTemp', function(args) {
  SetMinTemp(args.value);
  return true;
});

RPC.addHandler(deviceId + '.IncrementMinTemp', function() {
  IncrementMinTemp();
  return true;
});

RPC.addHandler(deviceId + '.DecrementMinTemp', function() {
  DecrementMinTemp();
  return true;
});

RPC.addHandler(deviceId + '.SetMaxTemp', function(args) {
  SetMaxTemp(args.value);
  return true;
});

RPC.addHandler(deviceId + '.IncrementMaxTemp', function() {
  print('IncrementMaxTemp');
  IncrementMaxTemp();
  return true;
});

RPC.addHandler(deviceId + '.DecrementMaxTemp', function() {
  print('DecrementMaxTemp');
  DecrementMaxTemp();
  return true;
});

RPC.addHandler(deviceId + '.SetState', function(args) {
  if (args.minTemp) {
    SetMinTemp(args.minTemp);
  }
  if (args.maxTemp) {
    SetMaxTemp(args.maxTemp);
  }
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

Timer.set(3000 /* milliseconds */, true /* repeat */, function() {
  let temp = state.temp;

  if (curState.temp > curState.maxTemp) {
    print('More:', curState.temp, '*C');
    // for (let i = 0; i < state.maxTempActions.length; i++) {
    //   let rpc = state.maxTempActions[i];
    //   let dst = rpc.local ? RPC.LOCAL : '';
    //   RPC.call(dst, rpc.method, rpc.args, function(res, ud) {
    //     print(JSON.stringify(state));
    //   }, null);
    // }
  } else if (curState.temp < curState.minTemp) {
    print('Less:', curState.temp, '*C');
  }

  print('Temperature:', curState.temp, '*C');
  print('Humidity:', curState.hum, '%');
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
  // RPC.call(RPC.LOCAL, deviceId + '.IncrementMaxTemp', {}, function(res, ud) {
  //   print(JSON.stringify(state));
  // }, null);

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
