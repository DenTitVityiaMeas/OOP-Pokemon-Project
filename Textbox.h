#include "stdInclude.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
 public:
  Textbox() {}
  Textbox(int size, sf::Color color, bool sel) {
    textbox.setCharacterSize(size);
    textbox.setColor(color);
    textbox.setOutlineColor(sf::Color::White);
    textbox.setOutlineThickness(1);
    isSelected = sel;
    if (sel) {
      textbox.setString("_");
    } else {
      textbox.setString("");
    }
  }
  void setFont(sf::Font &font) { textbox.setFont(font); }
  void setPosition(sf::Vector2f pos) { textbox.setPosition(pos); }
  void setLimit(bool Tof) { hasLimit = Tof; }
  void setLimit(bool ToF, int lim) {
    hasLimit = ToF;
    limit = lim - 1;
  }
  void setSeclected(bool sel) {
    isSelected = sel;
    if (!sel) {
      std::string t = text.str();
      std::string newT = "";
      for (int i = 0; i < t.length(); i++) {
        newT += t[i];
      }
      textbox.setString(newT);
    }
  }

  std::string getText() { return text.str(); }

  void drawTo(sf::RenderWindow &window) { window.draw(textbox); }
  void typedOn(sf::Event input) {
    if (isSelected) {
      int charTyped = input.text.unicode;
      if (charTyped < 128) {  // typing input abuse proof
        if (hasLimit) {
          if (text.str().length() <= limit) { // check limit
            inputLogic(charTyped);
          } else if (text.str().length() > limit && charTyped == DELETE_KEY) {
            deleteLadtChar();
          }
        } else {
          inputLogic(charTyped);
        }
      }
    }
  }

 private:
  sf::Text textbox;
  std::ostringstream text;
  bool isSelected = false;
  bool hasLimit = false;
  int limit;

  // Char input if key is not special key
  void inputLogic(int charTyped) {
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY &&
        charTyped != ESCAPE_KEY) {
      text << static_cast<char>(charTyped);
    } else if (charTyped == DELETE_KEY) {
      if (text.str().length() > 0) {
        deleteLadtChar();
      }
    }
    textbox.setString(text.str() + "_");
  }
  // Char delete function
  void deleteLadtChar() {
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++) {
      newT += t[i];
    }
    text.str("");  // Initialize before reassign
    text << newT;

    textbox.setString(text.str());
  }
};