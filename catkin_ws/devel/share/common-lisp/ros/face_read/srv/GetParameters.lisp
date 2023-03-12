; Auto-generated. Do not edit!


(cl:in-package face_read-srv)


;//! \htmlinclude GetParameters-request.msg.html

(cl:defclass <GetParameters-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass GetParameters-request (<GetParameters-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetParameters-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetParameters-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_read-srv:<GetParameters-request> is deprecated: use face_read-srv:GetParameters-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetParameters-request>) ostream)
  "Serializes a message object of type '<GetParameters-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetParameters-request>) istream)
  "Deserializes a message object of type '<GetParameters-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetParameters-request>)))
  "Returns string type for a service object of type '<GetParameters-request>"
  "face_read/GetParametersRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetParameters-request)))
  "Returns string type for a service object of type 'GetParameters-request"
  "face_read/GetParametersRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetParameters-request>)))
  "Returns md5sum for a message object of type '<GetParameters-request>"
  "6485c21672e59e8ec1ecffa78b8b97fc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetParameters-request)))
  "Returns md5sum for a message object of type 'GetParameters-request"
  "6485c21672e59e8ec1ecffa78b8b97fc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetParameters-request>)))
  "Returns full string definition for message of type '<GetParameters-request>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetParameters-request)))
  "Returns full string definition for message of type 'GetParameters-request"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetParameters-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetParameters-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetParameters-request
))
;//! \htmlinclude GetParameters-response.msg.html

(cl:defclass <GetParameters-response> (roslisp-msg-protocol:ros-message)
  ((paras
    :reader paras
    :initarg :paras
    :type cl:string
    :initform ""))
)

(cl:defclass GetParameters-response (<GetParameters-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetParameters-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetParameters-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_read-srv:<GetParameters-response> is deprecated: use face_read-srv:GetParameters-response instead.")))

(cl:ensure-generic-function 'paras-val :lambda-list '(m))
(cl:defmethod paras-val ((m <GetParameters-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_read-srv:paras-val is deprecated.  Use face_read-srv:paras instead.")
  (paras m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetParameters-response>) ostream)
  "Serializes a message object of type '<GetParameters-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'paras))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'paras))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetParameters-response>) istream)
  "Deserializes a message object of type '<GetParameters-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetParameters-response>)))
  "Returns string type for a service object of type '<GetParameters-response>"
  "face_read/GetParametersResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetParameters-response)))
  "Returns string type for a service object of type 'GetParameters-response"
  "face_read/GetParametersResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetParameters-response>)))
  "Returns md5sum for a message object of type '<GetParameters-response>"
  "6485c21672e59e8ec1ecffa78b8b97fc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetParameters-response)))
  "Returns md5sum for a message object of type 'GetParameters-response"
  "6485c21672e59e8ec1ecffa78b8b97fc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetParameters-response>)))
  "Returns full string definition for message of type '<GetParameters-response>"
  (cl:format cl:nil "string paras~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetParameters-response)))
  "Returns full string definition for message of type 'GetParameters-response"
  (cl:format cl:nil "string paras~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetParameters-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'paras))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetParameters-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetParameters-response
    (cl:cons ':paras (paras msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetParameters)))
  'GetParameters-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetParameters)))
  'GetParameters-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetParameters)))
  "Returns string type for a service object of type '<GetParameters>"
  "face_read/GetParameters")