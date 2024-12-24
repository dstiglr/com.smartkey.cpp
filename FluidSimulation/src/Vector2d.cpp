#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <sstream>
using namespace std;

class Vector2d {

    public:
        float x;
        float y;

        Vector2d(){
            this->x = 0;
            this->y = 0;
        }
        
        Vector2d(float x, float y){
            this->x = x;
            this->y = y;
        }

        void clear() {
            x = 0;
            y = 0;
        }

        bool isEqual(Vector2d v) {
            return this->x == v.x && this->y == v.y;
        }

        void add(Vector2d v) {
            x +=  v.x;
            y +=  v.y;
        }


        void mult(float value) {
            x = x * value;
            y = y * value;
        } 

        void div(float value) {
            if(value > 0) {
                x = x / value;
                y = y / value;
            }
        }

        void setMag(float value) {
            this->normalize();
            this->mult(value);
        }

        Vector2d operator+(Vector2d vector) {
            Vector2d res;
            res.x = this->x + vector.x;
            res.y = this->y + vector.y;
            return res;
        }

        Vector2d operator-(Vector2d vector) {
            Vector2d res;
            res.x = this->x - vector.x;
            res.y = this->y - vector.y;
            return res;
        }

        string toString() {
            ostringstream ss;
            ss << "Vector2d( x: " << this->x << ", y: " << this->y << ")";
            return ss.str();
        }

        float magnitude() {
            return sqrt(x*x + y*y);
        }

        void normalize(){
            float mag = this->magnitude();
            if(mag > 0) {
                this->div(mag);
            }
        }
};
#endif