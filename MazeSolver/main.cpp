#include <iostream>
#include "Maze.h"

using namespace std;

int main() {

    Maze maze(50, 640, 480);
    maze.toString();
    cout << "END" << endl;

    maze.render();
    return 0;

}
