// Auto-generated. Do not edit!

// (in-package face_read.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SetParametersRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.paras = null;
    }
    else {
      if (initObj.hasOwnProperty('paras')) {
        this.paras = initObj.paras
      }
      else {
        this.paras = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetParametersRequest
    // Serialize message field [paras]
    bufferOffset = _serializer.string(obj.paras, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetParametersRequest
    let len;
    let data = new SetParametersRequest(null);
    // Deserialize message field [paras]
    data.paras = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.paras);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'face_read/SetParametersRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6485c21672e59e8ec1ecffa78b8b97fc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string paras
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetParametersRequest(null);
    if (msg.paras !== undefined) {
      resolved.paras = msg.paras;
    }
    else {
      resolved.paras = ''
    }

    return resolved;
    }
};

class SetParametersResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.feedback = null;
    }
    else {
      if (initObj.hasOwnProperty('feedback')) {
        this.feedback = initObj.feedback
      }
      else {
        this.feedback = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetParametersResponse
    // Serialize message field [feedback]
    bufferOffset = _serializer.string(obj.feedback, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetParametersResponse
    let len;
    let data = new SetParametersResponse(null);
    // Deserialize message field [feedback]
    data.feedback = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.feedback);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'face_read/SetParametersResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c14cdf907e5c7c7fd47292add15660f0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string feedback
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetParametersResponse(null);
    if (msg.feedback !== undefined) {
      resolved.feedback = msg.feedback;
    }
    else {
      resolved.feedback = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: SetParametersRequest,
  Response: SetParametersResponse,
  md5sum() { return '771cbc2cb2ba5e0bedf422ca8d884dac'; },
  datatype() { return 'face_read/SetParameters'; }
};
