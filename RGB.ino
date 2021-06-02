#include <EEPROM.h>

//pin of the red led
byte red = 11;
//pin of the green led
byte green = 6;
//pin of the blue led
byte blue = 3;
byte mode = 0;
//duration of effects
int duration = 1000;
//where to save the mode in EEPROM
byte address = 0;
//analog pin of the button
byte button = 0;

void setup() {
  //initialize pins
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  //read mode
  mode = EEPROM.read(address);
}

void loop() {
  //try to switch mode
  switchMode();
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
  if (mode == 0) {
    mode0();
  } else if (mode == 1) {
    mode1();
  } else if (mode == 2) {
    mode2();
  } else if (mode == 3) {
    mode3();
  } else if (mode == 4) {
    mode4();
  } else if (mode == 5) {
    mode5();
  } else if (mode == 6) {
    mode6();
  } else if (mode == 7) {
    mode7();
  } else if (mode == 8) {
    mode8();
  }else if (mode == 9) {
    delay(1000);
  }
}

void mode0() {
  analogWrite(red, 200);
  delay(duration);
  switchMode();
  analogWrite(red, 0);
  analogWrite(green, 200);
  delay(duration);
  switchMode();
  analogWrite(green, 0);
  analogWrite(blue, 200);
  delay(duration);
}

void mode1() {
  for (int i = 0; i < 201; i += 5) {
    analogWrite(red, 200 - i);
    analogWrite(green, i);
    delay(duration / 10);
  }
  switchMode();
  for (int i = 0; i < 201; i += 5) {
    analogWrite(green, 200 - i);
    analogWrite(blue, i);
    delay(duration / 10);
  }
  switchMode();
  for (int i = 0; i < 201; i += 5) {
    analogWrite(blue, 200 - i);
    analogWrite(red, i);
    delay(duration / 10);
  }
}

void mode2() {
  analogWrite(red, 200);
  delay(1000);
}

void mode3() {
  analogWrite(red, 150);
  analogWrite(green, 150);
  delay(1000);
}

void mode4() {
  analogWrite(green, 200);
  delay(1000);
}

void mode5() {
  analogWrite(green, 150);
  analogWrite(blue, 150);
  delay(1000);
}

void mode6() {
  analogWrite(blue, 200);
  delay(1000);
}

void mode7() {
  analogWrite(blue, 150);
  analogWrite(red, 150);
  delay(1000);
}

void mode8() {
  analogWrite(red, 200);
  analogWrite(green, 200);
  analogWrite(blue, 200);
  delay(1000);
}

void switchMode() {
  if (analogRead(button) > 1000) {
    mode++;
    if (mode == 10) {
      mode = 0;
    }
    EEPROM.write(address, mode);
    analogWrite(green, 0);
    analogWrite(red, 0);
    analogWrite(blue, 0);
    delay(1000);
    analogWrite(green, 200);
    analogWrite(red, 200);
    analogWrite(blue, 200);
    delay(1000);
    analogWrite(green, 0);
    analogWrite(red, 0);
    analogWrite(blue, 0);
  }
}
