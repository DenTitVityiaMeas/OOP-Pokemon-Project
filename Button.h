#include "stdInclude.h"

class Button {
 public:
  Button() {}
  ~Button(){}

  Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor,
         sf::Color textColor) {
    text.setString(t);
    text.setColor(textColor);
    text.setCharacterSize(charSize);
    button.setSize(size);
    button.setFillColor(bgColor);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(1);
  }
  void setFont(sf::Font &font) { text.setFont(font); }    //sfml text methods
  void setBackColor(sf::Color color) { button.setFillColor(color); }
  void setTextColor(sf::Color color) { text.setColor(color); }
  void setPosition(sf::Vector2f pos) {    //coordinate button according to globalbounds
    button.setPosition(pos);
    float xPos = (pos.x + button.getGlobalBounds().width / 2) -
                 (text.getGlobalBounds().width / 2);
    float yPos = (pos.y + button.getGlobalBounds().height / 2) -
                 (text.getGlobalBounds().height / 2);
    text.setPosition({xPos-1, yPos-10});
  }
  void drawTo(sf::RenderWindow &window) {   //auto polimophism by sf
    window.draw(button);
    window.draw(text);
  }
  bool isMouseOver(sf::RenderWindow &window) {    //mouse is over the button
    float mouseX = sf::Mouse::getPosition(window).x;    //get mouse pos from sf
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = button.getPosition().x;   //btn x y componants
    float btnPosY = button.getPosition().y;

    float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;    //set button boundry
    float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight &&    //check if the mouse pos with in the btn pos
        mouseY > btnPosY) {
      return true;
    }
    return false;
  }

 private:
  sf::RectangleShape button;
  sf::Text text;
};