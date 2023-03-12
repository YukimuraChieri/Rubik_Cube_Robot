// Auto-generated. Do not edit!

// (in-package path_planning.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class PathPlanningRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.solve_str = null;
      this.hand_axis = null;
    }
    else {
      if (initObj.hasOwnProperty('solve_str')) {
        this.solve_str = initObj.solve_str
      }
      else {
        this.solve_str = '';
      }
      if (initObj.hasOwnProperty('hand_axis')) {
        this.hand_axis = initObj.hand_axis
      }
      else {
        this.hand_axis = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PathPlanningRequest
    // Serialize message field [solve_str]
    bufferOffset = _serializer.string(obj.solve_str, buffer, bufferOffset);
    // Serialize message field [hand_axis]
    bufferOffset = _serializer.string(obj.hand_axis, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PathPlanningRequest
    let len;
    let data = new PathPlanningRequest(null);
    // Deserialize message field [solve_str]
    data.solve_str = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [hand_axis]
    data.hand_axis = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.solve_str);
    length += _getByteLength(object.hand_axis);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'path_planning/PathPlanningRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'af5709462db5b1aa4cc8f6fe93e80af6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string solve_str
    string hand_axis
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PathPlanningRequest(null);
    if (msg.solve_str !== undefined) {
      resolved.solve_str = msg.solve_str;
    }
    else {
      resolved.solve_str = ''
    }

    if (msg.hand_axis !== undefined) {
      resolved.hand_axis = msg.hand_axis;
    }
    else {
      resolved.hand_axis = ''
    }

    return resolved;
    }
};

class PathPlanningResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PathPlanningResponse
    // Serialize message field [result]
    bufferOffset = _serializer.string(obj.result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PathPlanningResponse
    let len;
    let data = new PathPlanningResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.result);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'path_planning/PathPlanningResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c22f2a1ed8654a0b365f1bb3f7ff2c0f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string result
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PathPlanningResponse(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: PathPlanningRequest,
  Response: PathPlanningResponse,
  md5sum() { return '1eee7119fb9bc2458d0167605d08766d'; },
  datatype() { return 'path_planning/PathPlanning'; }
};
