#ifndef KDTREE_H
#define KDTREE_H
#include <iostream>
#include "Particle.cpp"
using namespace std;

class KdTree {
    private:
        int DIM;
        
    public: 
        struct KdNode
        {
            Particle point;
            int axis; 
            KdNode* left;
            KdNode* right;
        };

        KdTree(int K) {
            this->DIM = K;
            this->root = NULL;
            //cout << "KdTree constructor, DIM:" << this->DIM << endl;
        }

        KdNode* root;
        
        void insert(Particle p) {
            this->root = insertRec(p, root, 0);
        }

        KdNode * insertRec(Particle p, KdNode * node, int axis) {
            if(node == NULL) {
                node = new KdNode{p, axis, NULL, NULL};
            } else if(p.isEqual(node->point)) {
                //cout << "warning, duplicated data" << endl;
            } else if(p.coords[axis] < node->point.coords[axis]) {
                node->left = insertRec(p, node->left, (axis + 1) % DIM);
            } else {
                node->right = insertRec(p, node->right, (axis + 1) % DIM);
            }
            return node;
        }
        

        vector<Particle> nearest(Particle p, float radio) {
            vector<Particle> data;
            nearestRec(p, root, radio, &data, 0);
            return data;
        }

        void nearestRec(Particle p, KdNode* node, float radio, vector<Particle>* data, int axis ) {
            if(node == NULL) {
                return;
            }

            // get euclidan distance between node and input point
            float _dist = p.distance(node->point);

            // if point's node is near, add it to result data
            if(_dist <= radio) {
                data->push_back(node->point);
            } 
            
            if(p.coords[axis] - radio <= node->point.coords[axis]) 
            nearestRec(p, node->left, radio, data, (axis + 1) % DIM);
            if(p.coords[axis] + radio > node->point.coords[axis]) 
            nearestRec(p, node->right, radio, data, (axis + 1) % DIM);
            
        }

};
#endif