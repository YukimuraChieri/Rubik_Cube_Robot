;; Auto-generated. Do not edit!


(when (boundp 'kociemba_solve::KociembaSolve)
  (if (not (find-package "KOCIEMBA_SOLVE"))
    (make-package "KOCIEMBA_SOLVE"))
  (shadow 'KociembaSolve (find-package "KOCIEMBA_SOLVE")))
(unless (find-package "KOCIEMBA_SOLVE::KOCIEMBASOLVE")
  (make-package "KOCIEMBA_SOLVE::KOCIEMBASOLVE"))
(unless (find-package "KOCIEMBA_SOLVE::KOCIEMBASOLVEREQUEST")
  (make-package "KOCIEMBA_SOLVE::KOCIEMBASOLVEREQUEST"))
(unless (find-package "KOCIEMBA_SOLVE::KOCIEMBASOLVERESPONSE")
  (make-package "KOCIEMBA_SOLVE::KOCIEMBASOLVERESPONSE"))

(in-package "ROS")





(defclass kociemba_solve::KociembaSolveRequest
  :super ros::object
  :slots (_six_face_str ))

(defmethod kociemba_solve::KociembaSolveRequest
  (:init
   (&key
    ((:six_face_str __six_face_str) "")
    )
   (send-super :init)
   (setq _six_face_str (string __six_face_str))
   self)
  (:six_face_str
   (&optional __six_face_str)
   (if __six_face_str (setq _six_face_str __six_face_str)) _six_face_str)
  (:serialization-length
   ()
   (+
    ;; string _six_face_str
    4 (length _six_face_str)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _six_face_str
       (write-long (length _six_face_str) s) (princ _six_face_str s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _six_face_str
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _six_face_str (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass kociemba_solve::KociembaSolveResponse
  :super ros::object
  :slots (_solve_str ))

(defmethod kociemba_solve::KociembaSolveResponse
  (:init
   (&key
    ((:solve_str __solve_str) "")
    )
   (send-super :init)
   (setq _solve_str (string __solve_str))
   self)
  (:solve_str
   (&optional __solve_str)
   (if __solve_str (setq _solve_str __solve_str)) _solve_str)
  (:serialization-length
   ()
   (+
    ;; string _solve_str
    4 (length _solve_str)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _solve_str
       (write-long (length _solve_str) s) (princ _solve_str s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _solve_str
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _solve_str (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass kociemba_solve::KociembaSolve
  :super ros::object
  :slots ())

(setf (get kociemba_solve::KociembaSolve :md5sum-) "2dda5a023a8b634c158eca12da32426c")
(setf (get kociemba_solve::KociembaSolve :datatype-) "kociemba_solve/KociembaSolve")
(setf (get kociemba_solve::KociembaSolve :request) kociemba_solve::KociembaSolveRequest)
(setf (get kociemba_solve::KociembaSolve :response) kociemba_solve::KociembaSolveResponse)

(defmethod kociemba_solve::KociembaSolveRequest
  (:response () (instance kociemba_solve::KociembaSolveResponse :init)))

(setf (get kociemba_solve::KociembaSolveRequest :md5sum-) "2dda5a023a8b634c158eca12da32426c")
(setf (get kociemba_solve::KociembaSolveRequest :datatype-) "kociemba_solve/KociembaSolveRequest")
(setf (get kociemba_solve::KociembaSolveRequest :definition-)
      "string six_face_str
---
string solve_str

")

(setf (get kociemba_solve::KociembaSolveResponse :md5sum-) "2dda5a023a8b634c158eca12da32426c")
(setf (get kociemba_solve::KociembaSolveResponse :datatype-) "kociemba_solve/KociembaSolveResponse")
(setf (get kociemba_solve::KociembaSolveResponse :definition-)
      "string six_face_str
---
string solve_str

")



(provide :kociemba_solve/KociembaSolve "2dda5a023a8b634c158eca12da32426c")


