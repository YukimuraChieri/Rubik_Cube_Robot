
(cl:in-package :asdf)

(defsystem "kociemba_solve-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "KociembaSolve" :depends-on ("_package_KociembaSolve"))
    (:file "_package_KociembaSolve" :depends-on ("_package"))
    (:file "RandomSolve" :depends-on ("_package_RandomSolve"))
    (:file "_package_RandomSolve" :depends-on ("_package"))
  ))