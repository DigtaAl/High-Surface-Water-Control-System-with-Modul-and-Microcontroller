#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <Wire.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
#define TRIGGER_PIN A0 // Memberi nama variabel pin A0 menjadi TRIGGER_PIN
#define ECHO_PIN A1 // Memberi nama variabel pin A1 menjadi ECHO
#define MAX_DISTANCE 200 // Membatasi jarak maksimum 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int lamp = 6; // // Memberi nama variabel pin D6 menjadi lamp
int nilai; //
void setup() {
  Serial.begin(9600);
  pinMode(lamp, OUTPUT); // Menentukan pin lamp menjadi pin Output
  lcd.init();
  lcd.backlight();
}
void loop() {
  nilai = sonar.ping_cm();
  Serial.println(nilai);
  if (nilai <= 5) { // jikalau besar nilai <= 5cm
    digitalWrite(lamp, HIGH);
    lcd.clear();
    lcd.print("Lampu Nyala");
    lcd.setCursor(0, 1);
    lcd.print(nilai);
  }
  else { // kecuali kondisi diatas
    digitalWrite(lamp, LOW);
    lcd.clear();
    lcd.print("Lampu Mati");
    lcd.setCursor(0, 1);
    lcd.print(nilai);
  }
  delay(500);
}
