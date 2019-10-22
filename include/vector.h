#ifndef VECTOR_H
#define VECTOR

// Octree types
typedef float oct_float;
typedef int oct_int;

class Vector
{
private:
public:
    Vector();
    Vector(oct_float, oct_float, oct_float);
    Vector operator*(oct_float);
    Vector operator/(oct_float);
    Vector operator+(const Vector&);
    oct_float x;
    oct_float y;
    oct_float z;
};

#endif
