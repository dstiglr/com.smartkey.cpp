#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>   
#include "Maze.h"
using namespace std;

Maze::Maze(int size, int width, int height){
    this->size = size;
    this->width = width;
    this->height = height;
    window.create(sf::VideoMode(width, height), "Maze Solver");
    matrix = new int*[size];

    // init maze
    this->initMatrix();
}

void Maze::initMatrix()  const {
    int c = 0;
    for (int i = 0; i < size; i++) {
 
        // Declare a memory block  of size n
        matrix[i] = new int[size];
    }
    // Traverse the 2D array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Assign values to the
            // memory blocks created
            matrix[i][j] = (float) rand()/RAND_MAX > 0.5;
        }
    }
}




void Maze::toString() const {
    cout << "matrix size: " << size << ", window width: " << width << ", heigth: " << height << endl;
}



void Maze::render() {
    sf::CircleShape shape;
    shape.setRadius(45.0);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
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

        //shape.setRadius( rand() % MAX_RAND);
        shape.setPosition(mousePos.x - shape.getRadius(), mousePos.y - shape.getRadius());
        window.draw(shape);

        // render pixels
        for (int i = 0; i < width; i+=15) {
            for (int j = 0; j < height; j+=15) {
                sf::CircleShape dot;
                dot.setRadius(3.0);
                dot.setFillColor(sf::Color::Blue);
                dot.setPosition(i, j);
                window.draw(dot);
            }
        }

        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        
        auto now = chrono::system_clock::now();
        
        auto start = std::chrono::system_clock::now();     
        std::time_t _now = std::chrono::system_clock::to_time_t(start); 
        //this->printMazeMatrix();
        cout <<  std::ctime(&_now) << "frame event" << endl ;
    }
}

void Maze::printMazeMatrix() const {
    cout << "-----" << endl;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}