;; Auto-generated. Do not edit!


(when (boundp 'face_read::GetParameters)
  (if (not (find-package "FACE_READ"))
    (make-package "FACE_READ"))
  (shadow 'GetParameters (find-package "FACE_READ")))
(unless (find-package "FACE_READ::GETPARAMETERS")
  (make-package "FACE_READ::GETPARAMETERS"))
(unless (find-package "FACE_READ::GETPARAMETERSREQUEST")
  (make-package "FACE_READ::GETPARAMETERSREQUEST"))
(unless (find-package "FACE_READ::GETPARAMETERSRESPONSE")
  (make-package "FACE_READ::GETPARAMETERSRESPONSE"))

(in-package "ROS")





(defclass face_read::GetParametersRequest
  :super ros::object
  :slots ())

(defmethod face_read::GetParametersRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass face_read::GetParametersResponse
  :super ros::object
  :slots (_paras ))

(defmethod face_read::GetParametersResponse
  (:init
   (&key
    ((:paras __paras) "")
    )
   (send-super :init)
   (setq _paras (string __paras))
   self)
  (:paras
   (&optional __paras)
   (if __paras (setq _paras __paras)) _paras)
  (:serialization-length
   ()
   (+
    ;; string _paras
    4 (length _paras)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _paras
       (write-long (length _paras) s) (princ _paras s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _paras
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _paras (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass face_read::GetParameters
  :super ros::object
  :slots ())

(setf (get face_read::GetParameters :md5sum-) "6485c21672e59e8ec1ecffa78b8b97fc")
(setf (get face_read::GetParameters :datatype-) "face_read/GetParameters")
(setf (get face_read::GetParameters :request) face_read::GetParametersRequest)
(setf (get face_read::GetParameters :response) face_read::GetParametersResponse)

(defmethod face_read::GetParametersRequest
  (:response () (instance face_read::GetParametersResponse :init)))

(setf (get face_read::GetParametersRequest :md5sum-) "6485c21672e59e8ec1ecffa78b8b97fc")
(setf (get face_read::GetParametersRequest :datatype-) "face_read/GetParametersRequest")
(setf (get face_read::GetParametersRequest :definition-)
      "
---
string paras

")

(setf (get face_read::GetParametersResponse :md5sum-) "6485c21672e59e8ec1ecffa78b8b97fc")
(setf (get face_read::GetParametersResponse :datatype-) "face_read/GetParametersResponse")
(setf (get face_read::GetParametersResponse :definition-)
      "
---
string paras

")



(provide :face_read/GetParameters "6485c21672e59e8ec1ecffa78b8b97fc")


