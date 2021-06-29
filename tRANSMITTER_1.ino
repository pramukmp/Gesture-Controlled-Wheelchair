//If you don't want to use pin 12 use vw_set_tx_pin(transmit_pin), with transmit_pin being desired pin ,in void setup

#include <VirtualWire.h>

int xPin=A0;
int yPin=A1;
char data[5];

void setup() 
{
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_setup(2000);  
  vw_set_tx_pin(7);
  analogReference(DEFAULT);//optional,not needed
}

void loop() 
{
  int xval,yval;
  
  xval=analogRead(xPin);
  yval=analogRead(yPin);  
   
  int s=50,f=10,b=20,r=30,l=40,d=99;
  
  Serial.print("xval=");
  Serial.println(xval);
  
  Serial.print("yval=");
  Serial.println(yval);
  delay(100);


  /*changeC(d,data); //used to display values after 1s delay
  vw_send((uint8_t*)data,1);*/
  Serial.print("\n");
  
  if ((xval>=320 && xval<=340) &&  (yval>=320 && yval<=350)) //stationary or stop(transmitter parallel to ground)
  {
    changeC(s,data);
    vw_send((uint8_t*)data,1);
    Serial.print("Stop");
  }
  else 
  { 
    if ((xval>=315 && xval<=340) && (yval>=355 && yval<=385)) //forward(transmitter tilted forward
    {
      
      changeC(f,data);
     vw_send((uint8_t*)data,1);Serial.print("Forward");
     //digitalWrite(ledPin,HIGH);
      
    }
    if ((xval>=315 && xval<338) && (yval>=275 && yval<=305)) //backward(transmitter tilted backward)
    {
      //digitalWrite(ledPin,HIGH);
      changeC(b,data);Serial.print("Backward");
      vw_send((uint8_t*)data,1);
      
    }
    if ((xval>=270 && xval<305)& (yval>330 && yval<345)) //right(transmitter tilted to right)
    {
      //digitalWrite(ledPin,HIGH);
      changeC(r,data);Serial.print("Right");
      vw_send((uint8_t*)data,1);
     }
     if ((xval<390 && xval>350) && (yval>320 && yval<355))//left(transmitter tilted to left)
    {
      //digitalWrite(ledPin,HIGH);
      changeC(l,data);Serial.print("Left");
    vw_send((uint8_t*)data,1);
      
    }
  }
  //delay(1000);
  
}
void changeC(int num,char *data) 
{
  int k = num,i = 0,j;

  while (k > 0)
  {
    k/=10;
    i++;
  }
  int l = i;

  for (i = 0,j = l-1; i < l; i++,j--)
  {
    data[j] = char(num%10);
    num/=10;
  }
}
