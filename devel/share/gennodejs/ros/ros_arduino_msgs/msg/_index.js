
"use strict";

let Digital = require('./Digital.js');
let Analog = require('./Analog.js');
let AnalogFloat = require('./AnalogFloat.js');
let SensorState = require('./SensorState.js');
let ArduinoConstants = require('./ArduinoConstants.js');

module.exports = {
  Digital: Digital,
  Analog: Analog,
  AnalogFloat: AnalogFloat,
  SensorState: SensorState,
  ArduinoConstants: ArduinoConstants,
};
