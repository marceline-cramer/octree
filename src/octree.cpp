#include "octree.h"

#include <iostream>
using namespace std;

// Constant octree positions
Vector vecOctreeCorners[] = {
    Vector(-1.0, -1.0, -1.0),
    Vector( 1.0, -1.0, -1.0),
    Vector(-1.0,  1.0, -1.0),
    Vector( 1.0,  1.0, -1.0),
    Vector(-1.0, -1.0,  1.0),
    Vector( 1.0, -1.0,  1.0),
    Vector(-1.0,  1.0,  1.0),
    Vector( 1.0,  1.0,  1.0)
};

Octree::Octree() {
    for(int i = 0; i < 8; i++) {
        this->nodes[i].octNode = NULL;
        this->nodes[i].isFull = false;
    }
    this->parent = NULL;
    this->radius = 1.0;
    this->index = 0;
}

Octree::~Octree() {
    Destroy();
}

void Octree::Destroy() {
    for(int i = 0; i < 8; i++) {
        OctreeSubNode* node = &(this->nodes[i]);
        if(node->octNode) {
            if(node->isFull) {
                delete node->datNode;
            } else {
                delete node->octNode;
            }
        }
    }
}

Octree* Octree::Subdivide(oct_int nodeIndex) {
    // Check occupancy
    OctreeSubNode* node = &(this->nodes[nodeIndex]);
    if(node->octNode) {
        // If the child already exists, return it
        if(!node->isFull) {
            return node->octNode;
        }
        // If it has a payload, return NULL
        else {
            return NULL;
        }
    } else {
        // Create new Octree
        Octree* child = new Octree();

        // Insert it into our nodes
        node->octNode = child;
        node->isFull = false;

        // Initialize values
        child->depth = this->depth+1;
        child->radius = this->radius/2.0;
        child->index = nodeIndex;
        child->center = this->center+vecOctreeCorners[nodeIndex]*(this->radius/2.0);

        return child;
    }
}

void Octree::Print(){
    // Place tabs
    for(int i = 0; i < this->depth; i++) {
        cout << "    ";
    }

    cout << "Octree #" << this->index << " at ";
    cout << this->center.x << " " << this->center.y << " " << this->center.z << " ";
    cout << "radius " << this->radius << endl;

    for(int i = 0; i < 8; i++) {
        OctreeSubNode* node = &(this->nodes[i]);
        if(node->octNode) {
            if(!node->isFull){
                node->octNode->Print();
            }
        }
    }
}
