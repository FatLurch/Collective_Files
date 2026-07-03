#include <Joystick.h>
#include <Wire.h>
#include <Adafruit_MCP23X17.h>


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK, 
  16,0,                 // Button Count, Hat Switch Count
  false, false, false,   // X, Y, Z Axis
  false, false, false,  // Rx, Ry, Rz
  false, true,         // rudder, throttle
  false, false, false); // accelerator, brake, steering

Adafruit_MCP23X17 mcp;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

void setup() {
  // Use Pin 6 to power the MCP. Power cycle the MCP at startup to reinitialize connection in case of ESD event
  Joystick.setThrottleRange(70, 1024);
  pinMode(6, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  digitalWrite(6, LOW);
  delay(50);
  digitalWrite(6, HIGH);
  //int analogIn;

  mcp.begin_I2C();      // use default address 0

  mcp.pinMode(0, INPUT_PULLUP);
  //mcp.pullUp(0, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(1, INPUT_PULLUP);
  //mcp.pullUp(1, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(2, INPUT_PULLUP);
  //mcp.pullUp(2, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(3, INPUT_PULLUP);
  //mcp.pullUp(3, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(4, INPUT_PULLUP);
  //mcp.pullUp(4, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(5, INPUT_PULLUP);
  //mcp.pullUp(5, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(6, INPUT_PULLUP);
  //mcp.pullUp(6, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(7, INPUT_PULLUP);
  //mcp.pullUp(7, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(8, INPUT_PULLUP);
  //mcp.pullUp(8, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(9, INPUT_PULLUP);
  //mcp.pullUp(9, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(10, INPUT_PULLUP);
  //mcp.pullUp(10, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(11, INPUT_PULLUP);
  //mcp.pullUp(11, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(12, INPUT_PULLUP);
  //mcp.pullUp(12, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(13, INPUT_PULLUP);
  //mcp.pullUp(13, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(14, INPUT_PULLUP);
  //mcp.pullUp(14, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(15, INPUT_PULLUP);
  //mcp.pullUp(15, HIGH);  // turn on a 100K pullup internally

  Serial.begin(9600);

  Joystick.begin();
}

int lastButtonState[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {
  
  // Read pin values
  for (int index = 0; index < 16; index++)
  {
    int currentButtonState = !mcp.digitalRead(index);
    delay(2);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  int analogIn = analogRead(analogInPin);
  Joystick.setThrottle(analogIn);
  //Joystick.setButton(16, !digitalRead(10)); //Hopefully someday latched buttons can be read, allowing for a real parking brake
  //Serial.println(analogIn);

  delay(20);
  
}
