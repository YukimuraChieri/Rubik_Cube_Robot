; Auto-generated. Do not edit!


(cl:in-package face_read-srv)


;//! \htmlinclude SetParameters-request.msg.html

(cl:defclass <SetParameters-request> (roslisp-msg-protocol:ros-message)
  ((paras
    :reader paras
    :initarg :paras
    :type cl:string
    :initform ""))
)

(cl:defclass SetParameters-request (<SetParameters-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetParameters-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetParameters-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_read-srv:<SetParameters-request> is deprecated: use face_read-srv:SetParameters-request instead.")))

(cl:ensure-generic-function 'paras-val :lambda-list '(m))
(cl:defmethod paras-val ((m <SetParameters-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_read-srv:paras-val is deprecated.  Use face_read-srv:paras instead.")
  (paras m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetParameters-request>) ostream)
  "Serializes a message object of type '<SetParameters-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'paras))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'paras))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetParameters-request>) istream)
  "Deserializes a message object of type '<SetParameters-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'paras) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'paras) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetParameters-request>)))
  "Returns string type for a service object of type '<SetParameters-request>"
  "face_read/SetParametersRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetParameters-request)))
  "Returns string type for a service object of type 'SetParameters-request"
  "face_read/SetParametersRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetParameters-request>)))
  "Returns md5sum for a message object of type '<SetParameters-request>"
  "771cbc2cb2ba5e0bedf422ca8d884dac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetParameters-request)))
  "Returns md5sum for a message object of type 'SetParameters-request"
  "771cbc2cb2ba5e0bedf422ca8d884dac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetParameters-request>)))
  "Returns full string definition for message of type '<SetParameters-request>"
  (cl:format cl:nil "string paras~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetParameters-request)))
  "Returns full string definition for message of type 'SetParameters-request"
  (cl:format cl:nil "string paras~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetParameters-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'paras))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetParameters-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetParameters-request
    (cl:cons ':paras (paras msg))
))
;//! \htmlinclude SetParameters-response.msg.html

(cl:defclass <SetParameters-response> (roslisp-msg-protocol:ros-message)
  ((feedback
    :reader feedback
    :initarg :feedback
    :type cl:string
    :initform ""))
)

(cl:defclass SetParameters-response (<SetParameters-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetParameters-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetParameters-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_read-srv:<SetParameters-response> is deprecated: use face_read-srv:SetParameters-response instead.")))

(cl:ensure-generic-function 'feedback-val :lambda-list '(m))
(cl:defmethod feedback-val ((m <SetParameters-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_read-srv:feedback-val is deprecated.  Use face_read-srv:feedback instead.")
  (feedback m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetParameters-response>) ostream)
  "Serializes a message object of type '<SetParameters-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'feedback))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'feedback))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetParameters-response>) istream)
  "Deserializes a message object of type '<SetParameters-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'feedback) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'feedback) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetParameters-response>)))
  "Returns string type for a service object of type '<SetParameters-response>"
  "face_read/SetParametersResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetParameters-response)))
  "Returns string type for a service object of type 'SetParameters-response"
  "face_read/SetParametersResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetParameters-response>)))
  "Returns md5sum for a message object of type '<SetParameters-response>"
  "771cbc2cb2ba5e0bedf422ca8d884dac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetParameters-response)))
  "Returns md5sum for a message object of type 'SetParameters-response"
  "771cbc2cb2ba5e0bedf422ca8d884dac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetParameters-response>)))
  "Returns full string definition for message of type '<SetParameters-response>"
  (cl:format cl:nil "string feedback~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetParameters-response)))
  "Returns full string definition for message of type 'SetParameters-response"
  (cl:format cl:nil "string feedback~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetParameters-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'feedback))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetParameters-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetParameters-response
    (cl:cons ':feedback (feedback msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetParameters)))
  'SetParameters-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetParameters)))
  'SetParameters-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetParameters)))
  "Returns string type for a service object of type '<SetParameters>"
  "face_read/SetParameters")