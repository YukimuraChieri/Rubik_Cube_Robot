
(cl:in-package :asdf)

(defsystem "action_demo-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ActTestAction" :depends-on ("_package_ActTestAction"))
    (:file "_package_ActTestAction" :depends-on ("_package"))
    (:file "ActTestActionFeedback" :depends-on ("_package_ActTestActionFeedback"))
    (:file "_package_ActTestActionFeedback" :depends-on ("_package"))
    (:file "ActTestActionGoal" :depends-on ("_package_ActTestActionGoal"))
    (:file "_package_ActTestActionGoal" :depends-on ("_package"))
    (:file "ActTestActionResult" :depends-on ("_package_ActTestActionResult"))
    (:file "_package_ActTestActionResult" :depends-on ("_package"))
    (:file "ActTestFeedback" :depends-on ("_package_ActTestFeedback"))
    (:file "_package_ActTestFeedback" :depends-on ("_package"))
    (:file "ActTestGoal" :depends-on ("_package_ActTestGoal"))
    (:file "_package_ActTestGoal" :depends-on ("_package"))
    (:file "ActTestResult" :depends-on ("_package_ActTestResult"))
    (:file "_package_ActTestResult" :depends-on ("_package"))
  ))