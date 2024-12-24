#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        sf::Event event;
        const int MAX_RAND = 100;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        
        // get global mouse position
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

        // convert it to world coordinates
        sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

        shape.setRadius( rand() % MAX_RAND);
        shape.setPosition(mousePos.x - shape.getRadius(), mousePos.y - shape.getRadius());
        window.draw(shape);
        window.display();

        cout << mousePos.x << ", " << mousePos.y << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    
}
