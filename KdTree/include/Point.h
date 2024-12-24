#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point {
    private:
        string value;

    public:
        vector<float> coords;
        Point(vector<float> coords, string value);
        string getValue() const {
            return value;
        }
        string toString() const;
        bool isEqual(Point);
        float distance(Point);

};
#endif