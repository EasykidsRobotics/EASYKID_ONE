/***************************************************
  This is an example for our Adafruit 16-channel PWM & Servo driver
  GPIO test - this will set a pin high/low

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These drivers use I2C to communicate, 2 pins are required to
  interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

void setup() {
  Serial.begin(9600);
  Serial.println("GPIO test!");

  pwm.begin();
  pwm.setPWMFreq(200);  // Set to whatever you like, we don't use it in this demo!

  // if you want to really speed stuff up, you can go into 'fast 400khz I2C' mode
  // some i2c devices dont like this so much so if you're sharing the bus, watch
  // out for this!
  Wire.setClock(400000);
}

void loop() {
  // Drive each pin in a 'wave'
  pwm.setPWM(0, 4095, 0);    // turns pin fully on
  pwm.setPWM(1, 0, 4095);    // turns pin fully off
  pwm.setPWM(2, 4095, 0);    // turns pin fully on
  pwm.setPWM(3, 0, 4095);    // turns pin fully off
  pwm.setPWM(4, 4095, 0);    // turns pin fully on
  pwm.setPWM(5, 0, 4095);    // turns pin fully off
  pwm.setPWM(6, 4095, 0);    // turns pin fully on
  pwm.setPWM(7, 0, 4095);    // turns pin fully off
  delay(3000);
  pwm.setPWM(0, 0, 4095);  // turns pin fully on
  pwm.setPWM(1, 4095, 0);  // turns pin fully off
  pwm.setPWM(2, 0, 4095);  // turns pin fully on
  pwm.setPWM(3, 4095, 0);  // turns pin fully off
  pwm.setPWM(4, 0, 4095);  // turns pin fully on
  pwm.setPWM(5, 4095, 0);  // turns pin fully off
  pwm.setPWM(6, 0, 4095);  // turns pin fully on
  pwm.setPWM(7, 4095, 0);  // turns pin fully off
  delay(3000);
}
