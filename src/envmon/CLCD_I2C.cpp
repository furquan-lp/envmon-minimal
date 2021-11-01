#include "CLCD_I2C.h"

CharacterLCD::CharacterLCD (uint8_t address, uint8_t c, uint8_t r)
        : lcd(address, c, r) {
    addr = address;
    cols = c;
    rows = r;
}

void CharacterLCD::init() {
    //lcd = LiquidCrystal_I2C(addr, rows, cols);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
}

void CharacterLCD::clearLCD() {
    lcd.clear();
}

void CharacterLCD::selectLine(int l) {
    if (l < rows)
        lcd.setCursor(0, l);
}


void CharacterLCD::printLCD(const char* s) {
    if(strlen(s) <= cols)
        lcd.print(s);
}

void CharacterLCD::printLCD(String s) {
    if (s.length() <= cols)
        lcd.print(s);
}

void CharacterLCD::printLCD(int n) {
    lcd.print(n);
}

void CharacterLCD::printLCD(float f) {
    lcd.print(f);
}

void CharacterLCD::printAt(const char* s, uint8_t col, uint8_t row) {
    if (col <= cols && row <= rows) {
        lcd.setCursor(col, row);
        this->printLCD(s);
    }
}

void CharacterLCD::printAt(String s, uint8_t col, uint8_t row) {
    if (col <= cols && row <= rows) {
        lcd.setCursor(col, row);
        this->printLCD(s);
    }
}
