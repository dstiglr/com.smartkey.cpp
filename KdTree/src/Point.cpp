#include <iostream>
#include "../include/Point.h"
#include <cmath>

using namespace std;

Point::Point(vector<float> coords, string value) 
{
    this->coords = coords;
    this->value = value;
}

string Point::toString() const
{
    string _coords = "[";
    for(float v : this->coords) {
        _coords +=  to_string(v) + ",";
    }
    _coords += "]";
    return "{coords:" + _coords + ", value:" + getValue()  + "}";
}

bool Point::isEqual(Point p) {
    return this->coords == p.coords;
}

float Point::distance(Point b) {
    float _dist = 0;
    for(float i = 0; i < coords.size(); i++) {
        _dist += pow(coords[i] - b.coords[i], 2);
    }
    return sqrt(_dist);
}




