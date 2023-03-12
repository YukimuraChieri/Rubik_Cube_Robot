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

class ReadTwoFacesRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.side = null;
    }
    else {
      if (initObj.hasOwnProperty('side')) {
        this.side = initObj.side
      }
      else {
        this.side = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReadTwoFacesRequest
    // Serialize message field [side]
    bufferOffset = _serializer.string(obj.side, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReadTwoFacesRequest
    let len;
    let data = new ReadTwoFacesRequest(null);
    // Deserialize message field [side]
    data.side = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.side);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'face_read/ReadTwoFacesRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '69d615a99b3ddce4b1854895f66933a8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string side
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReadTwoFacesRequest(null);
    if (msg.side !== undefined) {
      resolved.side = msg.side;
    }
    else {
      resolved.side = ''
    }

    return resolved;
    }
};

class ReadTwoFacesResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.face_1 = null;
      this.face_2 = null;
    }
    else {
      if (initObj.hasOwnProperty('face_1')) {
        this.face_1 = initObj.face_1
      }
      else {
        this.face_1 = '';
      }
      if (initObj.hasOwnProperty('face_2')) {
        this.face_2 = initObj.face_2
      }
      else {
        this.face_2 = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReadTwoFacesResponse
    // Serialize message field [face_1]
    bufferOffset = _serializer.string(obj.face_1, buffer, bufferOffset);
    // Serialize message field [face_2]
    bufferOffset = _serializer.string(obj.face_2, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReadTwoFacesResponse
    let len;
    let data = new ReadTwoFacesResponse(null);
    // Deserialize message field [face_1]
    data.face_1 = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [face_2]
    data.face_2 = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.face_1);
    length += _getByteLength(object.face_2);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'face_read/ReadTwoFacesResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9258eb66ca62faac6a93b464c913082a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string face_1
    string face_2
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReadTwoFacesResponse(null);
    if (msg.face_1 !== undefined) {
      resolved.face_1 = msg.face_1;
    }
    else {
      resolved.face_1 = ''
    }

    if (msg.face_2 !== undefined) {
      resolved.face_2 = msg.face_2;
    }
    else {
      resolved.face_2 = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: ReadTwoFacesRequest,
  Response: ReadTwoFacesResponse,
  md5sum() { return '3c14a0fe7db327aef6da537797c5908f'; },
  datatype() { return 'face_read/ReadTwoFaces'; }
};
