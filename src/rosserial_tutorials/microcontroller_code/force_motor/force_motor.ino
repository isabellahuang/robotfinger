#include "HX711.h"

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

HX711 scale(5, 6);
#define dirPin 7
#define stepperPin 8

float dis_per_turn = 3.0;

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;

std_msgs::Float32 str_msg;
ros::Publisher forcesensor("forcesensor", &str_msg);

float calibration_factor = 222; // this calibration factor is adjusted according to my load cell
float units;
float ounces;

void dis_cb(const std_msgs::Float32& dis_msg){
  nh.loginfo("Moving");
  execute_motor(dis_msg.data);
}

// Should this be moved to the setup() function?
ros::Subscriber<std_msgs::Float32> sub("dis_signal", dis_cb);

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepperPin, OUTPUT);

  nh.initNode();
  nh.advertise(forcesensor);
  nh.subscribe(sub);
  
  Serial.begin(57600);
  force_setup_output();
}

void loop() {
  //nh.subscribe(sub); 

  str_msg.data = real_force();
  forcesensor.publish( &str_msg );
  nh.spinOnce();

  force_loop_output();                                                                                   

  // Or any of this?
 //scale.power_down();              
  delay(100);
  //scale.power_up();
}

/* Force sensor monitor. */

void force_setup_output() {
  Serial.println("HX711 calibration sketch");                                                                                
  Serial.println("Remove all weight from scale");                                                                                                                                                                                                                  
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  scale.set_scale();
  scale.tare();  //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
  }

  
void force_loop_output() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print("Reading: ");
  units = scale.get_units(), 10;
  if (units < 0)
  {
    units = 0.00;
  }
  ounces = units * 0.035274;
  Serial.print(units);
  Serial.print(" grams"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 1;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 1;
  }
 }

float real_force() {
  scale.set_scale(calibration_factor);
  units = scale.get_units(), 10;
  if (units < 0)
  {
    units = 0.00;
  }
  return units;
}
  
//Motor/
  void execute_motor(float distance) {
  if (distance < 0) {
    digitalWrite(dirPin,LOW);
    distance = -distance;
    } else {
      digitalWrite(dirPin,HIGH);
     }
  float nums_turns = distance / dis_per_turn;
  for (int x = 0;x < 200 * nums_turns; x++){
    digitalWrite(stepperPin,HIGH);
//    delayMicroseconds(500);/
    digitalWrite(stepperPin,LOW);
//    delayMicroseconds(500);/
    }
  }
  
