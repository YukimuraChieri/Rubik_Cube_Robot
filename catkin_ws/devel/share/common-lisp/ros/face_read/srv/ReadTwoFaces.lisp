; Auto-generated. Do not edit!


(cl:in-package face_read-srv)


;//! \htmlinclude ReadTwoFaces-request.msg.html

(cl:defclass <ReadTwoFaces-request> (roslisp-msg-protocol:ros-message)
  ((side
    :reader side
    :initarg :side
    :type cl:string
    :initform ""))
)

(cl:defclass ReadTwoFaces-request (<ReadTwoFaces-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReadTwoFaces-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReadTwoFaces-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_read-srv:<ReadTwoFaces-request> is deprecated: use face_read-srv:ReadTwoFaces-request instead.")))

(cl:ensure-generic-function 'side-val :lambda-list '(m))
(cl:defmethod side-val ((m <ReadTwoFaces-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_read-srv:side-val is deprecated.  Use face_read-srv:side instead.")
  (side m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReadTwoFaces-request>) ostream)
  "Serializes a message object of type '<ReadTwoFaces-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'side))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'side))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReadTwoFaces-request>) istream)
  "Deserializes a message object of type '<ReadTwoFaces-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'side) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'side) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReadTwoFaces-request>)))
  "Returns string type for a service object of type '<ReadTwoFaces-request>"
  "face_read/ReadTwoFacesRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadTwoFaces-request)))
  "Returns string type for a service object of type 'ReadTwoFaces-request"
  "face_read/ReadTwoFacesRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReadTwoFaces-request>)))
  "Returns md5sum for a message object of type '<ReadTwoFaces-request>"
  "3c14a0fe7db327aef6da537797c5908f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReadTwoFaces-request)))
  "Returns md5sum for a message object of type 'ReadTwoFaces-request"
  "3c14a0fe7db327aef6da537797c5908f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReadTwoFaces-request>)))
  "Returns full string definition for message of type '<ReadTwoFaces-request>"
  (cl:format cl:nil "string side~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReadTwoFaces-request)))
  "Returns full string definition for message of type 'ReadTwoFaces-request"
  (cl:format cl:nil "string side~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReadTwoFaces-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'side))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReadTwoFaces-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ReadTwoFaces-request
    (cl:cons ':side (side msg))
))
;//! \htmlinclude ReadTwoFaces-response.msg.html

(cl:defclass <ReadTwoFaces-response> (roslisp-msg-protocol:ros-message)
  ((face_1
    :reader face_1
    :initarg :face_1
    :type cl:string
    :initform "")
   (face_2
    :reader face_2
    :initarg :face_2
    :type cl:string
    :initform ""))
)

(cl:defclass ReadTwoFaces-response (<ReadTwoFaces-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReadTwoFaces-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReadTwoFaces-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name face_read-srv:<ReadTwoFaces-response> is deprecated: use face_read-srv:ReadTwoFaces-response instead.")))

(cl:ensure-generic-function 'face_1-val :lambda-list '(m))
(cl:defmethod face_1-val ((m <ReadTwoFaces-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_read-srv:face_1-val is deprecated.  Use face_read-srv:face_1 instead.")
  (face_1 m))

(cl:ensure-generic-function 'face_2-val :lambda-list '(m))
(cl:defmethod face_2-val ((m <ReadTwoFaces-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader face_read-srv:face_2-val is deprecated.  Use face_read-srv:face_2 instead.")
  (face_2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReadTwoFaces-response>) ostream)
  "Serializes a message object of type '<ReadTwoFaces-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'face_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'face_1))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'face_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'face_2))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReadTwoFaces-response>) istream)
  "Deserializes a message object of type '<ReadTwoFaces-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'face_1) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'face_1) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'face_2) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'face_2) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReadTwoFaces-response>)))
  "Returns string type for a service object of type '<ReadTwoFaces-response>"
  "face_read/ReadTwoFacesResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadTwoFaces-response)))
  "Returns string type for a service object of type 'ReadTwoFaces-response"
  "face_read/ReadTwoFacesResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReadTwoFaces-response>)))
  "Returns md5sum for a message object of type '<ReadTwoFaces-response>"
  "3c14a0fe7db327aef6da537797c5908f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReadTwoFaces-response)))
  "Returns md5sum for a message object of type 'ReadTwoFaces-response"
  "3c14a0fe7db327aef6da537797c5908f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReadTwoFaces-response>)))
  "Returns full string definition for message of type '<ReadTwoFaces-response>"
  (cl:format cl:nil "string face_1~%string face_2~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReadTwoFaces-response)))
  "Returns full string definition for message of type 'ReadTwoFaces-response"
  (cl:format cl:nil "string face_1~%string face_2~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReadTwoFaces-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'face_1))
     4 (cl:length (cl:slot-value msg 'face_2))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReadTwoFaces-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ReadTwoFaces-response
    (cl:cons ':face_1 (face_1 msg))
    (cl:cons ':face_2 (face_2 msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ReadTwoFaces)))
  'ReadTwoFaces-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ReadTwoFaces)))
  'ReadTwoFaces-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadTwoFaces)))
  "Returns string type for a service object of type '<ReadTwoFaces>"
  "face_read/ReadTwoFaces")