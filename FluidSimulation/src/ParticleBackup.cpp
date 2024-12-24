#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <cmath>
#include <SFML/System/Time.hpp>
using namespace std;

class Particle {  
    public:
        vector<float> coords;
        float x;
        float y;
        string value;
        float vX;
        float vY;
        float collitionsDamping = 0.7;
        float mass = 1;
        float density = 0;

        Particle(float x, float y) {
            this->x = x;
            this->y = y;
            this->coords.push_back(x);
            this->coords.push_back(y);
        }


        Particle(float x, float y, float density) {
            this->x = x;
            this->y = y;
            this->density = density;
            this->coords.push_back(x);
            this->coords.push_back(y);
        }

        void updateLocation(float gravity, float deltaTime) { 
            vX += 0;
            vY += gravity * deltaTime;
            x += vX * deltaTime * mass;
            y += vY * deltaTime * mass;
            this->coords[0] = x;
            this->coords[1] = y;
        }

        void updateDensity(float density, float gravity, float deltaTime) {
            // the partile is near others particles, so go to opposite direction
            if(density > this->density ) {
                //vX *= -1 * collitionsDamping;
                //vY *= -1 * collitionsDamping;   
            }
            this->density = density;

        }

        void resolveCollitions(int width, int height) {
            if(x < 0 || x > width) {
                vX *= -1 * collitionsDamping;
                if(x > width) {
                    x = width;
                }
            }
            if ( y < 0 || y > height) {
                vY *= -1 * collitionsDamping;   
                if(y > height) {
                    y = height;
                }
            }
        }

        bool isEqual(Particle p) {
            return this->coords == p.coords;
        }

        float distance(Particle b) {
            float _dist = 0;
            for(float i = 0; i < coords.size(); i++) {
                _dist += pow(coords[i] - b.coords[i], 2);
            }
            return sqrt(_dist);
        }
};
#endif