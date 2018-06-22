// Auto-generated. Do not edit!

// (in-package ros_arduino_trial.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class pwm_signal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.dir = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('dir')) {
        this.dir = initObj.dir
      }
      else {
        this.dir = false;
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type pwm_signal
    // Serialize message field [dir]
    bufferOffset = _serializer.bool(obj.dir, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _serializer.uint16(obj.data, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pwm_signal
    let len;
    let data = new pwm_signal(null);
    // Deserialize message field [dir]
    data.dir = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_arduino_trial/pwm_signal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a874b178257f5432b765c0462992b150';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #This is the message file for generating a custom message to control a DC
    #motor using MD10C R3 motor driver by Cytron technologies in Sign Magnitude 
    #mode.
    bool dir
    uint16 data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pwm_signal(null);
    if (msg.dir !== undefined) {
      resolved.dir = msg.dir;
    }
    else {
      resolved.dir = false
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = 0
    }

    return resolved;
    }
};

module.exports = pwm_signal;
