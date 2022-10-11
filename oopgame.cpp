#include <SFML/Graphics.hpp>
#include <string>

#include "player.h"
using namespace sf;

class OOPGame {
 private:
  sf::RenderWindow *window;
  Player *player;

 public:
  OOPGame(int size, std::string title) {
    window = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
  }
  void run() {
    while (window->isOpen()) {
      Event event;
      while (window->pollEvent(event)) {
        if (event.type == Event::Closed) {
          window->close();
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
          player->move_left(6);
        } else if (Keyboard::isKeyPressed(Keyboard::D)) {
          player->move_right(6);
        } else if (Keyboard::isKeyPressed(Keyboard::W)) {
          player->move_up(6);
        } else if (Keyboard::isKeyPressed(Keyboard::S)) {
          player->move_down(6);
        }
      }
      window->clear();
      player->draw(window);
      window->display();
    }
  }
  ~OOPGame() {}
};

int main() {
  OOPGame game(500, "OOP GAME");
  game.run();

  return 0;
}