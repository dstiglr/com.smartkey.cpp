#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <thread>
#include <random>
#include "./src/Particle.cpp"
#include "./src/KdTree.cpp"
#include <chrono>
#include <cmath>
#include <time.h>
#include <SFML/System/Time.hpp>

using namespace std;
void drawParticles(vector<Particle>&, sf::Color);
vector<Particle> generateParticles(bool);
float smothingKernel(Particle, vector<Particle>, float);
void calculateDensity();
sf::Color interpolateColor(sf::Color, sf::Color, float);

sf::Color bgColor(255, 255, 255);
sf::Color lBlue(34, 87, 122);
sf::Color grayGreen(56, 163, 165);
sf::Color esmerald(87, 204, 153);
sf::Color lightGreen(128, 237, 153);
sf::Color teaGreen(199, 249, 204);
sf::Color redColor(255, 0, 4);
sf::Color blackColor(0, 0, 4);
sf::Color silverColor(192,192,192);
sf::Color blueColor(0,0,180);


const int WIDTH = 480;
const int HEIGHT = 320;
const int NUMBER_OF_PARTICLES = 100;
const float GRAVITY = 1;
const float RADIUS = 15;
float RUN = true;

// add particles to tree
KdTree kdT(2);
vector<Particle> particles = generateParticles(true);
vector<Particle> mesh;
// init kd tree
sf::CircleShape mouseCircle;
sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Fluid Simulation");
float ELAPSED_TIME = 0;

int main() {

    mouseCircle.setRadius(RADIUS);
    mouseCircle.setFillColor(bgColor); 
    mouseCircle.setOutlineThickness(3.f);
    mouseCircle.setOutlineColor(esmerald);

    sf::Clock clock;
    sf::Time elapsed1;
    //thread t1(calculateDensity);
    while (window.isOpen())
    { 
        elapsed1 = clock.restart();
        ELAPSED_TIME = elapsed1.asSeconds() * 10;
        kdT =  KdTree(2);

        for(Particle p : particles) {
            kdT.insert(p);
        } 
        
        window.clear(bgColor);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // get global mouse position
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        // convert it to world coordinates
        sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

        mouseCircle.setPosition(mousePos.x - mouseCircle.getRadius(), mousePos.y - mouseCircle.getRadius());
        window.draw(mouseCircle);

        

        // find nearest particles to mouse position
        Particle target({mousePos.x , mousePos.y });
        vector<Particle> nearPoints = kdT.nearest(target, RADIUS);  
        calculateDensity();
        // draw

        drawParticles(particles, silverColor);
        drawParticles(nearPoints, blueColor); 
        window.display();
        
    }
    RUN = false;
    //t1.join();
    return 0;    
}

vector<Particle> generateParticles (bool random) {
    srand ( time(NULL) );
    // Initialize a random number generator
    vector<Particle> data;
    int offsetX = WIDTH / 10;
    int offsetY =  HEIGHT / 10;
    if(random) {
        for(int i = 0; i < NUMBER_OF_PARTICLES; i++) {
            float x = (rand() % WIDTH) + 1;
            float y = (rand() % HEIGHT) + 1;
            data.push_back(Particle(x, y));
        }
    }  else {
        for(int i = offsetX; i < WIDTH - offsetX; i += 30) {
            for(int j = offsetY; j < HEIGHT - offsetY; j += 30) {
                float x =  i;
                float y = j;
                data.push_back(Particle(x, y));
            }
        }
        //data.push_back(Particle(WIDTH/2, HEIGHT/2));
    }

    return data;
}

void drawParticles(vector<Particle> &data, sf::Color color) {

    for (auto p = begin(data); p != end(data); ++p) {
        sf::CircleShape circle;
        p->resolveCollitions(WIDTH - 5, HEIGHT - 5);
        p->updateLocation(GRAVITY, ELAPSED_TIME);
        circle.setRadius(5);
        circle.setFillColor(color);
        circle.setPosition(p->x - circle.getRadius(), p->y  - circle.getRadius() );
        window.draw(circle);
    }        
}

void calculateDensity() {
    /*
    //while(RUN) {
        for(float x = 0; x < WIDTH; x += 15){
            for(float y = 0; y < HEIGHT; y += 15) {
                // find nearest particles to current position
                Particle target({x , y });
                vector<Particle> nearParticles = kdT.nearest(target, RADIUS);  
                float smoting = smothingKernel(target, nearParticles, RADIUS);
                target.density = smoting;
                sf::RectangleShape grid(sf::Vector2f(15.f, 15.f));
                
                grid.setFillColor(interpolateColor(sf::Color::White, sf::Color::Red, smoting * 0.2));
                grid.setPosition(target.x, target.y);
                window.draw(grid);
            }
        }
    //}
    */
   float SIZE = 20.0f;
    for (auto target = begin(particles); target != end(particles); ++target) {
        vector<Particle> nearParticles = kdT.nearest(*target, RADIUS);  
        float density = smothingKernel(*target, nearParticles, RADIUS);
        target->updateDensity(density,GRAVITY, ELAPSED_TIME);
        /*
        sf::RectangleShape grid(sf::Vector2f(SIZE, SIZE));
        grid.setFillColor(interpolateColor(sf::Color::White, sf::Color::Red, density * 0.2));
        grid.setPosition(target->x - SIZE / 2, target->y - SIZE / 2);
        window.draw(grid);
        */
    } 
}

float smothingKernel(Particle target, vector<Particle> nearParticles, float radius) {
    float result = 0;
    for(Particle p : nearParticles) {
        float distance = target.distance(p);
        if( (radius - distance ) > 0) {
            result += (radius - distance ) / radius;
        }
    }
    return result;
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