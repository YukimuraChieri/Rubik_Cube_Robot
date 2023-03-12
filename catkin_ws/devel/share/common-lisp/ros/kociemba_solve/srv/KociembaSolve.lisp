; Auto-generated. Do not edit!


(cl:in-package kociemba_solve-srv)


;//! \htmlinclude KociembaSolve-request.msg.html

(cl:defclass <KociembaSolve-request> (roslisp-msg-protocol:ros-message)
  ((six_face_str
    :reader six_face_str
    :initarg :six_face_str
    :type cl:string
    :initform ""))
)

(cl:defclass KociembaSolve-request (<KociembaSolve-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KociembaSolve-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KociembaSolve-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kociemba_solve-srv:<KociembaSolve-request> is deprecated: use kociemba_solve-srv:KociembaSolve-request instead.")))

(cl:ensure-generic-function 'six_face_str-val :lambda-list '(m))
(cl:defmethod six_face_str-val ((m <KociembaSolve-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kociemba_solve-srv:six_face_str-val is deprecated.  Use kociemba_solve-srv:six_face_str instead.")
  (six_face_str m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KociembaSolve-request>) ostream)
  "Serializes a message object of type '<KociembaSolve-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'six_face_str))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'six_face_str))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KociembaSolve-request>) istream)
  "Deserializes a message object of type '<KociembaSolve-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'six_face_str) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'six_face_str) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KociembaSolve-request>)))
  "Returns string type for a service object of type '<KociembaSolve-request>"
  "kociemba_solve/KociembaSolveRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KociembaSolve-request)))
  "Returns string type for a service object of type 'KociembaSolve-request"
  "kociemba_solve/KociembaSolveRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KociembaSolve-request>)))
  "Returns md5sum for a message object of type '<KociembaSolve-request>"
  "2dda5a023a8b634c158eca12da32426c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KociembaSolve-request)))
  "Returns md5sum for a message object of type 'KociembaSolve-request"
  "2dda5a023a8b634c158eca12da32426c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KociembaSolve-request>)))
  "Returns full string definition for message of type '<KociembaSolve-request>"
  (cl:format cl:nil "string six_face_str~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KociembaSolve-request)))
  "Returns full string definition for message of type 'KociembaSolve-request"
  (cl:format cl:nil "string six_face_str~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KociembaSolve-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'six_face_str))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KociembaSolve-request>))
  "Converts a ROS message object to a list"
  (cl:list 'KociembaSolve-request
    (cl:cons ':six_face_str (six_face_str msg))
))
;//! \htmlinclude KociembaSolve-response.msg.html

(cl:defclass <KociembaSolve-response> (roslisp-msg-protocol:ros-message)
  ((solve_str
    :reader solve_str
    :initarg :solve_str
    :type cl:string
    :initform ""))
)

(cl:defclass KociembaSolve-response (<KociembaSolve-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KociembaSolve-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KociembaSolve-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kociemba_solve-srv:<KociembaSolve-response> is deprecated: use kociemba_solve-srv:KociembaSolve-response instead.")))

(cl:ensure-generic-function 'solve_str-val :lambda-list '(m))
(cl:defmethod solve_str-val ((m <KociembaSolve-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kociemba_solve-srv:solve_str-val is deprecated.  Use kociemba_solve-srv:solve_str instead.")
  (solve_str m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KociembaSolve-response>) ostream)
  "Serializes a message object of type '<KociembaSolve-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'solve_str))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'solve_str))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KociembaSolve-response>) istream)
  "Deserializes a message object of type '<KociembaSolve-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'solve_str) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'solve_str) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KociembaSolve-response>)))
  "Returns string type for a service object of type '<KociembaSolve-response>"
  "kociemba_solve/KociembaSolveResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KociembaSolve-response)))
  "Returns string type for a service object of type 'KociembaSolve-response"
  "kociemba_solve/KociembaSolveResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KociembaSolve-response>)))
  "Returns md5sum for a message object of type '<KociembaSolve-response>"
  "2dda5a023a8b634c158eca12da32426c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KociembaSolve-response)))
  "Returns md5sum for a message object of type 'KociembaSolve-response"
  "2dda5a023a8b634c158eca12da32426c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KociembaSolve-response>)))
  "Returns full string definition for message of type '<KociembaSolve-response>"
  (cl:format cl:nil "string solve_str~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KociembaSolve-response)))
  "Returns full string definition for message of type 'KociembaSolve-response"
  (cl:format cl:nil "string solve_str~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KociembaSolve-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'solve_str))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KociembaSolve-response>))
  "Converts a ROS message object to a list"
  (cl:list 'KociembaSolve-response
    (cl:cons ':solve_str (solve_str msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'KociembaSolve)))
  'KociembaSolve-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'KociembaSolve)))
  'KociembaSolve-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KociembaSolve)))
  "Returns string type for a service object of type '<KociembaSolve>"
  "kociemba_solve/KociembaSolve")