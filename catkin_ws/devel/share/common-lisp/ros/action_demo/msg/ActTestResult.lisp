; Auto-generated. Do not edit!


(cl:in-package action_demo-msg)


;//! \htmlinclude ActTestResult.msg.html

(cl:defclass <ActTestResult> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:string
    :initform ""))
)

(cl:defclass ActTestResult (<ActTestResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ActTestResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ActTestResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name action_demo-msg:<ActTestResult> is deprecated: use action_demo-msg:ActTestResult instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ActTestResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader action_demo-msg:result-val is deprecated.  Use action_demo-msg:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ActTestResult>) ostream)
  "Serializes a message object of type '<ActTestResult>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'result))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ActTestResult>) istream)
  "Deserializes a message object of type '<ActTestResult>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'result) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ActTestResult>)))
  "Returns string type for a message object of type '<ActTestResult>"
  "action_demo/ActTestResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ActTestResult)))
  "Returns string type for a message object of type 'ActTestResult"
  "action_demo/ActTestResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ActTestResult>)))
  "Returns md5sum for a message object of type '<ActTestResult>"
  "c22f2a1ed8654a0b365f1bb3f7ff2c0f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ActTestResult)))
  "Returns md5sum for a message object of type 'ActTestResult"
  "c22f2a1ed8654a0b365f1bb3f7ff2c0f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ActTestResult>)))
  "Returns full string definition for message of type '<ActTestResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%string result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ActTestResult)))
  "Returns full string definition for message of type 'ActTestResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%string result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ActTestResult>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'result))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ActTestResult>))
  "Converts a ROS message object to a list"
  (cl:list 'ActTestResult
    (cl:cons ':result (result msg))
))
