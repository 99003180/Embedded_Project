#include<SPI.h>
volatile boolean received;
volatile uint16_t  Slavereceived, Slavereceived2;

void setup()
{
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                   
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  SPCR |= _BV(SPE);                       
  received = false;
  SPI.attachInterrupt(); 
  Serial.print("SYSTEM BOOTING...........");
  delay(2000);
  Serial.print("SYSTEM READY  ");                 
}


ISR (SPI_STC_vect)                        
{
    Slavereceived = SPDR;            
    received = true;
}

 

void loop()
{
  
  if(received)                           
  {  
      if(Slavereceived != 0)
      {
        received = false;    
        Serial.print("Smoke is  ");
        if(Slavereceived < 50)
        {
          Serial.print("LOW ---");
          Serial.println(Slavereceived);
        }
        else if(Slavereceived >= 50 && Slavereceived < 100)
        {
          Serial.print("MEDIUM ---");
          Serial.println(Slavereceived);
        }
        else
        {
          Serial.print("HIGH ---");
          Serial.println(Slavereceived);
        }
        
        delay(1);
      }
      else if (Slavereceived == 0)
      {
        Serial.println("Smoke is less than threshold");
      }
      else
      {
        //do nothing
      }
  
  
  }
 
}
