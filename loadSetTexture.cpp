#include "stdInclude.h"

sf::Sprite loadSetTexture(string fileName, float posX, float posY, float scaleX,
                          float scaleY) {
  sf::Texture texture;
  if (!texture.loadFromFile(fileName)) {
    cout << "Could not load " << fileName << endl;
  }
  sf::Sprite textureSprite;
  textureSprite.setTexture(texture);
  textureSprite.setPosition(sf::Vector2f(posX, posY));
  textureSprite.scale(sf::Vector2f(scaleX, scaleY));
  return textureSprite;
}