// Nixie Lab by Marcin Saj https://nixietester.com
// https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project
//
// Driving Nixie Tubes Example #1
//
// This example demonstrates how to control up to 8 nixie tubes.
// The control is carried out using Master/Slave Nixie Lab modules in serial connection.

int dataPin = A0;       // Serial data input pin
int latchPin = 8;       // Latch input pin
int clockPin = 9;       // Clock input pin

// First socket translation array
int nixie1[]={
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
int nixie2[]={
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

// Function prototype with optional parameters
void NixieDisplay(byte digit1 = 77, byte digit2 = 77, byte digit3 = 77, byte digit4 = 77, byte digit5 = 77, byte digit6 = 77, byte digit7 = 77, byte digit8 = 77);

void setup() 
{  
    Serial.begin(9600);
    
    pinMode(dataPin, OUTPUT); 
    digitalWrite(dataPin, LOW);    
    
    pinMode(clockPin, OUTPUT);
    digitalWrite(clockPin, LOW);         
  
    pinMode(latchPin, OUTPUT);
    digitalWrite(latchPin, LOW);
}

void loop ()
{
  NixieDisplay(1, 2);
//NixieDisplay(1, 2, 3, 4);
//NixieDisplay(1, 2, 3, 4, 5, 6);
//NixieDisplay(1, 2, 3, 4, 5, 6, 7, 8);   //  NixieDisplay(digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8);
  delay(1000);       
}

// Function with optional parameters 
void NixieDisplay(byte digit1, byte digit2 , byte digit3, byte digit4, byte digit5, byte digit6, byte digit7, byte digit8)
{
  StartShiftOutData();
  if (digit8 != 77 || digit7 != 77) ShiftOutData(digit7, digit8);
  if (digit6 != 77 || digit5 != 77) ShiftOutData(digit5, digit6);
  if (digit4 != 77 || digit3 != 77) ShiftOutData(digit3, digit4);
  if (digit2 != 77 || digit1 != 77) ShiftOutData(digit1, digit2);    
  EndShiftOutData();   
}

void StartShiftOutData()
{
  // Ground latch pin and hold low for as long as you are transmitting
  digitalWrite(latchPin, 0); 
  // Clear everything out just in case to
  // prepare shift register for bit shifting
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);  
}

void ShiftOutData(byte digitFirst, byte digitSecond)
{
  byte data;     

  // Each master/slave module contains two nixie sockets
  // The first socket uses the "nixie1" translation array
  // The second socket uses the "nixie2" translation array
  
  // Extract left half (8 bits) of 16 bits nixie2 array value
  data = nixie2[digitSecond] >> 8;
  shiftOut(dataPin, clockPin, MSBFIRST, data);  
  // Extract right half (8 bits) of 16 bits nixie2 array value
  data = nixie2[digitSecond];
  shiftOut(dataPin, clockPin, MSBFIRST, data);

  // Extract left half (8 bits) of 16 bits nixie1 array value
  data = nixie1[digitFirst] >> 8;  
  shiftOut(dataPin, clockPin, MSBFIRST, data); 
  // Extract right half (8 bits) of 16 bits nixie1 array value
  data = nixie1[digitFirst];
  shiftOut(dataPin, clockPin, MSBFIRST, data);
}

void EndShiftOutData()
{
  // Return the latch pin high to signal chip that it 
  // no longer needs to listen for data
  digitalWrite(latchPin, 1);
    
  // Stop shifting
  digitalWrite(clockPin, 0);    
}
