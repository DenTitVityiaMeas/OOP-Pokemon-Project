#include "stdInclude.h"
#include "Button.h"
#include "Textbox.h"
#include "PopUp.h"


int main() {
  sf::RenderWindow window;

  sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
                            (sf::VideoMode::getDesktopMode().height / 2) - 480);

  window.create(sf::VideoMode(720, 540), "OOP Project Pokemon",
                sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(centerWindow);

  window.setKeyRepeatEnabled(true);
  sf::Texture menueBackGround;  // Load background texture
  if (!menueBackGround.loadFromFile("Resources/battleField.jpg")) {
    std::cout << "Could not load menueBackGround texture";
    return 0;
  }
  sf::Sprite menueBackGroundSprite;
  menueBackGroundSprite.setTexture(menueBackGround);
  menueBackGroundSprite.setPosition(sf::Vector2f(0, -360));
  menueBackGroundSprite.scale(sf::Vector2f(0.3, 0.3));

  sf::Texture charizardF;  // Load texture
  if (!charizardF.loadFromFile("Resources/charizard-f.png")) {
    std::cout << "Could not load charizard-f texture";
    return 0;
  }
  sf::Sprite charizardSprite;
  charizardSprite.setTexture(charizardF);
  charizardSprite.setPosition(sf::Vector2f(520, 20));
  charizardSprite.scale(sf::Vector2f(2, 2));

  sf::Texture blastoiseF;
  if (!blastoiseF.loadFromFile("Resources/blastoise-f.png")) {
    std::cout << "Could not load blastoise-f texture";
    return 0;
  }
  sf::Sprite blastoiseSprite;
  blastoiseSprite.setTexture(blastoiseF);
  blastoiseSprite.setPosition(sf::Vector2f(270, 10));
  blastoiseSprite.scale(sf::Vector2f(2, 2));

  sf::Texture venusaurF;
  if (!venusaurF.loadFromFile("Resources/venusaur-f.png")) {
    std::cout << "Could not load venusaur-f.png texture";
    return 0;
  }
  sf::Sprite venusaurSprite;
  venusaurSprite.setTexture(venusaurF);
  venusaurSprite.setPosition(sf::Vector2f(20, 20));
  venusaurSprite.scale(sf::Vector2f(2, 2));

  sf::Font courierNew;  // set font for sfml
  courierNew.loadFromFile("Courier New Regular.ttf");
  Textbox textbox1(15, sf::Color::Black, false);
  textbox1.setFont(courierNew);
  textbox1.setPosition({100, 100});
  textbox1.setLimit(true, 20);

  Button startButton("START", {200, 50}, 30, sf::Color::Green,
                     sf::Color::Black);
  startButton.setFont(courierNew);
  startButton.setPosition({270, 270});
  Button loadButton("LOAD", {200, 50}, 30, sf::Color::Green, sf::Color::Black);
  loadButton.setFont(courierNew);
  loadButton.setPosition({270, 360});
  Button exitButton("EXIT", {200, 50}, 30, sf::Color::Green, sf::Color::Black);
  exitButton.setFont(courierNew);
  exitButton.setPosition({270, 450});
   

  
  // Window Loop
  while (window.isOpen()) {
    sf::Event event;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
      textbox1.setSeclected(true);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      textbox1.setSeclected(false);
    }
    // Event Poll Loop
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
        case sf::Event::TextEntered:
          textbox1.typedOn(event);
          break;
        case sf::Event::MouseMoved:
          if (startButton.isMouseOver(window)) {
            startButton.setBackColor(sf::Color::Red);
          } else {
            startButton.setBackColor(sf::Color::Green);
          }
          if (loadButton.isMouseOver(window)) {
            loadButton.setBackColor(sf::Color::Yellow);
          } else {
            loadButton.setBackColor(sf::Color::Green);
          }
          if (exitButton.isMouseOver(window)) {
            exitButton.setBackColor(sf::Color::Blue);
          } else {
            exitButton.setBackColor(sf::Color::Green);
          }
          break;
        case sf::Event::MouseButtonPressed:
          if (startButton.isMouseOver(window)) {
            std::cout << "START\n";
            

          } else if (loadButton.isMouseOver(window)) {
            std::cout << "LOAD\n";
          } else if (exitButton.isMouseOver(window)) {
            std::cout << "EXIT\n";
            window.close();
          }
          break;
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape)
            // call setting window
            break;
      }
    }

    // Update

    // Render
    window.clear();  // clear previous window    
    window.draw(menueBackGroundSprite);
    window.draw(charizardSprite);
    window.draw(blastoiseSprite);
    window.draw(venusaurSprite);
    textbox1.drawTo(window);
    startButton.drawTo(window);
    loadButton.drawTo(window);
    exitButton.drawTo(window);
    window.display();  // Tell app that window is done drawing
  }
  return 0;
}