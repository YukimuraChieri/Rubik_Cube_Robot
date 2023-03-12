;; Auto-generated. Do not edit!


(when (boundp 'stm32_serial::Control)
  (if (not (find-package "STM32_SERIAL"))
    (make-package "STM32_SERIAL"))
  (shadow 'Control (find-package "STM32_SERIAL")))
(unless (find-package "STM32_SERIAL::CONTROL")
  (make-package "STM32_SERIAL::CONTROL"))
(unless (find-package "STM32_SERIAL::CONTROLREQUEST")
  (make-package "STM32_SERIAL::CONTROLREQUEST"))
(unless (find-package "STM32_SERIAL::CONTROLRESPONSE")
  (make-package "STM32_SERIAL::CONTROLRESPONSE"))

(in-package "ROS")





(defclass stm32_serial::ControlRequest
  :super ros::object
  :slots (_command ))

(defmethod stm32_serial::ControlRequest
  (:init
   (&key
    ((:command __command) "")
    )
   (send-super :init)
   (setq _command (string __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; string _command
    4 (length _command)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _command
       (write-long (length _command) s) (princ _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _command
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _command (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass stm32_serial::ControlResponse
  :super ros::object
  :slots (_feedback ))

(defmethod stm32_serial::ControlResponse
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

(defclass stm32_serial::Control
  :super ros::object
  :slots ())

(setf (get stm32_serial::Control :md5sum-) "f1c376525e7fd3f183aa1122ff9108b1")
(setf (get stm32_serial::Control :datatype-) "stm32_serial/Control")
(setf (get stm32_serial::Control :request) stm32_serial::ControlRequest)
(setf (get stm32_serial::Control :response) stm32_serial::ControlResponse)

(defmethod stm32_serial::ControlRequest
  (:response () (instance stm32_serial::ControlResponse :init)))

(setf (get stm32_serial::ControlRequest :md5sum-) "f1c376525e7fd3f183aa1122ff9108b1")
(setf (get stm32_serial::ControlRequest :datatype-) "stm32_serial/ControlRequest")
(setf (get stm32_serial::ControlRequest :definition-)
      "string command
---
string feedback


")

(setf (get stm32_serial::ControlResponse :md5sum-) "f1c376525e7fd3f183aa1122ff9108b1")
(setf (get stm32_serial::ControlResponse :datatype-) "stm32_serial/ControlResponse")
(setf (get stm32_serial::ControlResponse :definition-)
      "string command
---
string feedback


")



(provide :stm32_serial/Control "f1c376525e7fd3f183aa1122ff9108b1")


