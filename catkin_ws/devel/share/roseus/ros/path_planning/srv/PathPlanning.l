;; Auto-generated. Do not edit!


(when (boundp 'path_planning::PathPlanning)
  (if (not (find-package "PATH_PLANNING"))
    (make-package "PATH_PLANNING"))
  (shadow 'PathPlanning (find-package "PATH_PLANNING")))
(unless (find-package "PATH_PLANNING::PATHPLANNING")
  (make-package "PATH_PLANNING::PATHPLANNING"))
(unless (find-package "PATH_PLANNING::PATHPLANNINGREQUEST")
  (make-package "PATH_PLANNING::PATHPLANNINGREQUEST"))
(unless (find-package "PATH_PLANNING::PATHPLANNINGRESPONSE")
  (make-package "PATH_PLANNING::PATHPLANNINGRESPONSE"))

(in-package "ROS")





(defclass path_planning::PathPlanningRequest
  :super ros::object
  :slots (_solve_str _hand_axis ))

(defmethod path_planning::PathPlanningRequest
  (:init
   (&key
    ((:solve_str __solve_str) "")
    ((:hand_axis __hand_axis) "")
    )
   (send-super :init)
   (setq _solve_str (string __solve_str))
   (setq _hand_axis (string __hand_axis))
   self)
  (:solve_str
   (&optional __solve_str)
   (if __solve_str (setq _solve_str __solve_str)) _solve_str)
  (:hand_axis
   (&optional __hand_axis)
   (if __hand_axis (setq _hand_axis __hand_axis)) _hand_axis)
  (:serialization-length
   ()
   (+
    ;; string _solve_str
    4 (length _solve_str)
    ;; string _hand_axis
    4 (length _hand_axis)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _solve_str
       (write-long (length _solve_str) s) (princ _solve_str s)
     ;; string _hand_axis
       (write-long (length _hand_axis) s) (princ _hand_axis s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _solve_str
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _solve_str (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _hand_axis
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _hand_axis (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass path_planning::PathPlanningResponse
  :super ros::object
  :slots (_result ))

(defmethod path_planning::PathPlanningResponse
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

(defclass path_planning::PathPlanning
  :super ros::object
  :slots ())

(setf (get path_planning::PathPlanning :md5sum-) "1eee7119fb9bc2458d0167605d08766d")
(setf (get path_planning::PathPlanning :datatype-) "path_planning/PathPlanning")
(setf (get path_planning::PathPlanning :request) path_planning::PathPlanningRequest)
(setf (get path_planning::PathPlanning :response) path_planning::PathPlanningResponse)

(defmethod path_planning::PathPlanningRequest
  (:response () (instance path_planning::PathPlanningResponse :init)))

(setf (get path_planning::PathPlanningRequest :md5sum-) "1eee7119fb9bc2458d0167605d08766d")
(setf (get path_planning::PathPlanningRequest :datatype-) "path_planning/PathPlanningRequest")
(setf (get path_planning::PathPlanningRequest :definition-)
      "string solve_str
string hand_axis
---
string result

")

(setf (get path_planning::PathPlanningResponse :md5sum-) "1eee7119fb9bc2458d0167605d08766d")
(setf (get path_planning::PathPlanningResponse :datatype-) "path_planning/PathPlanningResponse")
(setf (get path_planning::PathPlanningResponse :definition-)
      "string solve_str
string hand_axis
---
string result

")



(provide :path_planning/PathPlanning "1eee7119fb9bc2458d0167605d08766d")


