#include <iostream>
#include "./include/KdTree.h"
#include "./include/Point.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <thread>
#include <random>

using namespace std;

void drawCircleData(sf::RenderWindow*, vector<Point>, sf::Color, int);
vector<Point> generateRandomPoints (int);

sf::Color bgColor(11, 15, 23);
sf::Color lBlue(34, 87, 122);
sf::Color grayGreen(56, 163, 165);
sf::Color esmerald(87, 204, 153);
sf::Color lightGreen(128, 237, 153);
sf::Color teaGreen(199, 249, 204);
sf::Color redColor(255, 0, 4);
sf::Color blackColor(0, 0, 4);
sf::Color silverColor(192,192,192);

const int WIDTH = 640;
const int HEIGHT = 480;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "KDTREE Application");

   
    int DIM = 2;
    float dist = 45.0;

    cout << "hi there !" << endl;
    vector<Point> data = generateRandomPoints(300);

    KdTree kdT(DIM);

    for(Point p : data) {
        kdT.insert(p);
    }    

    sf::CircleShape mouseCircle;
    mouseCircle.setRadius(dist);
    mouseCircle.setFillColor(esmerald);

    while (window.isOpen())
    { 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(bgColor);


        // get global mouse position
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        // convert it to world coordinates
        sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

        mouseCircle.setPosition(mousePos.x - mouseCircle.getRadius(), mousePos.y - mouseCircle.getRadius());
        window.draw(mouseCircle);

        drawCircleData(&window, data, silverColor, 4);

        // ger nearest neighbors

        Point target({mousePos.x , mousePos.y }, "mX, mY");
        vector<Point> nearPoints = kdT.nearest(target, dist);  
        drawCircleData(&window, nearPoints, redColor, 8); 
        // draw
        window.display();
    }

}

vector<Point> generateRandomPoints (int numberOfPoints) {
    // Initialize a random number generator
    vector<Point> data;
    for(int i = 0; i < numberOfPoints; i++) {
        int x = (rand() % WIDTH) + 1;
        int y = (rand() % HEIGHT) + 1;
        data.push_back(Point({static_cast<float>(x), static_cast<float>(y)}, "A" + to_string(y)));
    }

    return data;
}

void drawCircleData(sf::RenderWindow* window, vector<Point> data, sf::Color color, int radius) {

    for(Point p : data) {
        sf::CircleShape circle;
        circle.setRadius(radius);
        circle.setFillColor(color);
        circle.setPosition(p.coords[0] - circle.getRadius(), p.coords[1]  - circle.getRadius() );
        window->draw(circle);
    }    

}