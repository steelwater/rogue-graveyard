#include <Arduino.h>
#include <Arduboy2.h>

// Rogue Graveyard — Milestone 0: title + navigation-only placeholder.
// Intentionally no saves, EEPROM writes, Rogue imports, or procedural data.
Arduboy2 arduboy;

enum class Screen : uint8_t {
  Title,
  GraveyardPlaceholder
};

Screen currentScreen = Screen::Title;

void drawTitle() {
  arduboy.setTextSize(1);
  arduboy.setCursor(15, 9);
  arduboy.print(F("ROGUE GRAVEYARD"));
  arduboy.drawFastHLine(12, 23, 104, WHITE);
  arduboy.setCursor(30, 32);
  arduboy.print(F("REST IN PEACE"));
  arduboy.setCursor(27, 52);
  arduboy.print(F("A: ENTER"));
}

void drawPlaceholder() {
  arduboy.setTextSize(1);
  arduboy.setCursor(20, 10);
  arduboy.print(F("THE GRAVEYARD"));
  arduboy.drawFastHLine(8, 24, 112, WHITE);
  arduboy.setCursor(29, 34);
  arduboy.print(F("COMING IN M1"));
  arduboy.setCursor(27, 52);
  arduboy.print(F("B: RETURN"));
}

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }
  arduboy.pollButtons();

  if (currentScreen == Screen::Title && arduboy.justPressed(A_BUTTON)) {
    currentScreen = Screen::GraveyardPlaceholder;
  } else if (currentScreen == Screen::GraveyardPlaceholder &&
             arduboy.justPressed(B_BUTTON)) {
    currentScreen = Screen::Title;
  }

  arduboy.clear();
  if (currentScreen == Screen::Title) {
    drawTitle();
  } else {
    drawPlaceholder();
  }
  arduboy.display();
}
