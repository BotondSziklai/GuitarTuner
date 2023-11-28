#include <LiquidCrystal.h>


//Creating variables
#define SOR 2
#define OSZLOP 16
#define PIN A0
int bekapcs,kikapcs;
float frek,periodus;
LiquidCrystal lcd(1,2,4,5,6,7);

//Initial settings
void setup(){
  pinMode(PIN,INPUT); //A0 pin to input
  lcd.begin(OSZLOP, SOR); //Display's size
  lcd.print("Made by Sz. B.");
  delay(1000);
  lcd.clear(); //Clear display
 
}

//Running Code
void loop()
{
   bekapcs = pulseIn(PIN,HIGH); //In microseconds, we get back the time until it goes from high to low
   kikapcs = pulseIn(PIN,LOW); //In microseconds, we get back the time until it goes from low to high
   periodus = bekapcs+kikapcs; //Period calculation
   frek = 1000000.0/periodus; //Frequency calculation
   
   if(periodus > 0){ //Real data
    lcd.setCursor(0,0);
    lcd.print(frek); //Exact frequency display
  }

  //E string
  if(frek > 270 && frek < 360 ){
    if(frek > 323 && frek < 336){
      lcd.setCursor(8,0);
      lcd.print("E-hur");
      lcd.setCursor(3,1);
      lcd.print("Behangolva");
    }
    else if(frek > 335 && frek < 360){
      lcd.setCursor(8,0);
      lcd.print("E -");
    }
    else if(frek > 270 && frek < 322){
      lcd.setCursor(8,0);
      lcd.print("E +");
    }
  }

//B string 
  if(frek > 215 && frek < 270 ){
    if(frek > 240 && frek < 252){
      lcd.setCursor(8,0);
      lcd.print("B-hur");
      lcd.setCursor(3,1);
      lcd.print("Behangolva");
    }
    else if(frek > 251 && frek < 270){
      lcd.setCursor(8,0);
      lcd.print("B -");
    }
    else if(frek > 215 && frek < 239){
      lcd.setCursor(8,0);
      lcd.print("B +");
    }
  }

   delay(200); //Delay
   lcd.clear(); //Clear display
}