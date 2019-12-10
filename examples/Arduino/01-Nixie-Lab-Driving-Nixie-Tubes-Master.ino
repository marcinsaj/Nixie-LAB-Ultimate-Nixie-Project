// Nixie Lab by Marcin Saj https://nixietester.com
// https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project
//
// Driving Nixie Tubes Example #1 - Master
// This example demonstrates how to control Master module with two nixie tubes.

int dataPin = A0;       // Serial data input pin
int latchPin = 8;       // Latch input pin
int clockPin = 9;       // Clock input pin

// First socket translation array
uint16_t nixie1[]={
  0b0000000000000010,   // 0 
  0b0010000000000000,   // 1
  0b0100000000000000,   // 2
  0b1000000000000000,   // 3
  0b0000000000010000,   // 4
  0b0000000000100000,   // 5
  0b0000000001000000,   // 6
  0b0000000010000000,   // 7
  0b0000000000001000,   // 8
  0b0000000000000100    // 9
};

// Second socket translation array
uint16_t nixie2[]={
  0b1000000000000000,   // 0 
  0b0000000010000000,   // 1
  0b0000000001000000,   // 2
  0b0000000000100000,   // 3
  0b0000000000010000,   // 4
  0b0000000000001000,   // 5
  0b0000000000000100,   // 6
  0b0000000000000010,   // 7
  0b0000000000000001,   // 8
  0b0100000000000000    // 9
};

void setup() 
{      
    pinMode(dataPin, OUTPUT); 
    digitalWrite(dataPin, LOW);    
    
    pinMode(clockPin, OUTPUT);
    digitalWrite(clockPin, LOW);         
  
    pinMode(latchPin, OUTPUT);
    digitalWrite(latchPin, LOW);
}

void loop ()
{
  for(int i = 0; i <= 9; i++)
  {
    // Do simple counting
    NixieDisplay(i, i);
    delay(1000);      
  }      
}

void NixieDisplay(byte digit1, byte digit2)
{  
  // Ground latch pin and hold low for as long as you are transmitting
  digitalWrite(latchPin, 0); 
  // Clear everything out just in case to
  // prepare shift register for bit shifting
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);   

  // Each master/slave module contains two nixie sockets
  // The first socket uses the "nixie1" translation array
  // The second socket uses the "nixie2" translation array

  byte data;
    
  // Extract left half (8 bits) of 16 bits nixie2 array value
  data = nixie2[digit2] >> 8;
  shiftOut(dataPin, clockPin, MSBFIRST, data);  
  // Extract right half (8 bits) of 16 bits nixie2 array value
  data = nixie2[digit2];
  shiftOut(dataPin, clockPin, MSBFIRST, data);

  // Extract left half (8 bits) of 16 bits nixie1 array value
  data = nixie1[digit1] >> 8;  
  shiftOut(dataPin, clockPin, MSBFIRST, data); 
  // Extract right half (8 bits) of 16 bits nixie1 array value
  data = nixie1[digit1];
  shiftOut(dataPin, clockPin, MSBFIRST, data);

  // Return the latch pin high to signal chip that it 
  // no longer needs to listen for data
  digitalWrite(latchPin, 1);
    
  // Stop shifting
  digitalWrite(clockPin, 0);    
}
