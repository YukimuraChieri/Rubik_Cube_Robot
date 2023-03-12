
(cl:in-package :asdf)

(defsystem "face_read-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "GetParameters" :depends-on ("_package_GetParameters"))
    (:file "_package_GetParameters" :depends-on ("_package"))
    (:file "ReadTwoFaces" :depends-on ("_package_ReadTwoFaces"))
    (:file "_package_ReadTwoFaces" :depends-on ("_package"))
    (:file "SetParameters" :depends-on ("_package_SetParameters"))
    (:file "_package_SetParameters" :depends-on ("_package"))
  ))