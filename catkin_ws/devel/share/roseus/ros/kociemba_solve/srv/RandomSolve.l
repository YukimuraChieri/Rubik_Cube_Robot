;; Auto-generated. Do not edit!


(when (boundp 'kociemba_solve::RandomSolve)
  (if (not (find-package "KOCIEMBA_SOLVE"))
    (make-package "KOCIEMBA_SOLVE"))
  (shadow 'RandomSolve (find-package "KOCIEMBA_SOLVE")))
(unless (find-package "KOCIEMBA_SOLVE::RANDOMSOLVE")
  (make-package "KOCIEMBA_SOLVE::RANDOMSOLVE"))
(unless (find-package "KOCIEMBA_SOLVE::RANDOMSOLVEREQUEST")
  (make-package "KOCIEMBA_SOLVE::RANDOMSOLVEREQUEST"))
(unless (find-package "KOCIEMBA_SOLVE::RANDOMSOLVERESPONSE")
  (make-package "KOCIEMBA_SOLVE::RANDOMSOLVERESPONSE"))

(in-package "ROS")





(defclass kociemba_solve::RandomSolveRequest
  :super ros::object
  :slots (_step_num ))

(defmethod kociemba_solve::RandomSolveRequest
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
    ;; int16 _step_num
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _step_num
       (write-word _step_num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _step_num
     (setq _step_num (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass kociemba_solve::RandomSolveResponse
  :super ros::object
  :slots (_random_str ))

(defmethod kociemba_solve::RandomSolveResponse
  (:init
   (&key
    ((:random_str __random_str) "")
    )
   (send-super :init)
   (setq _random_str (string __random_str))
   self)
  (:random_str
   (&optional __random_str)
   (if __random_str (setq _random_str __random_str)) _random_str)
  (:serialization-length
   ()
   (+
    ;; string _random_str
    4 (length _random_str)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _random_str
       (write-long (length _random_str) s) (princ _random_str s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _random_str
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _random_str (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass kociemba_solve::RandomSolve
  :super ros::object
  :slots ())

(setf (get kociemba_solve::RandomSolve :md5sum-) "1e50375af0a44d22e32e9a1b65fd9076")
(setf (get kociemba_solve::RandomSolve :datatype-) "kociemba_solve/RandomSolve")
(setf (get kociemba_solve::RandomSolve :request) kociemba_solve::RandomSolveRequest)
(setf (get kociemba_solve::RandomSolve :response) kociemba_solve::RandomSolveResponse)

(defmethod kociemba_solve::RandomSolveRequest
  (:response () (instance kociemba_solve::RandomSolveResponse :init)))

(setf (get kociemba_solve::RandomSolveRequest :md5sum-) "1e50375af0a44d22e32e9a1b65fd9076")
(setf (get kociemba_solve::RandomSolveRequest :datatype-) "kociemba_solve/RandomSolveRequest")
(setf (get kociemba_solve::RandomSolveRequest :definition-)
      "int16 step_num
---
string random_str

")

(setf (get kociemba_solve::RandomSolveResponse :md5sum-) "1e50375af0a44d22e32e9a1b65fd9076")
(setf (get kociemba_solve::RandomSolveResponse :datatype-) "kociemba_solve/RandomSolveResponse")
(setf (get kociemba_solve::RandomSolveResponse :definition-)
      "int16 step_num
---
string random_str

")



(provide :kociemba_solve/RandomSolve "1e50375af0a44d22e32e9a1b65fd9076")


