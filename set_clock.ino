void set_clock() {
  lcd.clear();
  lcd.print(F("Set Date:"));
  lcd.setCursor(0, 1);
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
  lcd.blink();
  time_set_status = true;
  h_year = per_year / 1000;
  s_year = (per_year % 1000) / 100;
  d_year = (per_year % 100) / 10;
  y_year = per_year % 10;
  d_month = per_month / 10;
  y_month = per_month % 10;
  d_day = per_day / 10;
  y_day = per_day % 10;
  d_hour = Hour / 10;
  y_hour = Hour % 10;
  d_minute = Minute / 10;
  y_minute = Minute % 10;
  d_second = Second / 10;
  y_second = Second % 10;
  while (true) {
    char key = keypad.getKey();
    if (status == 0 ) {
      lcd.setCursor(0, 1);
      if (key == '0') {
        h_year = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        h_year = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        h_year = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        h_year = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        h_year = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        h_year = 5;
        lcd.print(5);
        status++;
      } else if (key == '6') {
        h_year = 6;
        lcd.print(6);
        status++;
      } else if (key == '7') {
        h_year = 7;
        lcd.print(7);
        status++;
      } else if (key == '8') {
        h_year = 8;
        lcd.print(8);
        status++;
      } else if (key == '9') {
        h_year = 9;
        lcd.print(9);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
        lcd.noBlink();
        break;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 1 ) {
      lcd.setCursor(1, 1);
      if (key == '0') {
        s_year = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        s_year = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        s_year = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        s_year = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        s_year = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        s_year = 5;
        lcd.print(5);
        status++;
      } else if (key == '6') {
        s_year = 6;
        lcd.print(6);
        status++;
      } else if (key == '7') {
        s_year = 7;
        lcd.print(7);
        status++;
      } else if (key == '8') {
        s_year = 8;
        lcd.print(8);
        status++;
      } else if (key == '9') {
        s_year = 9;
        lcd.print(9);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 2 ) {
      lcd.setCursor(2, 1);
      if (key == '0') {
        d_year = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        d_year = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        d_year = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        d_year = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        d_year = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        d_year = 5;
        lcd.print(5);
        status++;
      } else if (key == '6') {
        d_year = 6;
        lcd.print(6);
        status++;
      } else if (key == '7') {
        d_year = 7;
        lcd.print(7);
        status++;
      } else if (key == '8') {
        d_year = 8;
        lcd.print(8);
        status++;
      } else if (key == '9') {
        d_year = 9;
        lcd.print(9);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 3 ) {
      lcd.setCursor(3, 1);
      if (key == '0') {
        y_year = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        y_year = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        y_year = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        y_year = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        y_year = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        y_year = 5;
        lcd.print(5);
        status++;
      } else if (key == '6') {
        y_year = 6;
        lcd.print(6);
        status++;
      } else if (key == '7') {
        y_year = 7;
        lcd.print(7);
        status++;
      } else if (key == '8') {
        y_year = 8;
        lcd.print(8);
        status++;
      } else if (key == '9') {
        y_year = 9;
        lcd.print(9);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 4 ) {
      lcd.setCursor(5, 1);
      if (key == '0') {
        d_month = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        d_month = 1;
        lcd.print(1);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 5 ) {
      lcd.setCursor(6, 1);
      if (key == '0') {
        y_month = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        y_month = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        y_month = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        if ( d_month == 0 ) {
          y_month = 3;
          lcd.print(3);
          status++;
        }
      } else if (key == '4') {
        if ( d_month == 0 ) {
          y_month = 4;
          lcd.print(4);
          status++;
        }
      } else if (key == '5') {
        if ( d_month == 0 ) {
          y_month = 5;
          lcd.print(5);
          status++;
        }
      } else if (key == '6') {
        if ( d_month == 0 ) {
          y_month = 6;
          lcd.print(6);
          status++;
        }
      } else if (key == '7') {
        if ( d_month == 0 ) {
          y_month = 7;
          lcd.print(7);
          status++;
        }
      } else if (key == '8') {
        if ( d_month == 0 ) {
          y_month = 8;
          lcd.print(8);
          status++;
        }
      } else if (key == '9') {
        if ( d_month == 0 ) {
          y_month = 9;
          lcd.print(9);
          status++;
        }
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 6 ) {
      lcd.setCursor(8, 1);
      if (key == '0') {
        d_day = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        d_day = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        d_day = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        d_day = 3;
        lcd.print(3);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 7 ) {
      lcd.setCursor(9, 1);
      if (key == '0') {
        y_day = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        y_day = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        if ( d_day < 3 ) {
          y_day = 2;
          lcd.print(2);
          status++;
        }
      } else if (key == '3') {
        if ( d_day < 3 ) {
          y_day = 3;
          lcd.print(3);
          status++;
        }
      } else if (key == '4') {
        if ( d_day < 3 ) {
          y_day = 4;
          lcd.print(4);
          status++;
        }
      } else if (key == '5') {
        if ( d_day < 3 ) {
          y_day = 5;
          lcd.print(5);
          status++;
        }
      } else if (key == '6') {
        if ( d_day < 3 ) {
          y_day = 6;
          lcd.print(6);
          status++;
        }
      } else if (key == '7') {
        if ( d_day < 3 ) {
          y_day = 7;
          lcd.print(7);
          status++;
        }
      } else if (key == '8') {
        if ( d_day < 3 ) {
          y_day = 8;
          lcd.print(8);
          status++;
        }
      } else if (key == '9') {
        if ( d_day < 3 ) {
          y_day = 9;
          lcd.print(9);
          status++;
        }
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 8 ) {
      if (time_set_status) {
        lcd.clear();
        lcd.print(F("Set Time:"));
        lcd.setCursor(0, 1);
        if (Hour < 10) {
          lcd.print(F("0"));
        }
        lcd.print(Hour);
        lcd.print(F(":"));
        if (Minute < 10) {
          lcd.print(F("0"));
        }
        lcd.print(Minute);
        lcd.print(F(":"));
        if (Second < 10) {
          lcd.print(F("0"));
        }
        lcd.print(Second);
        lcd.setCursor(0, 1);
        time_set_status = false;
      }
      if (key == '0') {
        d_hour = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        d_hour = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        d_hour = 2;
        lcd.print(2);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
        if (set_clock_only) {
          set_clock_only = false;
          lcd.noBlink();
          break;
        }
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 9 ) {
      lcd.setCursor(1, 1);
      if (key == '0') {
        y_hour = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        y_hour = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        y_hour = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        y_hour = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        if ( d_hour < 3) {
          y_hour = 4;
          lcd.print(4);
          status++;
        }
      } else if (key == '5') {
        if ( d_hour < 2) {
          y_hour = 5;
          lcd.print(5);
          status++;
        }
      } else if (key == '6') {
        if ( d_hour < 2) {
          y_hour = 6;
          lcd.print(6);
          status++;
        }
      } else if (key == '7') {
        if ( d_hour < 2) {
          y_hour = 7;
          lcd.print(7);
          status++;
        }
      } else if (key == '8') {
        if ( d_hour < 2) {
          y_hour = 8;
          lcd.print(8);
          status++;
        }
      } else if (key == '9') {
        if ( d_hour < 2) {
          y_hour = 9;
          lcd.print(9);
          status++;
        }
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 10 ) {
      lcd.setCursor(3, 1);
      if (key == '0') {
        d_minute = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        d_minute = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        d_minute = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        d_minute = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        d_minute = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        d_minute = 5;
        lcd.print(5);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 11 ) {
      lcd.setCursor(4, 1);
      if (key == '0') {
        y_minute = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        y_minute = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        y_minute = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        y_minute = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        y_minute = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        y_minute = 5;
        lcd.print(5);
        status++;
      } else if (key == '6') {
        y_minute = 6;
        lcd.print(6);
        status++;
      } else if (key == '7') {
        y_minute = 7;
        lcd.print(7);
        status++;
      } else if (key == '8') {
        y_minute = 8;
        lcd.print(8);
        status++;
      } else if (key == '9') {
        y_minute = 9;
        lcd.print(9);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 12 ) {
      lcd.setCursor(6, 1);
      if (key == '0') {
        d_second = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        d_second = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        d_second = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        d_second = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        d_second = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        d_second = 5;
        lcd.print(5);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if (status == 13 ) {
      lcd.setCursor(7, 1);
      if (key == '0') {
        y_second = 0;
        lcd.print(0);
        status++;
      } else if (key == '1') {
        y_second = 1;
        lcd.print(1);
        status++;
      } else if (key == '2') {
        y_second = 2;
        lcd.print(2);
        status++;
      } else if (key == '3') {
        y_second = 3;
        lcd.print(3);
        status++;
      } else if (key == '4') {
        y_second = 4;
        lcd.print(4);
        status++;
      } else if (key == '5') {
        y_second = 5;
        lcd.print(5);
        status++;
      } else if (key == '6') {
        y_second = 6;
        lcd.print(6);
        status++;
      } else if (key == '7') {
        y_second = 7;
        lcd.print(7);
        status++;
      } else if (key == '8') {
        y_second = 8;
        lcd.print(8);
        status++;
      } else if (key == '9') {
        y_second = 9;
        lcd.print(9);
        status++;
      } else if (key == 'A') {
        status++;
      } else if (key == 'B') {
        status--;
      } else if (key == 'C') {
        lcd.noBlink();
        break;
      } else if (key == 'D') {
        status = 14;
      }
    } else if ( status == 14 ) {
      lcd.noBlink();
      per_year = h_year * 1000;
      per_year += s_year * 100;
      per_year += d_year * 10;
      per_year += y_year;

      per_month = d_month * 10;
      per_month += y_month;

      per_day = d_day * 10;
      per_day += y_day;

      Hour = d_hour * 10;
      Hour += y_hour;

      Minute = d_minute * 10;
      Minute += y_minute;

      Second = d_second * 10;
      Second += y_minute;
      jal.convert_date(per_year, per_month, per_day, rtc_year, rtc_month, rtc_day, JALALI);
      set_rtc();
      break;
    }
  }
}
