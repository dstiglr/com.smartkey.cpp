#include <iostream>
#include "../include/KdTree.h"
#include "../include/Point.h"
#include <cmath>    

using namespace std;
KdTree::KdTree(int K) {
    this->DIM = K;
    this->root = NULL;
    cout << "KdTree constructor, DIM:" << this->DIM << endl;
}

void KdTree::insert(Point p) {
    this->root = insertRec(p, root, 0);
}

KdTree::KdNode * KdTree::insertRec(Point p, KdNode * node, int axis) {
    if(node == NULL) {
        node = new KdNode{p, axis, NULL, NULL};
    } else if(p.isEqual(node->point)) {
        cout << "warking, duplicated data" << endl;
    } else if(p.coords[axis] < node->point.coords[axis]) {
        node->left = insertRec(p, node->left, (axis + 1) % DIM);
    } else {
        node->right = insertRec(p, node->right, (axis + 1) % DIM);
    }
    return node;
}

void KdTree::printInOrder(KdNode* node) const {
    if(node == NULL) {
        return;
    }

    printInOrder(node->left);
    cout << node->point.getValue() << endl;
    printInOrder(node->right);
}

vector<Point> KdTree::nearest(Point p, float radio) {
    vector<Point> data;
    nearestRec(p, root, radio, &data, 0);
    return data;
}

void KdTree::nearestRec(Point p, KdNode* node, float radio, vector<Point>* data, int axis ) {
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