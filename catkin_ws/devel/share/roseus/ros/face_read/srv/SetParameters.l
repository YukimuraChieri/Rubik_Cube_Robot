;; Auto-generated. Do not edit!


(when (boundp 'face_read::SetParameters)
  (if (not (find-package "FACE_READ"))
    (make-package "FACE_READ"))
  (shadow 'SetParameters (find-package "FACE_READ")))
(unless (find-package "FACE_READ::SETPARAMETERS")
  (make-package "FACE_READ::SETPARAMETERS"))
(unless (find-package "FACE_READ::SETPARAMETERSREQUEST")
  (make-package "FACE_READ::SETPARAMETERSREQUEST"))
(unless (find-package "FACE_READ::SETPARAMETERSRESPONSE")
  (make-package "FACE_READ::SETPARAMETERSRESPONSE"))

(in-package "ROS")





(defclass face_read::SetParametersRequest
  :super ros::object
  :slots (_paras ))

(defmethod face_read::SetParametersRequest
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

(defclass face_read::SetParametersResponse
  :super ros::object
  :slots (_feedback ))

(defmethod face_read::SetParametersResponse
  (:init
   (&key
    ((:feedback __feedback) "")
    )
   (send-super :init)
   (setq _feedback (string __feedback))
   self)
  (:feedback
   (&optional __feedback)
   (if __feedback (setq _feedback __feedback)) _feedback)
  (:serialization-length
   ()
   (+
    ;; string _feedback
    4 (length _feedback)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _feedback
       (write-long (length _feedback) s) (princ _feedback s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _feedback
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _feedback (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass face_read::SetParameters
  :super ros::object
  :slots ())

(setf (get face_read::SetParameters :md5sum-) "771cbc2cb2ba5e0bedf422ca8d884dac")
(setf (get face_read::SetParameters :datatype-) "face_read/SetParameters")
(setf (get face_read::SetParameters :request) face_read::SetParametersRequest)
(setf (get face_read::SetParameters :response) face_read::SetParametersResponse)

(defmethod face_read::SetParametersRequest
  (:response () (instance face_read::SetParametersResponse :init)))

(setf (get face_read::SetParametersRequest :md5sum-) "771cbc2cb2ba5e0bedf422ca8d884dac")
(setf (get face_read::SetParametersRequest :datatype-) "face_read/SetParametersRequest")
(setf (get face_read::SetParametersRequest :definition-)
      "string paras
---
string feedback

")

(setf (get face_read::SetParametersResponse :md5sum-) "771cbc2cb2ba5e0bedf422ca8d884dac")
(setf (get face_read::SetParametersResponse :datatype-) "face_read/SetParametersResponse")
(setf (get face_read::SetParametersResponse :definition-)
      "string paras
---
string feedback

")



(provide :face_read/SetParameters "771cbc2cb2ba5e0bedf422ca8d884dac")


