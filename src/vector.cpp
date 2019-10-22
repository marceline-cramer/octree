#include "vector.h"

Vector::Vector()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector::Vector(oct_float nx, oct_float ny, oct_float nz)
{
    x = nx;
    y = ny;
    z = nz;
}

Vector Vector::operator*(oct_float rhs)
{
    Vector op(this->x*rhs, this->y*rhs, this->z*rhs);
    return op;
}

Vector Vector::operator/(oct_float rhs)
{
    Vector op(this->x/rhs, this->y/rhs, this->z/rhs);
    return op;
}

Vector Vector::operator+(const Vector& rhs)
{
    Vector op(this->x+rhs.x, this->y+rhs.y, this->z+rhs.z);
    return op;
}
