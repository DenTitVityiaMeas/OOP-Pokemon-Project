#include "BattleSystem.h"

#include <string.h>

#include <ctime>
#include <iostream>

#include "Pokemonlist.h"
#include "stdInclude.h"

// Set the skill available to 1 which mean the third skill is ready to use
// Call the actionBoard that vary from fire,grass and water pokemon
// Actionboard function will create the options for user to pick from
// SFML RenderWindow
/*
int actionBoardG(int t, grassPokemon& C, Pokemon& S, string trainerName) {
  int skillAvailable = 1;
  int option = 0;
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
  venusaurSprite.setPosition(sf::Vector2f(20, 240));
  venusaurSprite.scale(sf::Vector2f(2, 2));

  sf::Texture geninjaF;
  geninjaF.loadFromFile("Resources/greninjaF.png");
  sf::Sprite geninjaFSprite;
  geninjaFSprite.setTexture(geninjaF);
  geninjaFSprite.setPosition(sf::Vector2f(440, 10));
  geninjaFSprite.scale(sf::Vector2f(2, 2));

  // Make buttons
  Button bite(C.M1.getMoveName(), {120, 40}, 16, sf::Color::Green,
              sf::Color::Black);
  bite.setFont(courierNew);
  bite.setPosition({435, 420});
  Button bulletSeed(C.M2.getMoveName(), {120, 40}, 16, sf::Color::Green,
                    sf::Color::Black);
  bulletSeed.setFont(courierNew);
  bulletSeed.setPosition({565, 420});
  Button leafStorm(C.M3.getMoveName(), {120, 40}, 16, sf::Color::Green,
                   sf::Color::Black);
  leafStorm.setFont(courierNew);
  leafStorm.setPosition({435, 470});
  Button guardUp(C.M4.getMoveName(), {120, 40}, 16, sf::Color::Green,
                 sf::Color::Black);
  guardUp.setFont(courierNew);
  guardUp.setPosition({565, 470});

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
  hpBarA.setPosition(statusAllignmentAX + 112, statusAllignmentAY + 40);
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
  hpBarB.setPosition(statusAllignmentBX + 106, statusAllignmentBY + 40);

  statusB.setString("Greninja  Element: Water\nHP: 8\tSpeed: 3");

  // Window Loop
  while (window.isOpen()) {
    sf::Event event;
    // Event Poll Loop
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
        case sf::Event::MouseButtonPressed:
          if (bite.isMouseOver(window)) {
            return pokemonMove(C, S, C.M1.getType(), C.M1.getPower());
            break;
          } else if (bulletSeed.isMouseOver(window)) {
            return pokemonMove(C, S, C.M2.getType(), C.M2.getPower());
            break;
          } else if (leafStorm.isMouseOver(window)) {
            if (skillAvailable == 0) {
              return 9;
            };
            skillAvailable = 0;
            return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());

            case 4:
              return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
          } else if (guardUp.isMouseOver(window)) {
            return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
            break;
          } else {
            return 10;
          }
          break;
        case sf::Event::MouseMoved:
          if (bite.isMouseOver(window)) {
            bite.setBackColor(sf::Color::White);
          } else {
            bite.setBackColor(sf::Color(200, 255, 200));
          }
          if (bulletSeed.isMouseOver(window)) {
            bulletSeed.setBackColor(sf::Color::Yellow);
          } else {
            bulletSeed.setBackColor(sf::Color(200, 255, 200));
          }
          if (leafStorm.isMouseOver(window)) {
            if (skillAvailable == 1) {
              leafStorm.setBackColor(sf::Color::Green);
            } else if (skillAvailable == 0) {
              userInteractMessage.setString(
                  "Trainer, you do not have\nLeaf Storm\nskill shot left.");
              leafStorm.setBackColor(sf::Color::Black);
            }
          } else {
            userInteractMessage.setString(currentMessage);
            leafStorm.setBackColor(sf::Color(200, 255, 200));
          }
          if (guardUp.isMouseOver(window)) {
            guardUp.setBackColor(sf::Color::Red);
          } else {
            // userInteractMessage.setString(currentMessage);
            guardUp.setBackColor(sf::Color(200, 255, 200));
          }
          break;

        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) {
            window.close();
            PokemonMenu(trainerName);
            std::cout << "Escape Pressed" << std::endl;
          }
          break;
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
    if (C.getHealth() < (C.getHealth() * 0.5)) {
      hpBarA.setFillColor(sf::Color::Yellow);
    }
    if (C.getHealth() < (C.getHealth() * 0.25)) {
      hpBarA.setFillColor(sf::Color::Red);
    }
    if (S.getHealth() < (S.getHealth() * 0.5)) {
      hpBarB.setFillColor(sf::Color::Yellow);
    }
    if (S.getHealth() < (S.getHealth() * 0.2)) {
      hpBarB.setFillColor(sf::Color::Red);
    }
    hpBarA.setSize(sf::Vector2f(C.getHealth() * 21.5, 20));
    hpBarB.setSize(sf::Vector2f(S.getHealth() * 27, 20));
    window.draw(hpBarA);
    window.draw(hpBarB);
    window.draw(geninjaFSprite);
    // Draw button
    bite.drawTo(window);
    bulletSeed.drawTo(window);
    leafStorm.drawTo(window);
    guardUp.drawTo(window);
    window.display();  // Tell app that window is done drawing
    switch (option) {
      case 1:

      case 2:

      case 3:
        if (skillAvailable == 0) {
          return 9;
        };
        skillAvailable = 0;
        return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());

      case 4:
        return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());

      default:
        return 10;
    }
  }
  return 0;
}*/

int actionBoardG(int shot, grassPokemon& C, Pokemon& S, int option,
                 string trainName) {
  int skillAvailable = shot;
  cout << endl;
  cout << "*******************************************************************"
       << endl;
  cout << "* Pick a Move:  " << endl;
  cout << "* 1. " << C.M1.getMoveName() << endl;
  cout << "* 2. " << C.M2.getMoveName() << endl;
  if (skillAvailable == 1) {
    cout << "* 3. " << C.M3.getMoveName() << endl;
  } else if (skillAvailable == 0) {
    cout << "* 3. This skill is already used!" << endl;
  };
  cout << "* 4. " << C.M4.getMoveName() << endl;
  cout << "Your choice: ";
  switch (option) {
    case 1:
      cout << "You use: " << C.M1.getMoveName() << endl;
      return pokemonMove(C, S, C.M1.getType(), C.M1.getPower());
      break;
    case 2:
      cout << "You use: " << C.M2.getMoveName() << endl;
      return pokemonMove(C, S, C.M2.getType(), C.M2.getPower());
      break;
    case 3:
      cout << "You use: " << C.M3.getMoveName() << endl;
      if (skillAvailable == 0) {
        cout << "**************************************************************"
                "*****";
        return 9;
        break;
      } else if (skillAvailable == 1) {
        return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());
        break;
      }
    case 4:
      cout << "You use: " << C.M4.getMoveName() << endl;
      return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
      break;
    default:
      cout << "****************************************************************"
              "***"
           << endl;
      cout << "WRONG INPUT! " << endl;
      return 10;
      break;
  }
  return 0;
}

int actionBoardW(int shot, waterPokemon& C, Pokemon& S, int option,
                 string trainerName) {
  int skillAvailable = shot;
  cout << endl;
  cout << "*******************************************************************"
       << endl;
  cout << "* Pick a Move:  " << endl;
  cout << "* 1. " << C.M1.getMoveName() << endl;
  cout << "* 2. " << C.M2.getMoveName() << endl;
  if (skillAvailable == 1) {
    cout << "* 3. " << C.M3.getMoveName() << endl;
  } else if (skillAvailable == 0) {
    cout << "* 3. This skill is already used!" << endl;
  };
  cout << "* 4. " << C.M4.getMoveName() << endl;
  cout << "Your choice: ";
  switch (option) {
    case 1:
      cout << "You use: " << C.M1.getMoveName() << endl;
      return pokemonMove(C, S, C.M1.getType(), C.M1.getPower());
      break;
    case 2:
      cout << "You use: " << C.M2.getMoveName() << endl;
      return pokemonMove(C, S, C.M2.getType(), C.M2.getPower());
      break;
    case 3:
      cout << "You use: " << C.M3.getMoveName() << endl;
      if (skillAvailable == 0) {
        cout << "**************************************************************"
                "*****";
        return 9;
        break;
      } else if (skillAvailable == 1) {
        return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());
        break;
      }
    case 4:
      cout << "You use: " << C.M4.getMoveName() << endl;
      return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
      break;
    default:
      cout << "****************************************************************"
              "***"
           << endl;
      cout << "WRONG INPUT! " << endl;
      return 10;
      break;
  }
  return 0;
}
int actionBoardF(int shot, firePokemon& C, Pokemon& S, int option,
                 string trainerName) {
  int skillAvailable = shot;
  cout << endl;
  cout << "*******************************************************************"
       << endl;
  cout << "* Pick a Move:  " << endl;
  cout << "* 1. " << C.M1.getMoveName() << endl;
  cout << "* 2. " << C.M2.getMoveName() << endl;
  if (skillAvailable == 1) {
    cout << "* 3. " << C.M3.getMoveName() << endl;
  } else if (skillAvailable == 0) {
    cout << "* 3. This skill is already used!" << endl;
  };
  cout << "* 4. " << C.M4.getMoveName() << endl;
  cout << "Your choice: ";
  if (option == 1) {
    cout << "You use: " << C.M1.getMoveName() << endl;
    return pokemonMove(C, S, C.M1.getType(), C.M1.getPower());
  } else if (option == 2) {
    cout << "You use: " << C.M2.getMoveName() << endl;
    int dmg = pokemonMove(C, S, C.M2.getType(), C.M2.getPower());
    return dmg;
  } else if (option == 3) {
    cout << "You use: " << C.M3.getMoveName() << endl;
    if (skillAvailable == 0) {
      cout << "**************************************************************"
              "*****";
      return 9;
    } else if (skillAvailable == 1) {
      return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());
    }
  } else if (option == 4) {
    cout << "You use: " << C.M4.getMoveName() << endl;
    return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
  } else {
    cout << "****************************************************************"
            "***"
         << endl;
    cout << "WRONG INPUT! " << endl;
    return 10;
  }
  return 0;
}
// Function pokeMove calculate the damage based on class and elements
// pokemMove is called inside actionBoard
// different types create different damage
int pokemonMove(Pokemon& C, Pokemon& S, string Type, int Power) {
  int damage = 1;
  if (Type.compare("Normal") == 0) {
    return 1;
  };
  if (Type.compare("Defense") == 0) {
    return 0;
  };
  if (Type.compare("Unique") == 0) {
    return C.M3.getPower();
  };
  if ((Type.compare("Element") == 0)) {
    if (C.getElement() == 1) {
      if (S.getElement() == 2) {
        cout << "Not effective" << endl;
        return C.M2.getPower() - damage;
      } else if (S.getElement() == 3) {
        cout << "Super effective" << endl;
        return C.M2.getPower() + damage;
      }
      return C.M2.getPower();
    }
    if (C.getElement() == 2) {
      if (S.getElement() == 1) {
        cout << "Not effective" << endl;
        return C.M2.getPower() - damage;
      } else if (S.getElement() == 3) {
        cout << "Super effective" << endl;
        return C.M2.getPower() + damage;
      }
      return C.M2.getPower();
    }
    if (C.getElement() == 3) {
      if (S.getElement() == 1) {
        cout << "Not effective" << endl;
        return C.M2.getPower() - damage;
      } else if (S.getElement() == 2) {
        cout << "Super effective" << endl;
        return C.M2.getPower() + damage;
      };
      return C.M2.getPower();
    }
  }
  return 0;
}

int enemyAction() {
  cout << "Normal Strike for 1 damage";
  return 1;
};
