#ifndef MAZE_H
#define MAZE_H
#include <SFML/Graphics.hpp>

class Maze {
    private:
        int width;
        int height;
        int size;
        sf::RenderWindow window;
        int** matrix;
        void initMatrix() const;
    
    public:
        Maze(int size, int width, int height);
        void toString() const;
        int getWidth() const {
            return width;
        }
        int getHeigth() const {
            return height;
        }
        int getSize() const {
            return size;
        }
        void render();
        void printMazeMatrix() const;
};

#endif