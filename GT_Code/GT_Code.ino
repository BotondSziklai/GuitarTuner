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
    else if(frek > 269 && frek < 322){
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
    else if(frek > 214 && frek < 239){
      lcd.setCursor(8,0);
      lcd.print("B +");
    }
  }

//G string 
  if(frek > 170 && frek < 215 ){
    if(frek > 189 && frek < 201){
      lcd.setCursor(8,0);
      lcd.print("G-hur");
      lcd.setCursor(3,1);
      lcd.print("Behangolva");
    }
    else if(frek > 200 && frek < 215){
      lcd.setCursor(8,0);
      lcd.print("G -");
    }
    else if(frek > 169 && frek < 188){
      lcd.setCursor(8,0);
      lcd.print("G +");
    }
  }

  //D string 
  if(frek > 125 && frek < 170 ){
    if(frek > 140 && frek < 152){
      lcd.setCursor(8,0);
      lcd.print("B-hur");
      lcd.setCursor(3,1);
      lcd.print("Behangolva");
    }
    else if(frek > 151 && frek < 170){
      lcd.setCursor(8,0);
      lcd.print("B -");
    }
    else if(frek > 124 && frek < 139){
      lcd.setCursor(8,0);
      lcd.print("B +");
    }
  }

  //A string 
  if(frek > 100 && frek < 125 ){
    if(frek > 104 && frek < 116){
      lcd.setCursor(8,0);
      lcd.print("A-hur");
      lcd.setCursor(3,1);
      lcd.print("Behangolva");
    }
    else if(frek > 115 && frek < 125){
      lcd.setCursor(8,0);
      lcd.print("A -");
    }
    else if(frek > 100 && frek < 103){
      lcd.setCursor(8,0);
      lcd.print("A +");
    }
  }

  //E* string 
  if(frek > 70 && frek < 100 ){
    if(frek > 76 && frek < 88){
      lcd.setCursor(8,0);
      lcd.print("E*-hur");
      lcd.setCursor(3,1);
      lcd.print("Behangolva");
    }
    else if(frek > 87 && frek < 100){
      lcd.setCursor(8,0);
      lcd.print("E* -");
    }
    else if(frek > 75 && frek < 70){
      lcd.setCursor(8,0);
      lcd.print("E* +");
    }
  }
   delay(200); //Delay
   lcd.clear(); //Clear display
}