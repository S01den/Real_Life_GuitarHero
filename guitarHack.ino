#include <Wire.h>
#include "LibChuck.h"
 
Nunchuk guitare = Nunchuk();

void setup()
{
 Serial.begin(9600);
  guitare.init(); 
}

bool toneBool = false;

int i = 3; // octave for E
int j = 3; // octave for A
int k = 3; // octave for D
int l = 3; // octave for G
int m = 3; // octave for B

int boutonSelect = 1;

/* TABLES OF THE DIFFERENTS NOTES AND OCTAVES */

int note_a[] = {NOTE_A1, NOTE_A2, NOTE_A3, NOTE_A4, NOTE_A5, NOTE_A6, NOTE_A7}; // La
int note_e[] = {NOTE_E1, NOTE_E2, NOTE_E3, NOTE_E4, NOTE_E5, NOTE_E6, NOTE_E7}; // Mi
int note_d[] = {NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6, NOTE_D7}; // Ré
int note_g[] = {NOTE_G1, NOTE_G2, NOTE_G3, NOTE_G4, NOTE_G5, NOTE_G6, NOTE_G7}; // Sol
int note_b[] = {NOTE_B1, NOTE_B2, NOTE_B3, NOTE_B4, NOTE_B5, NOTE_B6, NOTE_B7}; // Si


void loop()
{
 guitare.upDate(); 
  
  Serial.print(guitare.boutonY); 
  Serial.print(" ");
  Serial.print(guitare.boutonG);
  Serial.print(" ");
  Serial.print(guitare.boutonR);
  Serial.println(" ");
  
  toneBool = false;

  if(guitare.boutonY == 1) // If the yellow button is pressed, the guitar plays a D of octave k
  {
    boutonSelect = 3;
    tone(8, note_d[k], 250);
    toneBool = true;
  }
  if(guitare.boutonR == 1) // If the red button is pressed, the guitar plays an A of octave j
  {
    boutonSelect = 2;
    tone(8, note_a[j], 250);
    toneBool = true;
  }
  if(guitare.boutonG == 1) // // If the green button is pressed, the guitar plays a E of octave i
  {
    boutonSelect = 1;
    tone(8, note_e[i], 250);
    toneBool = true;
  }
  if(guitare.boutonB == 1 && guitare.boutonG == 0) // If the blue button is pressed, the guitar plays a G of octave l
  {
    boutonSelect = 4;
    tone(8, note_g[l], 250);
    toneBool = true;
  }
  if(guitare.boutonO == 1) // If the orange button is pressed, the guitar plays a B of octave m
  {
    boutonSelect = 5;
    tone(8, note_b[m], 250);
    toneBool = true;
  }


  if(guitare.boutonM == 1) // If the '-' button is pressed, decrease the octave of the note currentely played
  {
    switch(boutonSelect)
    {
      case 1:
      if(i > 0)
          i--;
        break;
      case 2:
      if(j > 0)
          j--;
        break;
      case 3:
      if(k > 0)
          k--;
        break;        
      case 4:
      if(l > 0)
          l--;
        break;    
      case 5:
      if(m > 0)
          m--;
        break; 
    }
    delay(100);
  }

  if(guitare.boutonP == 1) // If the '+' button is pressed, increase the octave of the note currentely played
  {
    switch(boutonSelect)
    {
      case 1:
      if(i < 6)
          i++;
        break;
      case 2:
      if(j < 6)
          j++;
        break;
      case 3:
      if(k < 6)
          k++;
        break;        
      case 4:
      if(l < 6)
          l++;
        break;    
      case 5:
      if(m < 6)
          m++;
        break; 
    }
    delay(100);
  }
  
  if(toneBool == false)
  {
    noTone(8);  
  }   
}

