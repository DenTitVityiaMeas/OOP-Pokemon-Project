#include "stdInclude.h"

void Result(bool win, char pokemon, string trainerName) {
  sf::RenderWindow window;
  sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
                            (sf::VideoMode::getDesktopMode().height / 2) - 480);

  window.create(sf::VideoMode(720, 540), "OOP Project Pokemon",
                sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(centerWindow);
  sf::Font courierNew;  // set font for sfml
  courierNew.loadFromFile("Resources/Courier New Regular.ttf");

  sf::Texture menueBackGround;  // Load background texture
  menueBackGround.loadFromFile("Resources/battleFieldOG.jpg");
  sf::Sprite menueBackGroundSprite;
  menueBackGroundSprite.setTexture(menueBackGround);
  menueBackGroundSprite.setPosition(sf::Vector2f(-160, -408));
  menueBackGroundSprite.scale(sf::Vector2f(0.33, 0.33));

  sf::Text youWon;
  youWon.setFont(courierNew);
  youWon.setCharacterSize(88);
  youWon.setColor(sf::Color::Red);
  youWon.setOutlineColor(sf::Color::Black);
  youWon.setOutlineThickness(4);
  youWon.setPosition(130, 10);
  youWon.setString("YOU WON!!");
  sf::Text youLost;
  youLost.setFont(courierNew);
  youLost.setCharacterSize(88);
  youLost.setColor(sf::Color::Red);
  youLost.setOutlineColor(sf::Color::Black);
  youLost.setOutlineThickness(4);
  youLost.setPosition(130, 10);
  youLost.setString("YOU LOST");

  sf::Texture charizardF;
  charizardF.loadFromFile("Resources/charizard-f.png");
  sf::Sprite charizardSprite;
  charizardSprite.setTexture(charizardF);
  charizardSprite.setPosition(sf::Vector2f(260, 100));
  charizardSprite.scale(sf::Vector2f(2.4, 2.4));

  sf::Texture blastoiseF;
  blastoiseF.loadFromFile("Resources/blastoise-f.png");
  sf::Sprite blastoiseSprite;
  blastoiseSprite.setTexture(blastoiseF);
  blastoiseSprite.setPosition(sf::Vector2f(260, 100));
  blastoiseSprite.scale(sf::Vector2f(2.6, 2.6));

  sf::Texture venusaurF;
  venusaurF.loadFromFile("Resources/venusaur-f.png");
  sf::Sprite venusaurSprite;
  venusaurSprite.setTexture(venusaurF);
  venusaurSprite.setPosition(sf::Vector2f(260, 120));
  venusaurSprite.scale(sf::Vector2f(2.2, 2.2));

  sf::Texture geninjaF;
  geninjaF.loadFromFile("Resources/greninjaF.png");
  sf::Sprite geninjaFSprite;
  geninjaFSprite.setTexture(geninjaF);
  geninjaFSprite.setPosition(sf::Vector2f(260, 100));
  geninjaFSprite.scale(sf::Vector2f(2, 2));

  // Button
  Button pokenmonSel("Pokemon Selection", {210, 60}, 20, sf::Color::Green,
                     sf::Color::Black);
  pokenmonSel.setFont(courierNew);
  pokenmonSel.setPosition({30, 320});
  Button newPlayer("New Player", {210, 60}, 20, sf::Color::Green,
                   sf::Color::Black);
  newPlayer.setFont(courierNew);
  newPlayer.setPosition({260, 320});
  Button exitButton("EXIT", {210, 60}, 20, sf::Color::Green, sf::Color::Black);
  exitButton.setFont(courierNew);
  exitButton.setPosition({490, 320});

  // User interacting message
  sf::Texture userInteractMessageBox;
  userInteractMessageBox.loadFromFile("Resources/message.jpg");
  sf::Sprite userInteractSprite;
  userInteractSprite.setTexture(userInteractMessageBox);
  userInteractSprite.setPosition(sf::Vector2f(4, 396));
  userInteractSprite.scale(sf::Vector2f(2.08, 1.3));
  sf::Text userInteractMessage;
  userInteractMessage.setFont(courierNew);
  userInteractMessage.setCharacterSize(20);
  userInteractMessage.setColor(sf::Color::Black);
  userInteractMessage.setPosition(40, 420);
  switch (win) {
    case 1:
      userInteractMessage.setString("Trainer " + trainerName +
                                    "\nYou have won the battle.");
      break;
    case 0:
      userInteractMessage.setString(
          "Trainer " + trainerName +
          "\nYou have lost the battle\nKeep on training.");
  }

  // Window Loop
  while (window.isOpen()) {
    sf::Event event;
    // Event Poll Loop
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
        case sf::Event::MouseMoved:
          if (pokenmonSel.isMouseOver(window)) {
            pokenmonSel.setBackColor(sf::Color::Yellow);
          } else {
            pokenmonSel.setBackColor(sf::Color::Green);
          }
          if (newPlayer.isMouseOver(window)) {
            newPlayer.setBackColor(sf::Color::Blue);
          } else {
            newPlayer.setBackColor(sf::Color::Green);
          }
          if (exitButton.isMouseOver(window)) {
            exitButton.setBackColor(sf::Color::Red);
          } else {
            exitButton.setBackColor(sf::Color::Green);
          }
          break;
        case sf::Event::MouseButtonPressed:
          if (pokenmonSel.isMouseOver(window)) {
            window.close();
            PokemonMenu(trainerName);
          } else if (newPlayer.isMouseOver(window)) {
            window.close();
            TrainerName();
          } else if (exitButton.isMouseOver(window)) {
            std::cout << "EXIT\n";
            window.close();
            break;
          }
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
    pokenmonSel.drawTo(window);
    newPlayer.drawTo(window);
    exitButton.drawTo(window);
    // Draw Sprite

    switch (win) {
      case 1:
        window.draw(youWon);
        switch (pokemon) {
          case 'g':
            window.draw(venusaurSprite);
            break;
          case 'w':
            window.draw(blastoiseSprite);
            break;
          case 'f':
            window.draw(charizardSprite);
            break;
        }
        break;
      case 0:
        window.draw(youLost);
        window.draw(geninjaFSprite);
        break;
    }
    window.display();
  }
}