;; Auto-generated. Do not edit!


(when (boundp 'action_demo::ActTestResult)
  (if (not (find-package "ACTION_DEMO"))
    (make-package "ACTION_DEMO"))
  (shadow 'ActTestResult (find-package "ACTION_DEMO")))
(unless (find-package "ACTION_DEMO::ACTTESTRESULT")
  (make-package "ACTION_DEMO::ACTTESTRESULT"))

(in-package "ROS")
;;//! \htmlinclude ActTestResult.msg.html


(defclass action_demo::ActTestResult
  :super ros::object
  :slots (_result ))

(defmethod action_demo::ActTestResult
  (:init
   (&key
    ((:result __result) "")
    )
   (send-super :init)
   (setq _result (string __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get action_demo::ActTestResult :md5sum-) "c22f2a1ed8654a0b365f1bb3f7ff2c0f")
(setf (get action_demo::ActTestResult :datatype-) "action_demo/ActTestResult")
(setf (get action_demo::ActTestResult :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
string result

")



(provide :action_demo/ActTestResult "c22f2a1ed8654a0b365f1bb3f7ff2c0f")

