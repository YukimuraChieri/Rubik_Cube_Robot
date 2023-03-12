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

class KociembaSolveRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.six_face_str = null;
    }
    else {
      if (initObj.hasOwnProperty('six_face_str')) {
        this.six_face_str = initObj.six_face_str
      }
      else {
        this.six_face_str = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type KociembaSolveRequest
    // Serialize message field [six_face_str]
    bufferOffset = _serializer.string(obj.six_face_str, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type KociembaSolveRequest
    let len;
    let data = new KociembaSolveRequest(null);
    // Deserialize message field [six_face_str]
    data.six_face_str = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.six_face_str);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'kociemba_solve/KociembaSolveRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bb54d8370dea95c40a6a0b3161f627c9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string six_face_str
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new KociembaSolveRequest(null);
    if (msg.six_face_str !== undefined) {
      resolved.six_face_str = msg.six_face_str;
    }
    else {
      resolved.six_face_str = ''
    }

    return resolved;
    }
};

class KociembaSolveResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.solve_str = null;
    }
    else {
      if (initObj.hasOwnProperty('solve_str')) {
        this.solve_str = initObj.solve_str
      }
      else {
        this.solve_str = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type KociembaSolveResponse
    // Serialize message field [solve_str]
    bufferOffset = _serializer.string(obj.solve_str, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type KociembaSolveResponse
    let len;
    let data = new KociembaSolveResponse(null);
    // Deserialize message field [solve_str]
    data.solve_str = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.solve_str);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'kociemba_solve/KociembaSolveResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ac23f95809f2e14e3143946f779d7d45';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string solve_str
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new KociembaSolveResponse(null);
    if (msg.solve_str !== undefined) {
      resolved.solve_str = msg.solve_str;
    }
    else {
      resolved.solve_str = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: KociembaSolveRequest,
  Response: KociembaSolveResponse,
  md5sum() { return '2dda5a023a8b634c158eca12da32426c'; },
  datatype() { return 'kociemba_solve/KociembaSolve'; }
};
