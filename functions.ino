void set_rtc() {
  //  RTCLib::set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
  rtc.set(Second, Minute, Hour, dow, rtc_day, rtc_month, rtc_year - 2000);
  rtc.refresh();
}

void get_rtc() {
  rtc.refresh();
  rtc_year = rtc.year() + 2000;
  rtc_month = rtc.month();
  rtc_day = rtc.day();
  Hour = rtc.hour();
  Minute = rtc.minute();
  Second = rtc.second();
  jal.convert_date( rtc_year, rtc_month, rtc_day, per_year, per_month, per_day, GREGORIAN );
}

void write_eeprom(int location) {
  location *= 9;
  eeprom.eeprom_write(location - 8, sobh_hour);
  eeprom.eeprom_write(location - 7, sobh_minute);
  eeprom.eeprom_write(location - 6, sobh_second);
  eeprom.eeprom_write(location - 5, zohr_hour);
  eeprom.eeprom_write(location - 4, zohr_minute);
  eeprom.eeprom_write(location - 3, zohr_second);
  eeprom.eeprom_write(location - 2, shab_hour);
  eeprom.eeprom_write(location - 1, shab_minute);
  eeprom.eeprom_write(location - 0, shab_second);
}

void read_eeprom(int location) {
  location *= 9;
  eeprom.eeprom_read(location - 8, &sobh_hour);
  eeprom.eeprom_read(location - 7, &sobh_minute);
  eeprom.eeprom_read(location - 6, &sobh_second);
  eeprom.eeprom_read(location - 5, &zohr_hour);
  eeprom.eeprom_read(location - 4, &zohr_minute);
  eeprom.eeprom_read(location - 3, &zohr_second);
  eeprom.eeprom_read(location - 2, &shab_hour);
  eeprom.eeprom_read(location - 1, &shab_minute);
  eeprom.eeprom_read(location - 0, &shab_second);
}

void welcome() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(F("Pray Timer"));
  lcd.setCursor(1, 1);
  lcd.print(F("0937 938 6752"));
}

short int get_day_number(int month_num, int day_num) {
  short int value = 0;
  if ( month_num > 6 ) {
    value = 186;
    month_num -= 6;
  }
  if ( month_num > 1 ) {
    month_num--;
    value += month_num * 30;
  }
  value += day_num;
  return value;
}

void display_home() {
  lcd.clear();
  lcd.print(F("Date: "));
  lcd.print(per_year);
  lcd.print(F("/"));
  if ( per_month < 10 ) {
    lcd.print(F("0"));
  }
  lcd.print(per_month);
  lcd.print(F("/"));
  if ( per_day < 10 ) {
    lcd.print(F("0"));
  }
  lcd.print(per_day);
  lcd.setCursor(0, 1);
  lcd.print(F("Time:  "));
  if ( Hour < 10 ) {
    lcd.print(F("0"));
  }
  lcd.print(Hour);
  lcd.print(F(":"));
  if ( Minute < 10 ) {
    lcd.print(F("0"));
  }
  lcd.print(Minute);
  lcd.print(F(":"));
  if ( Second < 10 ) {
    lcd.print(F("0"));
  }
  lcd.print(Second);
}

void calc_ramdan() {
  if (sobh_minute >= 30) {
    sobh_minute -= 30;
  } else {
    sobh_hour--;
    sobh_minute = 60 - (30 - sobh_minute);
  }
  if ( zohr_minute >= 30 ) {
    zohr_minute -= 30;
  } else {
    zohr_hour--;
    zohr_minute = 60 - (30 - zohr_minute);
  }
  if (shab_minute >= 30) {
    shab_minute -= 30;
  } else {
    shab_hour--;
    shab_minute = 60 - (30 - shab_minute);
  }
}

void play_azan() {
  digitalWrite(relay, HIGH);
  lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print(F("Playing"));
    lcd.setCursor(1, 1);
    lcd.print(F("0937 938 6752"));
  if (digitalRead(ramdan_mode) == HIGH) {
    execute_CMD(0x11, 0, 2); //play file 2
    delay(1800000);
    } else {
    execute_CMD(0x11, 0, 1); //play file 1
    delay(300000);
    }
  execute_CMD(0x0E, 0, 0);
  digitalWrite(relay, LOW);
}


void execute_CMD(byte CMD, byte Par1, byte Par2)
// Excecute the command and parameters
{
  // Calculate the checksum (2 bytes)
  word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
  // Build the command line
  byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
                            Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte
                          };
  //Send the command line to the module
  for (byte k = 0; k < 10; k++)
  {
    Serial.write( Command_line[k]);
  }
}

