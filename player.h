#include <SFML/Graphics.hpp>

class Player {
 private:
  sf::CircleShape *body;

 public:
  Player(int r, int x, int y) {
    body = new sf::CircleShape();
    body->setRadius(r);
    body->setPosition(x, y);
    body->setFillColor((sf::Color::Green));
    body->setOrigin(r / 2, r / 2);
  }
  void draw(sf::RenderWindow *window) { window->draw(*body); }
  void move_right(int speed) { body->move(speed, 0); }
  void move_left(int speed) { body->move(-speed, 0); }
  void move_up(int speed) { body->move(0, -speed); }
  void move_down(int speed) { body->move(0, speed); }

  ~Player() {}
};