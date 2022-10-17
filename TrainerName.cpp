#include "stdInclude.h"

string TrainerName() {
  cout << "Registering trainer's name." << endl;
  // SFML RenderWindow
  sf::RenderWindow window;
  sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
                            (sf::VideoMode::getDesktopMode().height / 2) - 480);

  window.create(sf::VideoMode(720, 540), "OOP Project Pokemon",
                sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(centerWindow);
  window.setKeyRepeatEnabled(true);

  // Welcome to OOP Pokemon
  sf::Texture menueBackGround;  // Load background texture
  menueBackGround.loadFromFile("Resources/battleFieldWithBall.png");
  sf::Sprite menueBackGroundSprite;
  menueBackGroundSprite.setTexture(menueBackGround);
  menueBackGroundSprite.setPosition(sf::Vector2f(-4, -208));
  menueBackGroundSprite.scale(sf::Vector2f(0.33, 0.33));
  // Set font
  sf::Font courierNew;
  courierNew.loadFromFile("Resources/Courier New Regular.ttf");
  sf::Text welcomeMessage;
  welcomeMessage.setFont(courierNew);
  welcomeMessage.setCharacterSize(66);
  welcomeMessage.setColor(sf::Color::White);
  welcomeMessage.setOutlineColor(sf::Color::Black);
  welcomeMessage.setOutlineThickness(3);
  welcomeMessage.setPosition(151.4, 216);
  welcomeMessage.setString("OOP Pokemon");
  // Make typing box
  Textbox traiName(30, sf::Color::Black, true);
  traiName.setFont(courierNew);
  traiName.setPosition({40, 470});
  traiName.setLimit(true, 29);
  // Import and make Pokemons' sprites
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
  // Make buttons
  Button confirmButton("CONFIRM", {100, 40}, 20, sf::Color::Green,
                       sf::Color::Black);
  confirmButton.setFont(courierNew);
  confirmButton.setPosition({580, 420});
  Button exitButton("EXIT", {100, 40}, 20, sf::Color::Green, sf::Color::Black);
  exitButton.setFont(courierNew);
  exitButton.setPosition({580, 470});
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
  // Check time greeting
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int hour = ltm->tm_hour;
  if (hour < 12) {
    userInteractMessage.setString(
        "Good morning trainer!\nPlease enter your nick name: ");
  } else if (hour == 12) {
    userInteractMessage.setString(
        "Good noon trainer!\nPlease enter your nick name: ");
  } else if (hour < 18) {
    userInteractMessage.setString(
        "Good afternoon trainer!\nPlease enter your nick name: ");
  } else if (hour >= 18 && hour < 24) {
    userInteractMessage.setString(
        "Good evening trainer!\nPlease enter your nick name: ");
  } else {
    userInteractMessage.setString(
        "Hello! Good midnight trainer!\nPlease enter your nick name: ");
  }

  // Window Loop
  while (window.isOpen()) {
    sf::Event event;
    // Event Poll Loop
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
        case sf::Event::TextEntered:
          traiName.typedOn(event);
          break;
          // Mouse moves check isMouseOver buttons
        case sf::Event::MouseMoved:
          if (confirmButton.isMouseOver(window)) {
            confirmButton.setBackColor(sf::Color::Red);
          } else {
            confirmButton.setBackColor(sf::Color::Green);
          }
          if (exitButton.isMouseOver(window)) {
            exitButton.setBackColor(sf::Color::White);
          } else {
            exitButton.setBackColor(sf::Color::Green);
          }
          break;
          // Check button pressed
        case sf::Event::MouseButtonPressed:
          if (confirmButton.isMouseOver(window)) {
            string trainerName = "";
            trainerName = traiName.getText();
            if (trainerName != "") {
              std::cout << "CONFIRM\n";
              cout << "Trainer's name is: " << trainerName << endl;
              window.close();
              PokemonMenu(trainerName);
            }
          } else if (exitButton.isMouseOver(window)) {
            std::cout << "EXIT\n";
            window.close();
          }
          break;
          // Press Escape key to get back to previous state
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) {
            window.close();
            WelcomeState();
            std::cout << "Escape Pressed" << std::endl;
          } else if (event.key.code == sf::Keyboard::Enter) {
            string trainerName = "";
            trainerName = traiName.getText();
            if (trainerName != "") {
              std::cout << "ENTER\n";
              cout << "Trainer's name is: " << trainerName << endl;
              window.close();
              PokemonMenu(trainerName);
            }
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
    window.draw(userInteractSprite);
    window.draw(userInteractMessage);
    window.draw(charizardSprite);
    window.draw(blastoiseSprite);
    window.draw(venusaurSprite);
    // Draw typing box
    traiName.drawTo(window);
    // Draw button
    confirmButton.drawTo(window);
    exitButton.drawTo(window);
    window.display();  // Tell app that window is done drawing
    Textbox traiName(30, sf::Color::Black, false);
  }
  return 0;
}