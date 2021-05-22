/*
 
  Connection:

    VCC -> 3V3 or 5V
    GND -> GND
    SCL -> D3
    SDA -> D4
    ADD -> (not connected) or GND
    
*/

#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter(0x23);

void setup(){

  Serial.begin(9600);

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin(D4, D3);  //SDA = D4  SCL = D3

  // begin returns a boolean that can be used to detect setup problems.
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }

}


void loop() {
  if (lightMeter.measurementReady()) {
    float lux = lightMeter.readLightLevel();
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
  }

}
