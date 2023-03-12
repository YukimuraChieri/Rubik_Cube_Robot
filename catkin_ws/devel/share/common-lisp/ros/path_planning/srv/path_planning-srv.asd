
(cl:in-package :asdf)

(defsystem "path_planning-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "PathPlanning" :depends-on ("_package_PathPlanning"))
    (:file "_package_PathPlanning" :depends-on ("_package"))
  ))