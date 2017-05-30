#include "Matrix2.h"
#include <math.h>




Matrix2::operator float*()
{
    return &x1;
}



void Matrix2::setRotate(float rot)
{
    x1 = cos(rot);
    x2 = sin(rot);
    y1 = -sin(rot);
    y2 = cos(rot);
}

Vector2 Matrix2::operator*(Vector2 rhs)
{
    Vector2 intVect;
    intVect.x = (x1 * rhs.x) + (y1 * rhs.y);
    intVect.y = (x2 * rhs.x) + (y2 * rhs.y);
    return intVect;
}

Matrix2 Matrix2::operator*(Matrix2 rhs)
{
    Matrix2 IntMat;
    IntMat.x1 = x1 * rhs.x1 + y1 * rhs.x2;
    IntMat.x2 = x2 * rhs.x1 + y2 * rhs.x2;
    IntMat.y1 = x1 * rhs.y1 + y1 * rhs.y2;
    IntMat.y2 = x2 * rhs.y1 + y2 * rhs.y2;

    return IntMat;
}

Matrix2::Matrix2()
{
    *this = identity();
}


Matrix2::Matrix2(const Matrix2 & other)
{
    *this = other;
}

void Matrix2::operator=(const Matrix2 & other)
{
    for (int i = 0; i < 4; i++)
    {
        M2[i] = other.M2[i];
    }
}

Matrix2::Matrix2(float pos1, float pos2, float pos3, float pos4)
{
    x1 = pos1;
    x2 = pos2;
    y1 = pos3;
    y2 = pos4;
}

Matrix2::~Matrix2()
{}

Matrix2 Matrix2::identity()
{
    return Matrix2(1,0,0,1);
}
