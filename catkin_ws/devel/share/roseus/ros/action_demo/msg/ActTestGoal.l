;; Auto-generated. Do not edit!


(when (boundp 'action_demo::ActTestGoal)
  (if (not (find-package "ACTION_DEMO"))
    (make-package "ACTION_DEMO"))
  (shadow 'ActTestGoal (find-package "ACTION_DEMO")))
(unless (find-package "ACTION_DEMO::ACTTESTGOAL")
  (make-package "ACTION_DEMO::ACTTESTGOAL"))

(in-package "ROS")
;;//! \htmlinclude ActTestGoal.msg.html


(defclass action_demo::ActTestGoal
  :super ros::object
  :slots (_step_num ))

(defmethod action_demo::ActTestGoal
  (:init
   (&key
    ((:step_num __step_num) 0)
    )
   (send-super :init)
   (setq _step_num (round __step_num))
   self)
  (:step_num
   (&optional __step_num)
   (if __step_num (setq _step_num __step_num)) _step_num)
  (:serialization-length
   ()
   (+
    ;; uint16 _step_num
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _step_num
       (write-word _step_num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _step_num
     (setq _step_num (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get action_demo::ActTestGoal :md5sum-) "9887d69f974ffe6cc0219745fb2fdaf5")
(setf (get action_demo::ActTestGoal :datatype-) "action_demo/ActTestGoal")
(setf (get action_demo::ActTestGoal :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
uint16 step_num

")



(provide :action_demo/ActTestGoal "9887d69f974ffe6cc0219745fb2fdaf5")

