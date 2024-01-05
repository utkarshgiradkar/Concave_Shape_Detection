int ena = 3;//ena for left enb for right
int enb = 9;
int in1 = 4;//1 and 2 are for left 
int in2 = 5;
int in3 = 6;//3 and 4 are for right
int in4 = 7;
int trig_back = 8;
int echo_back = 2;
int trig_front = 10;
int echo_front = 11;
int trig_right = 12;
int echo_right = 13;

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT);  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  pinMode(8,OUTPUT);
  pinMode(2,INPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(3000);
}

long rightDistance(){
  digitalWrite(trig_right,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_right,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_right,LOW);
  long duration = pulseIn(echo_right,HIGH);
  return duration*0.017;
}


long frontDistance(){
  digitalWrite(trig_front,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_front,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_front,LOW);
  long duration = pulseIn(echo_front,HIGH);
  return duration*0.017;
}

long backDistance(){
  digitalWrite(trig_back,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_back,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_back,LOW);
  long duration = pulseIn(echo_back,HIGH);
  return duration*0.017;
}


void turn_left(){
  analogWrite(enb,200);
  analogWrite(ena,200);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void turn_right(){
  analogWrite(ena,255);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void walk_straight(){
  analogWrite(enb,235);
  analogWrite(ena,235);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);  
}

void turn_left_while_moving(){
  analogWrite(enb,155);
  analogWrite(ena,140);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);   
}

void turn_right_while_moving(){
  analogWrite(enb,140);
  analogWrite(ena,155);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);   
}

void loop() {
  long front_distance=frontDistance();
  long right_distance=rightDistance();
  long back_distance=backDistance();
  bool x = true;
  bool y = true;
  
  if(10<right_distance<20 && front_distance>15){
    walk_straight();
    Serial.print("CASE 1");
  }
  if(front_distance<15 && 5<right_distance<25){
    while (x==true){
      turn_left();
      front_distance=frontDistance();
      back_distance=backDistance();
      right_distance=rightDistance();
      if (-1.1<right_distance-back_distance<1.1 && front_distance>40){
        x=false;
      }
    }
  }
  if(20>right_distance-back_distance>12 && front_distance>30){
    while (y==true){
      turn_right();
      front_distance=frontDistance();
      back_distance=backDistance();
      right_distance=rightDistance();
      if (-1.1<right_distance-back_distance<1.1 && front_distance>40){
        y =false;
      } 
    } 
  }

  # This is sample code 
  /*if(right_distance<back_distance){
    turn_left_while_moving();
    delay(500);
    walk_straight();
    right_distance=rightDistance();
    back_distance=backDistance();
  }*/
    /*while (true){
      turn_left_while_moving();
      right_distance=rightDistance();
      back_distance=backDistance(); 
      if (-1<right_distance-back_distance<1){
        break;     
      }
    }
  }*/
  /*if(right_distance>back_distance){
    
    turn_right_while_moving();
    delay(500);
    walk_straight();
    right_distance=rightDistance();
    back_distance=backDistance();     
  }*/
/*    while (true){
      turn_right_while_moving();
      right_distance=rightDistance();
      back_distance=backDistance(); 
      if (-1<right_distance-back_distance<1){
        break;     
      }
    }
  }*/
  /*if(right_distance<10){
      while (right_distance<10){
      turn_left_while_moving();
      right_distance=rightDistance();
    }    
  }
  if(right_distance>20){
    while (right_distance>20){
      turn_right_while_moving();
      right_distance=rightDistance();
    }    
  }*/
}