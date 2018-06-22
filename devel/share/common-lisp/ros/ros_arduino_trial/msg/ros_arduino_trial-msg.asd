
(cl:in-package :asdf)

(defsystem "ros_arduino_trial-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "pwm_signal" :depends-on ("_package_pwm_signal"))
    (:file "_package_pwm_signal" :depends-on ("_package"))
  ))