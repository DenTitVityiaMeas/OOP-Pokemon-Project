#include "stdInclude.h"

sf::Text printText(string string, unsigned int size, float tOuterThick, float posX,
                   float posY) {
  sf::Font courierNew;  // set font for sfml
  courierNew.loadFromFile("Resources/Courier New Regular.ttf");
  sf::Text text;
  text.setFont(courierNew);
  text.setString(string);
  text.setCharacterSize(size);
  text.setOutlineThickness(tOuterThick);
  text.setPosition(posX, posY);

  return text;
}