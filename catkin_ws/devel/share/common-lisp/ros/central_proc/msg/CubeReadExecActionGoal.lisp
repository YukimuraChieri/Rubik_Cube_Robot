; Auto-generated. Do not edit!


(cl:in-package central_proc-msg)


;//! \htmlinclude CubeReadExecActionGoal.msg.html

(cl:defclass <CubeReadExecActionGoal> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (goal_id
    :reader goal_id
    :initarg :goal_id
    :type actionlib_msgs-msg:GoalID
    :initform (cl:make-instance 'actionlib_msgs-msg:GoalID))
   (goal
    :reader goal
    :initarg :goal
    :type central_proc-msg:CubeReadExecGoal
    :initform (cl:make-instance 'central_proc-msg:CubeReadExecGoal)))
)

(cl:defclass CubeReadExecActionGoal (<CubeReadExecActionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CubeReadExecActionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CubeReadExecActionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name central_proc-msg:<CubeReadExecActionGoal> is deprecated: use central_proc-msg:CubeReadExecActionGoal instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <CubeReadExecActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader central_proc-msg:header-val is deprecated.  Use central_proc-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'goal_id-val :lambda-list '(m))
(cl:defmethod goal_id-val ((m <CubeReadExecActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader central_proc-msg:goal_id-val is deprecated.  Use central_proc-msg:goal_id instead.")
  (goal_id m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <CubeReadExecActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader central_proc-msg:goal-val is deprecated.  Use central_proc-msg:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CubeReadExecActionGoal>) ostream)
  "Serializes a message object of type '<CubeReadExecActionGoal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal_id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CubeReadExecActionGoal>) istream)
  "Deserializes a message object of type '<CubeReadExecActionGoal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal_id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CubeReadExecActionGoal>)))
  "Returns string type for a message object of type '<CubeReadExecActionGoal>"
  "central_proc/CubeReadExecActionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CubeReadExecActionGoal)))
  "Returns string type for a message object of type 'CubeReadExecActionGoal"
  "central_proc/CubeReadExecActionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CubeReadExecActionGoal>)))
  "Returns md5sum for a message object of type '<CubeReadExecActionGoal>"
  "7e069dc55095aba14d8be23b14bb99a6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CubeReadExecActionGoal)))
  "Returns md5sum for a message object of type 'CubeReadExecActionGoal"
  "7e069dc55095aba14d8be23b14bb99a6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CubeReadExecActionGoal>)))
  "Returns full string definition for message of type '<CubeReadExecActionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%CubeReadExecGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: central_proc/CubeReadExecGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# 读取模式~%string read_mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CubeReadExecActionGoal)))
  "Returns full string definition for message of type 'CubeReadExecActionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%CubeReadExecGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: central_proc/CubeReadExecGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# 读取模式~%string read_mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CubeReadExecActionGoal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal_id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CubeReadExecActionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'CubeReadExecActionGoal
    (cl:cons ':header (header msg))
    (cl:cons ':goal_id (goal_id msg))
    (cl:cons ':goal (goal msg))
))