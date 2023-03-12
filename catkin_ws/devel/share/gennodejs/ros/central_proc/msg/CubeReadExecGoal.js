// Auto-generated. Do not edit!

// (in-package central_proc.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class CubeReadExecGoal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.read_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('read_mode')) {
        this.read_mode = initObj.read_mode
      }
      else {
        this.read_mode = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CubeReadExecGoal
    // Serialize message field [read_mode]
    bufferOffset = _serializer.string(obj.read_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CubeReadExecGoal
    let len;
    let data = new CubeReadExecGoal(null);
    // Deserialize message field [read_mode]
    data.read_mode = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.read_mode);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'central_proc/CubeReadExecGoal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd133e27424af94de682501d23720b86f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    # 读取模式
    string read_mode
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CubeReadExecGoal(null);
    if (msg.read_mode !== undefined) {
      resolved.read_mode = msg.read_mode;
    }
    else {
      resolved.read_mode = ''
    }

    return resolved;
    }
};

module.exports = CubeReadExecGoal;