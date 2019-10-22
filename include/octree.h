#ifndef OCTREE_H
#define OCTREE_H

#include "vector.h"

class Octree;
struct OctreeData;

struct OctreeSubNode
{
    union
    {
        Octree* octNode;
        OctreeData* datNode;
    };
    bool isFull;
};

class Octree
{
private:
    Octree* parent;
    oct_int depth;
    oct_int index;
    OctreeSubNode nodes[8];

    Vector center;
    oct_float radius;

    friend class Octree;
public:
    Octree();
    ~Octree();
    void Destroy();
    Octree* Subdivide(oct_int);
    void Print();
};

struct OctreeData
{
    float r, g, b, a;
};

#endif
