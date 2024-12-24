#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "Vector2d.cpp"

using namespace std;

class Particle {  

    public:
        Vector2d position;
        Vector2d velocity;
        Vector2d acc; // acceleration
        float collitionsDamping = 0.9; 

        // class constructor
        Particle(float x, float y) {
            position.x = x;
            position.y = y;
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
        sf::CircleShape render(int radius) {
            sf::CircleShape circle;
            circle.setRadius(radius);
            circle.setFillColor(sf::Color(34, 87, 122)); 
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
};
#endif