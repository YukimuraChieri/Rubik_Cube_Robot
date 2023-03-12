// Auto-generated. Do not edit!

// (in-package kociemba_solve.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class RandomSolveRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.step_num = null;
    }
    else {
      if (initObj.hasOwnProperty('step_num')) {
        this.step_num = initObj.step_num
      }
      else {
        this.step_num = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RandomSolveRequest
    // Serialize message field [step_num]
    bufferOffset = _serializer.int16(obj.step_num, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RandomSolveRequest
    let len;
    let data = new RandomSolveRequest(null);
    // Deserialize message field [step_num]
    data.step_num = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'kociemba_solve/RandomSolveRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f2f706fe36a6478a8fe63c803973d9a5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 step_num
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RandomSolveRequest(null);
    if (msg.step_num !== undefined) {
      resolved.step_num = msg.step_num;
    }
    else {
      resolved.step_num = 0
    }

    return resolved;
    }
};

class RandomSolveResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.random_str = null;
    }
    else {
      if (initObj.hasOwnProperty('random_str')) {
        this.random_str = initObj.random_str
      }
      else {
        this.random_str = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RandomSolveResponse
    // Serialize message field [random_str]
    bufferOffset = _serializer.string(obj.random_str, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RandomSolveResponse
    let len;
    let data = new RandomSolveResponse(null);
    // Deserialize message field [random_str]
    data.random_str = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.random_str);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'kociemba_solve/RandomSolveResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9c6c1fce66086563633ba1d124c1ee88';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string random_str
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RandomSolveResponse(null);
    if (msg.random_str !== undefined) {
      resolved.random_str = msg.random_str;
    }
    else {
      resolved.random_str = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: RandomSolveRequest,
  Response: RandomSolveResponse,
  md5sum() { return '1e50375af0a44d22e32e9a1b65fd9076'; },
  datatype() { return 'kociemba_solve/RandomSolve'; }
};
