#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../src/Particle.cpp"
#include "../src/Vector2d.cpp"
#include <cmath>

using namespace std;

sf::Color bgColor(0, 0, 0);
sf::Color esmerald(87, 204, 153);
sf::Color lightGreen(128, 237, 153);
sf::Color yellowColor(255, 255, 0);


const int WIDTH = 1280;
const int HEIGHT = 800;
const int R = 100;
const int HALF_W = WIDTH / 2;
const int HALF_H = HEIGHT / 2;
float THETA = 0;

int main() {
    // Get a different random number each time the program runs
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Polar Coordinates");
    
    vector<Particle> particles;
    vector<float> angles;
    vector<float> xPos;




    
    // Create angles tracker, store x locations and generate particles to draw
    for(int i = 10; i < WIDTH; i+= 10) {
        float x = i;
        float y = R * sin(THETA) + HALF_H;
        if(i == 640) {
            Particle p(x, y, 10, yellowColor);
        particles.push_back(p);
        } else {
            Particle p(x, y, 3, esmerald);
        particles.push_back(p);
        }
        angles.push_back(THETA);
        xPos.push_back(x);
        THETA += 0.2;
    }

    window.setFramerateLimit(64);
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


        // update particles
        for(int i = 0; i < angles.size(); i++) {
            // calculate new particle position
            float x = xPos[i];
            float y = R * sin(angles[i]) + HALF_H;
            // update particle location
            Vector2d v(x,y);
            particles[i].updateLocation(v);  
            angles[i] += 0.01;  
        }
        
        for (Particle p : particles) {
            window.draw(p.render());
        }
    
        window.display();
    }
    return 0;    
}