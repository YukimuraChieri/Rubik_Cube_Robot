; Auto-generated. Do not edit!


(cl:in-package path_planning-srv)


;//! \htmlinclude PathPlanning-request.msg.html

(cl:defclass <PathPlanning-request> (roslisp-msg-protocol:ros-message)
  ((solve_str
    :reader solve_str
    :initarg :solve_str
    :type cl:string
    :initform "")
   (hand_axis
    :reader hand_axis
    :initarg :hand_axis
    :type cl:string
    :initform ""))
)

(cl:defclass PathPlanning-request (<PathPlanning-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PathPlanning-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PathPlanning-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name path_planning-srv:<PathPlanning-request> is deprecated: use path_planning-srv:PathPlanning-request instead.")))

(cl:ensure-generic-function 'solve_str-val :lambda-list '(m))
(cl:defmethod solve_str-val ((m <PathPlanning-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_planning-srv:solve_str-val is deprecated.  Use path_planning-srv:solve_str instead.")
  (solve_str m))

(cl:ensure-generic-function 'hand_axis-val :lambda-list '(m))
(cl:defmethod hand_axis-val ((m <PathPlanning-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_planning-srv:hand_axis-val is deprecated.  Use path_planning-srv:hand_axis instead.")
  (hand_axis m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PathPlanning-request>) ostream)
  "Serializes a message object of type '<PathPlanning-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'solve_str))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'solve_str))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'hand_axis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'hand_axis))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PathPlanning-request>) istream)
  "Deserializes a message object of type '<PathPlanning-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'solve_str) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'solve_str) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'hand_axis) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'hand_axis) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PathPlanning-request>)))
  "Returns string type for a service object of type '<PathPlanning-request>"
  "path_planning/PathPlanningRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PathPlanning-request)))
  "Returns string type for a service object of type 'PathPlanning-request"
  "path_planning/PathPlanningRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PathPlanning-request>)))
  "Returns md5sum for a message object of type '<PathPlanning-request>"
  "1eee7119fb9bc2458d0167605d08766d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PathPlanning-request)))
  "Returns md5sum for a message object of type 'PathPlanning-request"
  "1eee7119fb9bc2458d0167605d08766d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PathPlanning-request>)))
  "Returns full string definition for message of type '<PathPlanning-request>"
  (cl:format cl:nil "string solve_str~%string hand_axis~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PathPlanning-request)))
  "Returns full string definition for message of type 'PathPlanning-request"
  (cl:format cl:nil "string solve_str~%string hand_axis~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PathPlanning-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'solve_str))
     4 (cl:length (cl:slot-value msg 'hand_axis))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PathPlanning-request>))
  "Converts a ROS message object to a list"
  (cl:list 'PathPlanning-request
    (cl:cons ':solve_str (solve_str msg))
    (cl:cons ':hand_axis (hand_axis msg))
))
;//! \htmlinclude PathPlanning-response.msg.html

(cl:defclass <PathPlanning-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:string
    :initform ""))
)

(cl:defclass PathPlanning-response (<PathPlanning-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PathPlanning-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PathPlanning-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name path_planning-srv:<PathPlanning-response> is deprecated: use path_planning-srv:PathPlanning-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <PathPlanning-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_planning-srv:result-val is deprecated.  Use path_planning-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PathPlanning-response>) ostream)
  "Serializes a message object of type '<PathPlanning-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'result))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PathPlanning-response>) istream)
  "Deserializes a message object of type '<PathPlanning-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PathPlanning-response>)))
  "Returns string type for a service object of type '<PathPlanning-response>"
  "path_planning/PathPlanningResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PathPlanning-response)))
  "Returns string type for a service object of type 'PathPlanning-response"
  "path_planning/PathPlanningResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PathPlanning-response>)))
  "Returns md5sum for a message object of type '<PathPlanning-response>"
  "1eee7119fb9bc2458d0167605d08766d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PathPlanning-response)))
  "Returns md5sum for a message object of type 'PathPlanning-response"
  "1eee7119fb9bc2458d0167605d08766d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PathPlanning-response>)))
  "Returns full string definition for message of type '<PathPlanning-response>"
  (cl:format cl:nil "string result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PathPlanning-response)))
  "Returns full string definition for message of type 'PathPlanning-response"
  (cl:format cl:nil "string result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PathPlanning-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'result))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PathPlanning-response>))
  "Converts a ROS message object to a list"
  (cl:list 'PathPlanning-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'PathPlanning)))
  'PathPlanning-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'PathPlanning)))
  'PathPlanning-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PathPlanning)))
  "Returns string type for a service object of type '<PathPlanning>"
  "path_planning/PathPlanning")