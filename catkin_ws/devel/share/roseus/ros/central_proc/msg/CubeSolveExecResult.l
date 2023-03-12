;; Auto-generated. Do not edit!


(when (boundp 'central_proc::CubeSolveExecResult)
  (if (not (find-package "CENTRAL_PROC"))
    (make-package "CENTRAL_PROC"))
  (shadow 'CubeSolveExecResult (find-package "CENTRAL_PROC")))
(unless (find-package "CENTRAL_PROC::CUBESOLVEEXECRESULT")
  (make-package "CENTRAL_PROC::CUBESOLVEEXECRESULT"))

(in-package "ROS")
;;//! \htmlinclude CubeSolveExecResult.msg.html


(defclass central_proc::CubeSolveExecResult
  :super ros::object
  :slots (_result ))

(defmethod central_proc::CubeSolveExecResult
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

(setf (get central_proc::CubeSolveExecResult :md5sum-) "c22f2a1ed8654a0b365f1bb3f7ff2c0f")
(setf (get central_proc::CubeSolveExecResult :datatype-) "central_proc/CubeSolveExecResult")
(setf (get central_proc::CubeSolveExecResult :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
# Define the result
# 定义结果信息
string result

")



(provide :central_proc/CubeSolveExecResult "c22f2a1ed8654a0b365f1bb3f7ff2c0f")

