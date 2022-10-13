#include "stdInclude.h"

int main() {
  sf::RenderWindow window;

  sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
                            (sf::VideoMode::getDesktopMode().height / 2) - 480);

  window.create(sf::VideoMode(720, 540), "OOP Project Pokemon",
                sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(centerWindow);

  // Welcome to OOP Pokemon
  sf::Texture menueBackGround;  // Load background texture
  if (!menueBackGround.loadFromFile(
          "Resources/battleFieldWithBall.png")) {  // load texture
    std::cout << "Could not load menueBackGround texture";
    return 0;
  }
  sf::Sprite menueBackGroundSprite;
  menueBackGroundSprite.setTexture(menueBackGround);
  menueBackGroundSprite.setPosition(sf::Vector2f(-4, -208));
  menueBackGroundSprite.scale(sf::Vector2f(0.33, 0.33));

  sf::Font courierNew;  // set font for sfml
  if (!courierNew.loadFromFile(
          "Resources/Courier New Regular.ttf")) {  // load texture
    std::cout << "Could not load Courier New Regular.ttf";
    return 0;
  }
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
            std::cout << "START\n";

            Button VenusaurButton("Venusaur", {200, 360}, 30,
                                  sf::Color(200, 255, 200), sf::Color::Black);
            VenusaurButton.setFont(courierNew);
            VenusaurButton.setPosition({20, 20});
            Button BlastoiseButton("Blastoise", {200, 360}, 30,
                                   sf::Color(200, 200, 255), sf::Color::Black);
            BlastoiseButton.setFont(courierNew);
            BlastoiseButton.setPosition({260, 20});
            Button CharizardButton("Charizard", {200, 360}, 30,
                                   sf::Color(255, 200, 200), sf::Color::Black);
            CharizardButton.setFont(courierNew);
            CharizardButton.setPosition({500, 20});
            Button exitButton("EXIT", {100, 40}, 30, sf::Color::White,
                              sf::Color::Black);
            exitButton.setFont(courierNew);
            exitButton.setPosition({580, 470});
            // Pokemon sumarry status
            sf::Text venesaurSummary;
            venesaurSummary.setFont(courierNew);
            venesaurSummary.setCharacterSize(20);
            venesaurSummary.setColor(sf::Color::Black);
            venesaurSummary.setOutlineColor(sf::Color::White);
            venesaurSummary.setOutlineThickness(1);
            venesaurSummary.setPosition(30, 240);
            venesaurSummary.setString(
                "HP: 12\nAttack: 1\nS.Attack: 3\nDeffence: 3\nElement: Grass");
            sf::Text blastoiseSummary;
            blastoiseSummary.setFont(courierNew);
            blastoiseSummary.setCharacterSize(20);
            blastoiseSummary.setColor(sf::Color::Black);
            blastoiseSummary.setOutlineColor(sf::Color::White);
            blastoiseSummary.setOutlineThickness(1);
            blastoiseSummary.setPosition(270, 240);
            blastoiseSummary.setString(
                "HP: 11\nAttack: 2\nS.Attack: 4\nDeffence: 2\nElement: Water");
            sf::Text charizardSummary;
            charizardSummary.setFont(courierNew);
            charizardSummary.setCharacterSize(20);
            charizardSummary.setColor(sf::Color::Black);
            charizardSummary.setOutlineColor(sf::Color::White);
            charizardSummary.setOutlineThickness(1);
            charizardSummary.setPosition(510, 240);
            charizardSummary.setString(
                "HP: 10\nAttack: 3\nS.Attack: 5\nDeffence: 1\nElement: Fire");
            // User interacting message
            sf::Texture userInteractMessageBox;
            userInteractMessageBox.loadFromFile("Resources/message.jpg");
            sf::Sprite userInteractSprite;
            userInteractSprite.setTexture(userInteractMessageBox);
            userInteractSprite.setPosition(sf::Vector2f(4, 396));
            userInteractSprite.scale(sf::Vector2f(2.08, 1.3));
            sf::Text userInteractMessage;
            userInteractMessage.setFont(courierNew);
            userInteractMessage.setCharacterSize(18);
            userInteractMessage.setColor(sf::Color::Black);
            userInteractMessage.setPosition(35, 420);
            userInteractMessage.setString(
                "Please pick a Pokemon for the battle.");

            // Window Loop
            while (window.isOpen()) {
              sf::Event event;
              // Event Poll Loop
              while (window.pollEvent(event)) {
                switch (event.type) {
                  case sf::Event::Closed:
                    window.close();
                  case sf::Event::MouseMoved:
                    if (VenusaurButton.isMouseOver(window)) {
                      VenusaurButton.setBackColor(sf::Color(100, 255, 100));
                    } else {
                      VenusaurButton.setBackColor(sf::Color(200, 255, 200));
                    }
                    if (BlastoiseButton.isMouseOver(window)) {
                      BlastoiseButton.setBackColor(sf::Color(100, 100, 255));
                    } else {
                      BlastoiseButton.setBackColor(sf::Color(200, 200, 255));
                    }
                    if (CharizardButton.isMouseOver(window)) {
                      CharizardButton.setBackColor(sf::Color(255, 100, 100));
                    } else {
                      CharizardButton.setBackColor(sf::Color(255, 200, 200));
                    }
                    if (exitButton.isMouseOver(window)) {
                      exitButton.setBackColor(sf::Color::Red);
                    } else {
                      exitButton.setBackColor(sf::Color::White);
                    }
                    break;
                  case sf::Event::MouseButtonPressed:
                    if (VenusaurButton.isMouseOver(window)) {
                      std::cout << "Venusaur\n";
                    } else if (BlastoiseButton.isMouseOver(window)) {
                      std::cout << "Blastoise\n";
                    } else if (CharizardButton.isMouseOver(window)) {
                      std::cout << "Charizard\n";
                    } else if (exitButton.isMouseOver(window)) {
                      std::cout << "EXIT\n";
                      window.close();
                    }
                    break;
                  case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                      // call setting window
                      std::cout << "Escape Pressed" << std::endl;
                    break;
                }
              }

              // Update

              // Render
              window.clear();  // clear previous window
              window.draw(menueBackGroundSprite);
              window.draw(userInteractSprite);
              window.draw(userInteractMessage);
              // Draw button
              VenusaurButton.drawTo(window);
              BlastoiseButton.drawTo(window);
              CharizardButton.drawTo(window);
              exitButton.drawTo(window);
              // Draw Sprite
              window.draw(charizardSprite);
              window.draw(blastoiseSprite);
              window.draw(venusaurSprite);
              // Draw text
              window.draw(venesaurSummary);
              window.draw(blastoiseSummary);
              window.draw(charizardSummary);

              window.display();  // Tell app that window is done drawing
            }

          } else if (exitButton.isMouseOver(window)) {
            std::cout << "EXIT\n";
            window.close();
          }
          break;
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape)
            // call setting window
            std::cout << "Escape Pressed" << std::endl;
          break;
      }
    }

    // Update

    // Render
    window.clear();  // clear previous window
    window.draw(menueBackGroundSprite);
    window.draw(welcomeMessage);
    window.draw(charizardSprite);
    window.draw(blastoiseSprite);
    window.draw(venusaurSprite);
    startButton.drawTo(window);
    exitButton.drawTo(window);
    window.display();  // Tell app that window is done drawing
  }
  return 0;
}