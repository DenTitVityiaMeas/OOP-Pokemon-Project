#include "stdInclude.h"

void BattleBulVsGren(string trainerName) {
  Charizard Charizard;
  Blastoise Blastoise;
  Bulbasaur Bulbasaur;
  // Heal,Element,Speed,Name,Armor
  Pokemon Geninja(8, 1, 3, "Geninja", 0), Metapod(8, 1, 3, "Metapod", 0);
  Pokemon Pokemon_array[2] = {Geninja, Metapod};
  int i = rand() % 2 + 1;

  // SFML RenderWindow
  sf::RenderWindow window;
  sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
                            (sf::VideoMode::getDesktopMode().height / 2) - 480);

  window.create(sf::VideoMode(720, 540), "OOP Project Pokemon",
                sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(centerWindow);

  // Welcome to OOP Pokemon
  sf::Texture menueBackGround;  // Load background texture
  menueBackGround.loadFromFile("Resources/battleFieldOG.jpg");
  sf::Sprite menueBackGroundSprite;
  menueBackGroundSprite.setTexture(menueBackGround);
  menueBackGroundSprite.setPosition(sf::Vector2f(-160, -408));
  menueBackGroundSprite.scale(sf::Vector2f(0.33, 0.33));

  sf::Font courierNew;  // set font for sfml
  courierNew.loadFromFile("Resources/Courier New Regular.ttf");

  sf::Texture venusaurB;
  venusaurB.loadFromFile("Resources/venusaur-b.png");
  sf::Sprite venusaurSprite;
  venusaurSprite.setTexture(venusaurB);
  venusaurSprite.setPosition(sf::Vector2f(20, 230));
  venusaurSprite.scale(sf::Vector2f(2.2, 2.2));

  sf::Texture geninjaF;
  geninjaF.loadFromFile("Resources/greninjaF.png");
  sf::Sprite geninjaFSprite;
  geninjaFSprite.setTexture(geninjaF);
  geninjaFSprite.setPosition(sf::Vector2f(440, 10));
  geninjaFSprite.scale(sf::Vector2f(2, 2));

  // Make buttons
  Button m1(Bulbasaur.M1.getMoveName(), {120, 40}, 16, sf::Color::Green,
            sf::Color::Black);
  m1.setFont(courierNew);
  m1.setPosition({435, 420});
  Button m2(Bulbasaur.M2.getMoveName(), {120, 40}, 16, sf::Color::Green,
            sf::Color::Black);
  m2.setFont(courierNew);
  m2.setPosition({565, 420});
  Button m3(Bulbasaur.M3.getMoveName(), {120, 40}, 16, sf::Color::Green,
            sf::Color::Black);
  m3.setFont(courierNew);
  m3.setPosition({435, 470});
  Button m4(Bulbasaur.M4.getMoveName(), {120, 40}, 16, sf::Color::Green,
            sf::Color::Black);
  m4.setFont(courierNew);
  m4.setPosition({565, 470});

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
  string currentMessage =
      "Trainer\nyou are battling with Greninja\nplease command a move.";
  userInteractMessage.setString(currentMessage);

  // Status bar
  int statusAllignmentAX = 280;
  int statusAllignmentAY = 320;
  int statusAllignmentBX = 60;
  int statusAllignmentBY = 60;
  // StatusBox A
  sf::Texture statusBoxA;
  statusBoxA.loadFromFile("Resources/statusBarR.png");
  sf::Sprite statusBoxSpriteA;
  statusBoxSpriteA.setTexture(statusBoxA);
  statusBoxSpriteA.setPosition(
      sf::Vector2f(statusAllignmentAX, statusAllignmentAY));
  statusBoxSpriteA.scale(sf::Vector2f(0.15, 0.15));
  sf::Text statusA;
  statusA.setFont(courierNew);
  statusA.setCharacterSize(20);
  statusA.setColor(sf::Color::Black);
  statusA.setPosition(statusAllignmentAX + 40, statusAllignmentAY - 7);
  statusA.setString("Bulbasaur  Element: Grass\nHP: 10\tSpeed: 7");
  sf::RectangleShape hpBarA;
  hpBarA.setFillColor(sf::Color::Green);
  hpBarA.setOutlineThickness(1);
  hpBarA.setOutlineColor(sf::Color::Black);
  hpBarA.setPosition(statusAllignmentAX + 112, statusAllignmentAY + 42);
  // StatusBox B
  sf::Texture statusBoxB;
  statusBoxB.loadFromFile("Resources/statusBarL.png");
  sf::Sprite statusBoxSpriteB;
  statusBoxSpriteB.setTexture(statusBoxB);
  statusBoxSpriteB.setPosition(
      sf::Vector2f(statusAllignmentBX, statusAllignmentBY));
  statusBoxSpriteB.scale(sf::Vector2f(0.15, 0.15));
  sf::Text statusB;
  statusB.setFont(courierNew);
  statusB.setCharacterSize(20);
  statusB.setColor(sf::Color::Black);
  statusB.setPosition(statusAllignmentBX + 30, statusAllignmentBY - 8);
  // hpBar B
  sf::RectangleShape hpBarB;
  hpBarB.setFillColor(sf::Color::Green);
  hpBarB.setOutlineThickness(1);
  hpBarB.setOutlineColor(sf::Color::Black);
  hpBarB.setPosition(statusAllignmentBX + 106, statusAllignmentBY + 41);
  statusB.setString("Greninja  Element: Water\nHP: 8\tSpeed: 3");
  int skillAvailable = 1;
  int round = 1;
  // Window Loop
  while (window.isOpen()) {
    sf::Event event;
    // Event Poll Loop
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
        case sf::Event::MouseButtonPressed:
          if (m1.isMouseOver(window)) {
            if (skillAvailable == 1) {
              battleG(skillAvailable, round, Bulbasaur, Geninja, 1,
                      trainerName);
            } else if (skillAvailable == 0) {
              battleG(skillAvailable, round, Bulbasaur, Geninja, 1,
                      trainerName);
            }
            round++;
          } else if (m2.isMouseOver(window)) {
            if (skillAvailable == 1) {
              battleG(skillAvailable, round, Bulbasaur, Geninja, 2,
                      trainerName);
            } else if (skillAvailable == 0) {
              battleG(skillAvailable, round, Bulbasaur, Geninja, 2,
                      trainerName);
            }
            round++;
          } else if (m3.isMouseOver(window)) {
            if (skillAvailable == 1) {
              battleG(skillAvailable, round, Bulbasaur, Geninja, 3,
                      trainerName);
              round++;
              skillAvailable = 0;
            }
          } else if (m4.isMouseOver(window)) {
            if (skillAvailable == 1) {
              battleG(skillAvailable, round, Bulbasaur, Geninja, 4,
                      trainerName);
            } else if (skillAvailable == 0) {
              battleG(skillAvailable, round, Bulbasaur, Geninja, 4,
                      trainerName);
            }
            round++;
          }
          break;
        case sf::Event::MouseMoved:
          if (m1.isMouseOver(window)) {
            m1.setBackColor(sf::Color::White);
          } else {            
            m1.setBackColor(sf::Color(200, 255, 200));
          }
          if (m2.isMouseOver(window)) {
            m2.setBackColor(sf::Color::Yellow);
          } else {
            m2.setBackColor(sf::Color(200, 255, 200));
          }
          if (m3.isMouseOver(window)) {
            if (skillAvailable == 1) {
              userInteractMessage.setString(currentMessage);
              m3.setBackColor(sf::Color::Green);
            } else if (skillAvailable == 0) {
              userInteractMessage.setString(
                  "Trainer, Bulbasaur does not have\nLeaf Storm skill shot "
                  "left.");
              m3.setBackColor(sf::Color::Black);
            }
          } else {
            userInteractMessage.setString(currentMessage);
            m3.setBackColor(sf::Color(200, 255, 200));
          }
          if (m4.isMouseOver(window)) {
            m4.setBackColor(sf::Color::White);
          } else {
            m4.setBackColor(sf::Color(200, 255, 200));
          }
          break;

        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) {
            skillAvailable = 1;
            round = 1;
            window.close();
            PokemonMenu(trainerName);
            std::cout << "Escape Pressed" << std::endl;
          }
          break;
      }
      if (Bulbasaur.getHealth() <= 0) {
        window.close();
        Result(0, 'e', trainerName);
      } else if (Geninja.getHealth() <= 0) {
        window.close();
        Result(1, 'g', trainerName);
      }
    }
    // Update

    // Render
    window.clear();  // clear previous window
    // Draw Sprite
    window.draw(menueBackGroundSprite);
    window.draw(venusaurSprite);
    window.draw(userInteractSprite);
    window.draw(userInteractMessage);
    window.draw(statusBoxSpriteA);
    window.draw(statusA);
    window.draw(statusBoxSpriteB);
    window.draw(statusB);

    if (Bulbasaur.getHealth() < (10 * 0.5)) {
      hpBarA.setFillColor(sf::Color::Yellow);
    }
    if (Bulbasaur.getHealth() < (10 * 0.25)) {
      hpBarA.setFillColor(sf::Color::Red);
    }
    if (Geninja.getHealth() < (8 * 0.5)) {
      hpBarB.setFillColor(sf::Color::Yellow);
    }
    if (Geninja.getHealth() < (8 * 0.2)) {
      hpBarB.setFillColor(sf::Color::Red);
    }
    hpBarA.setSize(sf::Vector2f(Bulbasaur.getHealth() * 21.5, 20));
    hpBarB.setSize(sf::Vector2f(Geninja.getHealth() * 27, 20));
    window.draw(hpBarA);
    window.draw(hpBarB);
    window.draw(geninjaFSprite);
    // Draw button
    m1.drawTo(window);
    m2.drawTo(window);
    m3.drawTo(window);
    m4.drawTo(window);
    window.display();  // Tell app that window is done drawing
  }
}
