#include <VirtualWire.h>
#include <string.h>
#include <AFMotor.h>
/*AF_DCMotor mr(3);
AF_DCMotor ml(2);*/


  byte message[VW_MAX_MESSAGE_LEN];
  byte messageLength = VW_MAX_MESSAGE_LEN; 
 
  void setup() 
  {
    Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_setup(2000); 
    vw_set_rx_pin(A0);
    vw_rx_start();pinMode(A1,OUTPUT);
    pinMode(A2,OUTPUT);pinMode(A4,OUTPUT);
    pinMode(A3,OUTPUT);
    pinMode(A5,OUTPUT);
  }
 
  void loop() 
  { 
    //digitalWrite(A3,HIGH);
    String msg="";
    if (vw_get_message(message, &messageLength)) 
    {   
        analogWrite(A1,250);
      
        for (int i = 0; i < messageLength; i++)//printing data recieved from RF transission
        { 
        msg=msg+message[i];
        Serial.print(msg);        
        }        
        /*mr.run(RELEASE);
        ml.run(RELEASE);*/
        
        if(msg=="5")
        { 
          analogWrite(A2,0);analogWrite(A3,0);analogWrite(A5,0);analogWrite(A4,0);
          
          /*mr.run(RELEASE);mr.setSpeed(0);
          ml.run(RELEASE);ml.setSpeed(0);*/
          Serial.println("stop");          
        }
        else
          {
            if(msg=="1")//Forward
            {
              analogWrite(A2,0);analogWrite(A3,255);analogWrite(A4,255);analogWrite(A5,0);
              /*mr.run(FORWARD);
              mr.setSpeed(255);
              ml.run(FORWARD);
              ml.setSpeed(255);*/
              Serial.println("Forward");
            }            
          
            if (msg=="2")//Backward
            {analogWrite(A2,255);analogWrite(A3,0);analogWrite(A4,0);analogWrite(A5,255);
              /*mr.run(BACKWARD);
              mr.setSpeed(255);
              ml.run(BACKWARD);
              ml.setSpeed(255);*/
              Serial.println("Backward");
            }
          
            if (msg=="4")//Left 
            {analogWrite(A2,0);analogWrite(A3,255);analogWrite(A4,0);analogWrite(A5,0);
              /*mr.run(RELEASE);
              mr.setSpeed(120);
              ml.run(FORWARD);
              ml.setSpeed(255);*/
              Serial.println("Left");
            }
          
            if (msg=="3")//Right 
            {analogWrite(A2,0);analogWrite(A3,0);analogWrite(A4,255);analogWrite(A5,0);
              /*mr.run(FORWARD);
              mr.setSpeed(255);
              ml.run(RELEASE);
              mr.setSpeed(130);*/
              Serial.println("Right");
            }
          }
          //Serial.println();   
                
        }
        else
        {
          analogWrite(A1,0);
        }
       
      }
     

      
  
