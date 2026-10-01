#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Traffic Light 1 (North/South)
const int TL1_RED = 11; const int TL1_YEL = 10; const int TL1_GRN = 9;
// Traffic Light 3 (North/South)
const int TL3_RED = 5;  const int TL3_YEL = 4;  const int TL3_GRN = 3;

// Traffic Light 2 (East/West)
const int TL2_RED = 8;  const int TL2_YEL = 7;  const int TL2_GRN = 6;
// Traffic Light 4 (East/West)
const int TL4_RED = 2;  const int TL4_YEL = 1;  const int TL4_GRN = 0; 

void setup() {
  for (int i = 0; i <= 11; i++) pinMode(i, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Traffic Control");
  delay(1000);
}

// Helper to reset all pins to off before the next phase
void allOff() {
  for (int i = 0; i <= 11; i++) digitalWrite(i, LOW);
}

void loop() {
  // PHASE 1: North/South GO (4 lights total)
  allOff();
  digitalWrite(TL1_GRN, HIGH); // N/S Green
  digitalWrite(TL3_GRN, HIGH); // N/S Green
  digitalWrite(TL2_RED, HIGH); // E/W Red
  digitalWrite(TL4_RED, HIGH); // E/W Red
  lcd.clear(); lcd.print("N/S: GO"); lcd.setCursor(0,1); lcd.print("E/W: STOP");
  delay(5000);

  // PHASE 2: North/South SLOW (4 lights total)
  allOff();
  digitalWrite(TL1_YEL, HIGH); // N/S Yellow
  digitalWrite(TL3_YEL, HIGH); // N/S Yellow
  digitalWrite(TL2_RED, HIGH); // E/W Red
  digitalWrite(TL4_RED, HIGH); // E/W Red
  lcd.clear(); lcd.print("N/S: SLOW"); lcd.setCursor(0,1); lcd.print("E/W: STOP");
  delay(2000);

  // PHASE 3: East/West GO (4 lights total)
  allOff();
  digitalWrite(TL1_RED, HIGH); // N/S Red
  digitalWrite(TL3_RED, HIGH); // N/S Red
  digitalWrite(TL2_GRN, HIGH); // E/W Green
  digitalWrite(TL4_GRN, HIGH); // E/W Green
  lcd.clear(); lcd.print("N/S: STOP"); lcd.setCursor(0,1); lcd.print("E/W: GO");
  delay(5000);

  // PHASE 4: East/West SLOW (4 lights total)
  allOff();
  digitalWrite(TL1_RED, HIGH); // N/S Red
  digitalWrite(TL3_RED, HIGH); // N/S Red
  digitalWrite(TL2_YEL, HIGH); // E/W Yellow
  digitalWrite(TL4_YEL, HIGH); // E/W Yellow
  lcd.clear(); lcd.print("N/S: STOP"); lcd.setCursor(0,1); lcd.print("E/W: SLOW");
  delay(2000);
}