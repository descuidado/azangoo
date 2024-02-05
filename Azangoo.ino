#include <Wire.h>
#include <uEEPROMLib.h>
#include <uRTCLib.h>
#include <Jalali.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
//df player mini definitions
# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 //Returns info with command 0x41 [0x01: info, 0x00: no info]
# define ACTIVATED LOW


#define relay 17
#define dow 7 //day of week!!!
#define ramdan_mode 2

/*Azangoo pinout:
  0,1: DFPlayer mini
  2: [Ramadan Mode]   status key(auto on or allways on)
  3-8: LCD 1602
  9-16: 4*4 Keypad
  17: Relay
  18,19: RTC-MEMory
*/
/*
   4*4 keypad pinout is:
   while keypad pins are left side from up to down Connections be like:
  1: A2/16
  2: A1/15
  3: A0/14
  4: 13
  5: 12
  6: 11
  7: 10
  8: 9
*/
//uEEPROMLib eeprom;
uEEPROMLib eeprom(0x50);

//uRTLib setup
uRTCLib rtc;
//rtc.set_model(URTCLIB_MODEL_DS1307);
//rtc.set_model(URTCLIB_MODEL_DS3232);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//jalali calendar
Jalali jal;
char buf[30];

//LCD Connections
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

//define RTC and Converted Variables
int per_year, per_month, per_day; //
uint8_t sobh_hour, sobh_minute, sobh_second, zohr_hour, zohr_minute, zohr_second, shab_hour, shab_minute, shab_second, Hour, Minute, Second;
int rtc_year, day_number, last_day;
int rtc_month, rtc_day, set;
unsigned long int last_loop = 0;
bool new_day = true;
bool time_set_status = true;
bool set_clock_only = false;

//Keypad Settings
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 14, 15, 16}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

uint8_t h_year = 0, s_year = 0, d_year = 0, y_year = 0, d_month = 0, y_month = 0, d_day = 0, y_day = 0, d_hour = 0, y_hour = 0, d_minute = 0,  y_minute = 0, d_second = 0, y_second = 0, status = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  URTCLIB_WIRE.begin();
  rtc.set_rtc_address(0x68);
  lcd.begin(16, 2);
  pinMode(relay, OUTPUT);
  pinMode(ramdan_mode, INPUT_PULLUP);
  welcome();
  //Setup df player mini
  //Serial.begin(9600);
  execute_CMD(0x3F, 0, 0);
  delay(500);
  execute_CMD(0x06, 0, 20); // Set the volume (0x00~0x30)
  delay(2500);
  execute_CMD(0x11, 1, 0);
  delay(500);
  eeprom.eeprom_read(0, &set);
  if (set == 255) {
    set_clock();

    eeprom.eeprom_write(0, 0);
  }
}

void loop() {
  char key = keypad.getKey();
  if (key == 'A') {
    status = 0;
    set_clock();
  } else if (key == 'B') {
    status = 8;
    set_clock_only = true;
    set_clock();
  }
  if (millis() > last_loop + 1000) {
    last_loop = millis();
    get_rtc();
    display_home();
    day_number = get_day_number(per_month, per_day);
    if (last_day != day_number) {
      new_day = true;
    }
    if (new_day) {
      read_eeprom(day_number);
      new_day = false;
      last_day = day_number;
      if ( digitalRead(ramdan_mode) == HIGH ) {
        calc_ramdan();
      }
    }
    if ( (Hour == sobh_hour && Minute == sobh_minute && Second == sobh_second) || (Hour == zohr_hour && Minute == zohr_minute && Second == zohr_second) || (Hour == shab_hour && Minute == shab_minute && Second == shab_second)) {
      play_azan();
    }
  }
}
