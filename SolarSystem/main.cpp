#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../src/Particle.cpp"
#include "../src/Vector2d.cpp"
#include <cmath>

using namespace std;

sf::Color bgColor(0, 0, 0);
sf::Color blueColor(0, 0, 255);
sf::Color esmerald(87, 204, 153);
sf::Color lightGreen(128, 237, 153);
sf::Color silverColor(192,192,192);
sf::Color redColor(255, 42, 182);
sf::Color earthColor(122, 165, 229);
sf::Color sunColor(255, 255, 0);
sf::Color sunColorAlpha(255, 255, 0, 5);


const int WIDTH = 1280;
const int HEIGHT = 800;

sf::Color interpolateColor(sf::Color, sf::Color, float);
int main() {
    // Get a different random number each time the program runs
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Foces Interaction");

    vector<Particle> planets;

    Particle sun(WIDTH / 2, HEIGHT / 2, 25, sunColor);
    Particle sun2(WIDTH / 2, HEIGHT / 2, 35, sunColorAlpha);
    //sun.applyForce(Vector2d(0.0005,0.0005));
    // apply aceleration force
    for(int i = 0; i < 10; i++) {
        float x = (rand() % WIDTH) + 1;
        float y = (rand() % HEIGHT) + 1;
        float randMass = (rand() % 10) + 5;
        float accX = (float) rand()/RAND_MAX;
        float accY = (float) rand()/RAND_MAX;
        Particle planet(x, y, randMass,  interpolateColor(blueColor, redColor, accX + accY));
        planet.applyForce(Vector2d(accX * 0.1, accY * 0.1));
        planets.push_back(planet);
    }

    //window.setFramerateLimit(64);
    while (window.isOpen())
    { 
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
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        // get the current mouse position in the window
        // convert it to world coordinates
        sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

       for (Particle& p : planets) {
            //sun.update();
            sun.resolveCollitions(WIDTH, HEIGHT);
            sun.applyGravityForce(&p);
            p.applyGravityForce(&sun);
            p.update();
            
            window.draw(p.render());
            window.draw(sun.render());
            window.draw(sun2.render());
        }
        
        window.display();
    }
    return 0;    
}

sf::Color interpolateColor(sf::Color color1, sf::Color color2, float value) {
    if(value > 1) {
        value = 1;
    }
    int r = (color2.r - color1.r) * value + color1.r;
    int g = (color2.g - color1.g) * value + color1.g;
    int b = (color2.b - color1.b) * value + color1.b;
    return sf::Color(r, g, b);
}