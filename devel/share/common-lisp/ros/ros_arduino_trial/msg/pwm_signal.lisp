; Auto-generated. Do not edit!


(cl:in-package ros_arduino_trial-msg)


;//! \htmlinclude pwm_signal.msg.html

(cl:defclass <pwm_signal> (roslisp-msg-protocol:ros-message)
  ((dir
    :reader dir
    :initarg :dir
    :type cl:boolean
    :initform cl:nil)
   (data
    :reader data
    :initarg :data
    :type cl:fixnum
    :initform 0))
)

(cl:defclass pwm_signal (<pwm_signal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pwm_signal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pwm_signal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_arduino_trial-msg:<pwm_signal> is deprecated: use ros_arduino_trial-msg:pwm_signal instead.")))

(cl:ensure-generic-function 'dir-val :lambda-list '(m))
(cl:defmethod dir-val ((m <pwm_signal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_arduino_trial-msg:dir-val is deprecated.  Use ros_arduino_trial-msg:dir instead.")
  (dir m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <pwm_signal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_arduino_trial-msg:data-val is deprecated.  Use ros_arduino_trial-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pwm_signal>) ostream)
  "Serializes a message object of type '<pwm_signal>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'dir) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'data)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'data)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pwm_signal>) istream)
  "Deserializes a message object of type '<pwm_signal>"
    (cl:setf (cl:slot-value msg 'dir) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'data)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'data)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pwm_signal>)))
  "Returns string type for a message object of type '<pwm_signal>"
  "ros_arduino_trial/pwm_signal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pwm_signal)))
  "Returns string type for a message object of type 'pwm_signal"
  "ros_arduino_trial/pwm_signal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pwm_signal>)))
  "Returns md5sum for a message object of type '<pwm_signal>"
  "a874b178257f5432b765c0462992b150")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pwm_signal)))
  "Returns md5sum for a message object of type 'pwm_signal"
  "a874b178257f5432b765c0462992b150")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pwm_signal>)))
  "Returns full string definition for message of type '<pwm_signal>"
  (cl:format cl:nil "#This is the message file for generating a custom message to control a DC~%#motor using MD10C R3 motor driver by Cytron technologies in Sign Magnitude ~%#mode.~%bool dir~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pwm_signal)))
  "Returns full string definition for message of type 'pwm_signal"
  (cl:format cl:nil "#This is the message file for generating a custom message to control a DC~%#motor using MD10C R3 motor driver by Cytron technologies in Sign Magnitude ~%#mode.~%bool dir~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pwm_signal>))
  (cl:+ 0
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pwm_signal>))
  "Converts a ROS message object to a list"
  (cl:list 'pwm_signal
    (cl:cons ':dir (dir msg))
    (cl:cons ':data (data msg))
))
