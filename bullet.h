#include <SFML/Graphics.hpp>

class Bullet {
 private:
  sf::RectangleShape *bulletBody;
  bool fired;

 public:
  Bullet() {
    bulletBody = new sf::RectangleShape(sf::Vector2f(10, 5));
    bulletBody->getFillColor(sf::Color::Red);
    bulletBody->setPosition(-1, -1);
    fired = false;
  }
  void draw(sf::RenderWindow *window) { window->draw(bulletBody); }
  void set_position(sf::Vector2f position) {
    bulletBody->setPosition(position);
  }
  void move() { bulletBody->move(0.5, 0); }
  bool isFired() { return fired; }
  void use(sf::Vector2f position) {
    bulletBody->setPosition(position);
    fired = true;
  }
  ~Bullet() {}
};