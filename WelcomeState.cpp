#include "stdInclude.h"

void WelcomeState() {
  cout << "You're in WelcomeState" << endl;

  // SFML RenderWindow
  sf::RenderWindow window;
  sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
                            (sf::VideoMode::getDesktopMode().height / 2) - 480);

  window.create(sf::VideoMode(720, 540), "OOP Project Pokemon",
                sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(centerWindow);

  // Welcome to OOP Pokemon
  sf::Texture menueBackGround;  // Load background texture
  menueBackGround.loadFromFile("Resources/battleFieldWithBall.png");
  sf::Sprite menueBackGroundSprite;
  menueBackGroundSprite.setTexture(menueBackGround);
  menueBackGroundSprite.setPosition(sf::Vector2f(-4, -208));
  menueBackGroundSprite.scale(sf::Vector2f(0.33, 0.33));

  sf::Font courierNew;  // set font for sfml
  courierNew.loadFromFile("Resources/Courier New Regular.ttf");
  sf::Text welcomeMessage;
  welcomeMessage.setFont(courierNew);
  welcomeMessage.setCharacterSize(66);
  welcomeMessage.setColor(sf::Color::White);
  welcomeMessage.setOutlineColor(sf::Color::Black);
  welcomeMessage.setOutlineThickness(3);
  welcomeMessage.setPosition(151.4, 216);
  welcomeMessage.setString("OOP Pokemon");

  sf::Texture charizardF;
  charizardF.loadFromFile("Resources/charizard-f.png");
  sf::Sprite charizardSprite;
  charizardSprite.setTexture(charizardF);
  charizardSprite.setPosition(sf::Vector2f(520, 10));
  charizardSprite.scale(sf::Vector2f(2, 2));

  sf::Texture blastoiseF;
  blastoiseF.loadFromFile("Resources/blastoise-f.png");
  sf::Sprite blastoiseSprite;
  blastoiseSprite.setTexture(blastoiseF);
  blastoiseSprite.setPosition(sf::Vector2f(270, 10));
  blastoiseSprite.scale(sf::Vector2f(2, 2));

  sf::Texture venusaurF;
  venusaurF.loadFromFile("Resources/venusaur-f.png");
  sf::Sprite venusaurSprite;
  venusaurSprite.setTexture(venusaurF);
  venusaurSprite.setPosition(sf::Vector2f(20, 10));
  venusaurSprite.scale(sf::Vector2f(2, 2));

  Button startButton("START", {200, 50}, 30, sf::Color::Green,
                     sf::Color::Black);
  startButton.setFont(courierNew);
  startButton.setPosition({270, 390});
  Button exitButton("EXIT", {200, 50}, 30, sf::Color::Green, sf::Color::Black);
  exitButton.setFont(courierNew);
  exitButton.setPosition({270, 460});

  // Window Loop
  while (window.isOpen()) {
    sf::Event event;
    // Event Poll Loop
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
        case sf::Event::MouseMoved:
          if (startButton.isMouseOver(window)) {
            startButton.setBackColor(sf::Color::Red);
          } else {
            startButton.setBackColor(sf::Color::Green);
          }
          if (exitButton.isMouseOver(window)) {
            exitButton.setBackColor(sf::Color::White);
          } else {
            exitButton.setBackColor(sf::Color::Green);
          }
          break;
        case sf::Event::MouseButtonPressed:
          if (startButton.isMouseOver(window)) {
            window.close();
            TrainerName();
          } else if (exitButton.isMouseOver(window)) {
            std::cout << "EXIT\n";
            window.close();
          }
          break;
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Enter) {
            std::cout << "ENTER\n";
            window.close();
            TrainerName();
          }
          break;
      }
    }
    // Update

    // Render
    window.clear();  // clear previous window
    // Draw Sprite
    window.draw(menueBackGroundSprite);
    window.draw(welcomeMessage);
    window.draw(charizardSprite);
    window.draw(blastoiseSprite);
    window.draw(venusaurSprite);
    // Draw button
    startButton.drawTo(window);
    exitButton.drawTo(window);
    window.display();  // Tell app that window is done drawing
  }
}
