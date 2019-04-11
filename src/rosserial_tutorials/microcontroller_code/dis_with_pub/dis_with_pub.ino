#include<ros.h>
#include<std_msgs/UInt16.h>
#include<std_msgs/Float32.h>
#include<std_msgs/String.h>

//#include <iostream> 
//#include <string>

#define dirPin 7
#define stepperPin 8

float dis_per_turn = 3.0;
//float nums_turns = 0;

ros::NodeHandle nh;
//std_msgs::String str_msg;
std_msgs::Float32 str_msg;
ros::Publisher chatter("listener", &str_msg);

char temp[] = "Test message!";

void dis_cb(const std_msgs::Float32& dis_msg){
  nh.loginfo("subscribe xxxxxxxx");
  execute_motor(dis_msg.data);
}

ros::Subscriber<std_msgs::Float32> sub("dis_signal", dis_cb);

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepperPin, OUTPUT);

  Serial.begin(57600);
  
  nh.initNode();

  nh.advertise(chatter);
  
}

void loop() {
    nh.subscribe(sub);
/*
  nh.subscribe(sub);
  str_msg.data = nums_turns;
  chatter.publish( &str_msg );
  
  if (nums_turns != 0) {
    execute_motor(nums_turns);
    //str_msg.data = "Done";
    chatter.publish( &str_msg );
    nums_turns = 0;
    }
  else {
  //str_msg.data = temp;
  //chatter.publish( &str_msg );
  }*/

  delay(2);
  nh.spinOnce();
  delay(1);  

}

void execute_motor(int distance) {
  float nums_turns = distance / dis_per_turn;
  digitalWrite(dirPin,HIGH);
  for (int x = 0;x < 200 * nums_turns; x++){
    digitalWrite(stepperPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepperPin,LOW);
    delayMicroseconds(500);
    }
  //delay(1000);
  }
  
/*

void execute_motor(int distance) {
  float nums_turns = distance / dis_per_turn;
  for (int x = 0; x < nums_turns; x++){
    execute_one_circle();
    } 
  }

void execute_one_circle() {
  digitalWrite(dirPin,HIGH);
  for (int x=0;x<200;x++){
    digitalWrite(stepperPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepperPin,LOW);
    delayMicroseconds(500);
    }
  delay(1000);
  }*/
