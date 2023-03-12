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

class GetParametersRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetParametersRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetParametersRequest
    let len;
    let data = new GetParametersRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'face_read/GetParametersRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetParametersRequest(null);
    return resolved;
    }
};

class GetParametersResponse {
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
    // Serializes a message object of type GetParametersResponse
    // Serialize message field [paras]
    bufferOffset = _serializer.string(obj.paras, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetParametersResponse
    let len;
    let data = new GetParametersResponse(null);
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
    return 'face_read/GetParametersResponse';
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
    const resolved = new GetParametersResponse(null);
    if (msg.paras !== undefined) {
      resolved.paras = msg.paras;
    }
    else {
      resolved.paras = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: GetParametersRequest,
  Response: GetParametersResponse,
  md5sum() { return '6485c21672e59e8ec1ecffa78b8b97fc'; },
  datatype() { return 'face_read/GetParameters'; }
};
