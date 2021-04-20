#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "CAssets.h"
#include "CGameModel.h"
#include "CGameView.h"
#include "CGameController.h"

int main() {

    CAssets::GetInstance().Load();
    CGameModel Model;

    CGameView View(&Model);

    CGameController Controller(&Model, &View);

    Controller.Run();
    return 0;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Platformer", sf::Style::Default);

    // View
    sf::View mainView;
    mainView.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);


    sf::View mainView1;
    mainView1.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // rect
    sf::RectangleShape playerRect;
    playerRect.setSize(sf::Vector2f(100.f, 100.f));
    playerRect.setPosition(500.f, 500.f);

    sf::RectangleShape object;
    object.setSize(sf::Vector2f(100.f, 100.f));
    object.setPosition(500.f, 500.f);
    object.setFillColor(sf::Color::Red);

    sf::RectangleShape object2;
    object2.setSize(sf::Vector2f(250.f, 250.f));
    object2.setPosition(2000.f, 500.f);
    object2.setFillColor(sf::Color::Red);

    sf::FloatRect a(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
    mainView.setViewport(a);

    sf::RectangleShape UIElement;
    std::cout << mainView.getCenter().x << std::endl;
    std::cout << mainView.getCenter().y << std::endl;
    std::cout << 0.75f*WINDOW_WIDTH << std::endl;
    UIElement.setPosition(WINDOW_WIDTH - 750, 0.f);
    UIElement.setSize(sf::Vector2f(0.25f*WINDOW_WIDTH, 0.25f*WINDOW_HEIGHT));
    UIElement.setOutlineColor(sf::Color::Green);
    UIElement.setFillColor(sf::Color::Black);
    UIElement.setOutlineThickness(2.f);


    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Update
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            playerRect.move(-0.5f,0.f);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerRect.move(0.5f,0.f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            playerRect.move(0.f,-0.5f);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            playerRect.move(0.f,0.5f);
        }

        mainView.setCenter(playerRect.getPosition());
        mainView1.setCenter(playerRect.getPosition());

        // clear the window with black color
        window.clear();


        // draw ui
        window.setView(window.getDefaultView());
        window.draw(UIElement);


        // mini map
        window.setView(mainView1);
        window.draw(playerRect);
        window.draw(object);
        window.draw(object2);


        // draw stuff
        window.setView(mainView);
        window.draw(playerRect);
        window.draw(object);
        window.draw(object2);


        // end the current frame
        window.display();
    }

    return 0;
}


