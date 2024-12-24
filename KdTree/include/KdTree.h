#ifndef KDTREE_H
#define KDTREE_H
#include <iostream>
#include "Point.h"
using namespace std;

class KdTree {
    private:
        int DIM;
        
    public: 
        struct KdNode
        {
            Point point;
            int axis; 
            KdNode* left;
            KdNode* right;
        };

        KdTree(int);
        KdNode* root;
        
        void insert(Point);
        KdNode * insertRec(Point, KdNode*, int);
        
        void printInOrder(KdNode*) const;

        vector<Point> nearest(Point, float);
        void  nearestRec(Point, KdNode*, float, vector<Point>*, int);

};
#endif