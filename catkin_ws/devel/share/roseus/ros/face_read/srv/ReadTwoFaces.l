;; Auto-generated. Do not edit!


(when (boundp 'face_read::ReadTwoFaces)
  (if (not (find-package "FACE_READ"))
    (make-package "FACE_READ"))
  (shadow 'ReadTwoFaces (find-package "FACE_READ")))
(unless (find-package "FACE_READ::READTWOFACES")
  (make-package "FACE_READ::READTWOFACES"))
(unless (find-package "FACE_READ::READTWOFACESREQUEST")
  (make-package "FACE_READ::READTWOFACESREQUEST"))
(unless (find-package "FACE_READ::READTWOFACESRESPONSE")
  (make-package "FACE_READ::READTWOFACESRESPONSE"))

(in-package "ROS")





(defclass face_read::ReadTwoFacesRequest
  :super ros::object
  :slots (_side ))

(defmethod face_read::ReadTwoFacesRequest
  (:init
   (&key
    ((:side __side) "")
    )
   (send-super :init)
   (setq _side (string __side))
   self)
  (:side
   (&optional __side)
   (if __side (setq _side __side)) _side)
  (:serialization-length
   ()
   (+
    ;; string _side
    4 (length _side)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _side
       (write-long (length _side) s) (princ _side s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _side
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _side (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass face_read::ReadTwoFacesResponse
  :super ros::object
  :slots (_face_1 _face_2 ))

(defmethod face_read::ReadTwoFacesResponse
  (:init
   (&key
    ((:face_1 __face_1) "")
    ((:face_2 __face_2) "")
    )
   (send-super :init)
   (setq _face_1 (string __face_1))
   (setq _face_2 (string __face_2))
   self)
  (:face_1
   (&optional __face_1)
   (if __face_1 (setq _face_1 __face_1)) _face_1)
  (:face_2
   (&optional __face_2)
   (if __face_2 (setq _face_2 __face_2)) _face_2)
  (:serialization-length
   ()
   (+
    ;; string _face_1
    4 (length _face_1)
    ;; string _face_2
    4 (length _face_2)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _face_1
       (write-long (length _face_1) s) (princ _face_1 s)
     ;; string _face_2
       (write-long (length _face_2) s) (princ _face_2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _face_1
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _face_1 (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _face_2
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _face_2 (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass face_read::ReadTwoFaces
  :super ros::object
  :slots ())

(setf (get face_read::ReadTwoFaces :md5sum-) "3c14a0fe7db327aef6da537797c5908f")
(setf (get face_read::ReadTwoFaces :datatype-) "face_read/ReadTwoFaces")
(setf (get face_read::ReadTwoFaces :request) face_read::ReadTwoFacesRequest)
(setf (get face_read::ReadTwoFaces :response) face_read::ReadTwoFacesResponse)

(defmethod face_read::ReadTwoFacesRequest
  (:response () (instance face_read::ReadTwoFacesResponse :init)))

(setf (get face_read::ReadTwoFacesRequest :md5sum-) "3c14a0fe7db327aef6da537797c5908f")
(setf (get face_read::ReadTwoFacesRequest :datatype-) "face_read/ReadTwoFacesRequest")
(setf (get face_read::ReadTwoFacesRequest :definition-)
      "string side
---
string face_1
string face_2


")

(setf (get face_read::ReadTwoFacesResponse :md5sum-) "3c14a0fe7db327aef6da537797c5908f")
(setf (get face_read::ReadTwoFacesResponse :datatype-) "face_read/ReadTwoFacesResponse")
(setf (get face_read::ReadTwoFacesResponse :definition-)
      "string side
---
string face_1
string face_2


")



(provide :face_read/ReadTwoFaces "3c14a0fe7db327aef6da537797c5908f")


