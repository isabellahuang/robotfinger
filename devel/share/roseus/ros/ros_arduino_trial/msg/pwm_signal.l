;; Auto-generated. Do not edit!


(when (boundp 'ros_arduino_trial::pwm_signal)
  (if (not (find-package "ROS_ARDUINO_TRIAL"))
    (make-package "ROS_ARDUINO_TRIAL"))
  (shadow 'pwm_signal (find-package "ROS_ARDUINO_TRIAL")))
(unless (find-package "ROS_ARDUINO_TRIAL::PWM_SIGNAL")
  (make-package "ROS_ARDUINO_TRIAL::PWM_SIGNAL"))

(in-package "ROS")
;;//! \htmlinclude pwm_signal.msg.html


(defclass ros_arduino_trial::pwm_signal
  :super ros::object
  :slots (_dir _data ))

(defmethod ros_arduino_trial::pwm_signal
  (:init
   (&key
    ((:dir __dir) nil)
    ((:data __data) 0)
    )
   (send-super :init)
   (setq _dir __dir)
   (setq _data (round __data))
   self)
  (:dir
   (&optional __dir)
   (if __dir (setq _dir __dir)) _dir)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; bool _dir
    1
    ;; uint16 _data
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _dir
       (if _dir (write-byte -1 s) (write-byte 0 s))
     ;; uint16 _data
       (write-word _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _dir
     (setq _dir (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint16 _data
     (setq _data (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get ros_arduino_trial::pwm_signal :md5sum-) "a874b178257f5432b765c0462992b150")
(setf (get ros_arduino_trial::pwm_signal :datatype-) "ros_arduino_trial/pwm_signal")
(setf (get ros_arduino_trial::pwm_signal :definition-)
      "#This is the message file for generating a custom message to control a DC
#motor using MD10C R3 motor driver by Cytron technologies in Sign Magnitude 
#mode.
bool dir
uint16 data

")



(provide :ros_arduino_trial/pwm_signal "a874b178257f5432b765c0462992b150")


