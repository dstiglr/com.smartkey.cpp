#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "./src/Particle.cpp"
#include "./src/Vector2d.cpp"
#include <cmath>
#include <time.h>
#include <SFML/System/Time.hpp>

using namespace std;

sf::Color bgColor(0, 0, 0);
sf::Color lBlue(34, 87, 122);
sf::Color esmerald(87, 204, 153);
sf::Color lightGreen(128, 237, 153);
sf::Color silverColor(192,192,192);


const int WIDTH = 640;
const int HEIGHT = 380;
float ELAPSED_TIME = 0;
const int RADIUS = 20;

int main() {


    sf::Clock clock;
    sf::Time elapsed1;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Foces Interaction");

    Particle particle(WIDTH / 2, HEIGHT / 2);

    Vector2d gravity = Vector2d(0, 0.0001);
    Vector2d wind = Vector2d(0,0);
    particle.applyForce(wind);

    while (window.isOpen())
    { 
        elapsed1 = clock.restart();
        ELAPSED_TIME = elapsed1.asSeconds() * 10;

        window.clear(bgColor);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        // get global mouse position
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        // convert it to world coordinates
        sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

        Vector2d centerVector = Vector2d(WIDTH / 2, HEIGHT / 2);
        Vector2d mouseVector = Vector2d(mousePos.x, mousePos.y);
        Vector2d _v = mouseVector - centerVector;

       // _v.normalize();
        _v.setMag(13);
        _v.add(centerVector);

        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(centerVector.x,centerVector.y)),
            sf::Vertex(sf::Vector2f(_v.x, _v.y))
        };
        line[0].color = sf::Color(34, 87, 122);
        line[1].color = sf::Color(34, 87, 122);
        window.draw(line, 2, sf::Lines);

        particle.applyForce(gravity);
        particle.update();
        particle.resolveCollitions(WIDTH, HEIGHT);
        window.draw(particle.render(RADIUS));

        window.display();
    }
    return 0;    
}
