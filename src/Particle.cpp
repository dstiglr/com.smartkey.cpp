#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "Vector2d.cpp"
#include <math.h>
#include <sstream>

using namespace std;

class Particle {  

    public:
        float mass = 1.0f;
        float radius = 1;
        Vector2d position;
        Vector2d velocity;
        Vector2d acc; // acceleration
        float collitionsDamping = 1; 
        sf::Color color;

        // class constructor
        Particle(float x, float y) {
            position.x = x;
            position.y = y;
        }


        Particle(float x, float y, float radius, sf::Color color) {
            position.x = x;
            position.y = y;
            this->radius = radius;
            this->mass = M_PI * radius * radius;
            this->color = color;
        }

        // apply external force
        void applyForce(Vector2d force) {
            acc.add(force);
        }

        // update particle location
        void update() {
            velocity.add(acc);
            position.add(velocity);
            acc.clear();
        }

        /**
         * Function to draw particle on canvas
         */
        sf::CircleShape render() {
            sf::CircleShape circle;
            circle.setRadius(this->radius);
            circle.setFillColor(this->color); 
            circle.setPosition(position.x - circle.getRadius(), position.y - circle.getRadius());
            return circle;
        }

        // resolve window collitions
        void resolveCollitions(int width, int height) {
             if(position.x < 0 || position.x > width) {
                if(position.x > width) {
                    position.x = width;
                }
                velocity.x *= -1 * collitionsDamping;
            }
            if ( position.y < 0 || position.y > height) { 
                if(position.y > height) {
                    position.y = height;
                }
                velocity.y *= -1 * collitionsDamping;  
            }
        }

        string toString() {
            ostringstream os;
            os << "Particle( mass: " << this->mass 
                << ", radius: " << this->radius 
                << ", position" << this->position.toString() 
                << ")";
            return os.str();
        }

        void applyGravityForce(Particle *p) {
            Vector2d force = this->position - p->position;
            float distance = force.magnitude() / 10;
            float G = 2;
            float strength =  G * (this->mass * p->mass)  / distance;
            force.setMag(strength * 0.000000001);
            p->applyForce(force);            
        }

        void updateLocation(Vector2d v) {
            this->position = v;
        }
};
#endif