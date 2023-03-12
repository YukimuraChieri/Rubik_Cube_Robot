; Auto-generated. Do not edit!


(cl:in-package kociemba_solve-srv)


;//! \htmlinclude RandomSolve-request.msg.html

(cl:defclass <RandomSolve-request> (roslisp-msg-protocol:ros-message)
  ((step_num
    :reader step_num
    :initarg :step_num
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RandomSolve-request (<RandomSolve-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RandomSolve-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RandomSolve-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kociemba_solve-srv:<RandomSolve-request> is deprecated: use kociemba_solve-srv:RandomSolve-request instead.")))

(cl:ensure-generic-function 'step_num-val :lambda-list '(m))
(cl:defmethod step_num-val ((m <RandomSolve-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kociemba_solve-srv:step_num-val is deprecated.  Use kociemba_solve-srv:step_num instead.")
  (step_num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RandomSolve-request>) ostream)
  "Serializes a message object of type '<RandomSolve-request>"
  (cl:let* ((signed (cl:slot-value msg 'step_num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RandomSolve-request>) istream)
  "Deserializes a message object of type '<RandomSolve-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'step_num) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RandomSolve-request>)))
  "Returns string type for a service object of type '<RandomSolve-request>"
  "kociemba_solve/RandomSolveRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RandomSolve-request)))
  "Returns string type for a service object of type 'RandomSolve-request"
  "kociemba_solve/RandomSolveRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RandomSolve-request>)))
  "Returns md5sum for a message object of type '<RandomSolve-request>"
  "1e50375af0a44d22e32e9a1b65fd9076")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RandomSolve-request)))
  "Returns md5sum for a message object of type 'RandomSolve-request"
  "1e50375af0a44d22e32e9a1b65fd9076")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RandomSolve-request>)))
  "Returns full string definition for message of type '<RandomSolve-request>"
  (cl:format cl:nil "int16 step_num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RandomSolve-request)))
  "Returns full string definition for message of type 'RandomSolve-request"
  (cl:format cl:nil "int16 step_num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RandomSolve-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RandomSolve-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RandomSolve-request
    (cl:cons ':step_num (step_num msg))
))
;//! \htmlinclude RandomSolve-response.msg.html

(cl:defclass <RandomSolve-response> (roslisp-msg-protocol:ros-message)
  ((random_str
    :reader random_str
    :initarg :random_str
    :type cl:string
    :initform ""))
)

(cl:defclass RandomSolve-response (<RandomSolve-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RandomSolve-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RandomSolve-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kociemba_solve-srv:<RandomSolve-response> is deprecated: use kociemba_solve-srv:RandomSolve-response instead.")))

(cl:ensure-generic-function 'random_str-val :lambda-list '(m))
(cl:defmethod random_str-val ((m <RandomSolve-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kociemba_solve-srv:random_str-val is deprecated.  Use kociemba_solve-srv:random_str instead.")
  (random_str m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RandomSolve-response>) ostream)
  "Serializes a message object of type '<RandomSolve-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'random_str))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'random_str))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RandomSolve-response>) istream)
  "Deserializes a message object of type '<RandomSolve-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'random_str) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'random_str) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RandomSolve-response>)))
  "Returns string type for a service object of type '<RandomSolve-response>"
  "kociemba_solve/RandomSolveResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RandomSolve-response)))
  "Returns string type for a service object of type 'RandomSolve-response"
  "kociemba_solve/RandomSolveResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RandomSolve-response>)))
  "Returns md5sum for a message object of type '<RandomSolve-response>"
  "1e50375af0a44d22e32e9a1b65fd9076")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RandomSolve-response)))
  "Returns md5sum for a message object of type 'RandomSolve-response"
  "1e50375af0a44d22e32e9a1b65fd9076")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RandomSolve-response>)))
  "Returns full string definition for message of type '<RandomSolve-response>"
  (cl:format cl:nil "string random_str~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RandomSolve-response)))
  "Returns full string definition for message of type 'RandomSolve-response"
  (cl:format cl:nil "string random_str~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RandomSolve-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'random_str))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RandomSolve-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RandomSolve-response
    (cl:cons ':random_str (random_str msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RandomSolve)))
  'RandomSolve-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RandomSolve)))
  'RandomSolve-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RandomSolve)))
  "Returns string type for a service object of type '<RandomSolve>"
  "kociemba_solve/RandomSolve")