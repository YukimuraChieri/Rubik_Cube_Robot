; Auto-generated. Do not edit!


(cl:in-package action_demo-msg)


;//! \htmlinclude ActTestGoal.msg.html

(cl:defclass <ActTestGoal> (roslisp-msg-protocol:ros-message)
  ((step_num
    :reader step_num
    :initarg :step_num
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ActTestGoal (<ActTestGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ActTestGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ActTestGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name action_demo-msg:<ActTestGoal> is deprecated: use action_demo-msg:ActTestGoal instead.")))

(cl:ensure-generic-function 'step_num-val :lambda-list '(m))
(cl:defmethod step_num-val ((m <ActTestGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader action_demo-msg:step_num-val is deprecated.  Use action_demo-msg:step_num instead.")
  (step_num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ActTestGoal>) ostream)
  "Serializes a message object of type '<ActTestGoal>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'step_num)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'step_num)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ActTestGoal>) istream)
  "Deserializes a message object of type '<ActTestGoal>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'step_num)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'step_num)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ActTestGoal>)))
  "Returns string type for a message object of type '<ActTestGoal>"
  "action_demo/ActTestGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ActTestGoal)))
  "Returns string type for a message object of type 'ActTestGoal"
  "action_demo/ActTestGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ActTestGoal>)))
  "Returns md5sum for a message object of type '<ActTestGoal>"
  "9887d69f974ffe6cc0219745fb2fdaf5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ActTestGoal)))
  "Returns md5sum for a message object of type 'ActTestGoal"
  "9887d69f974ffe6cc0219745fb2fdaf5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ActTestGoal>)))
  "Returns full string definition for message of type '<ActTestGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%uint16 step_num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ActTestGoal)))
  "Returns full string definition for message of type 'ActTestGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%uint16 step_num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ActTestGoal>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ActTestGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'ActTestGoal
    (cl:cons ':step_num (step_num msg))
))