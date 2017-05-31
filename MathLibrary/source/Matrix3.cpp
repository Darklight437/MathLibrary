#include "Matrix3.h"
#include <math.h>



Matrix3::operator float*()
{
    return &u.x1;
}

//finish 3d rotation

void Matrix3::setRotateX(float rot)
{
    u.x1 = 1;
    u.x2 = 0;
    u.x3 = 0;
    u.y1 = 0;
    u.y2 = cos(rot);
    u.y3 = sin(rot);
    u.z1 = 0;
    u.z2 = -sin(rot);
	u.z3 = cos(rot); 
}

void Matrix3::setRotateY(float rot)
{
    u.x1 = cos(rot);
    u.x2 = 0;
    u.x3 = -sin(rot);
    u.y1 = 0;
    u.y2 = 1;
    u.y3 = 0;
    u.z1 = sin(rot);
    u.z2 = 0;
    u.z3 = cos(rot);
}

void Matrix3::setRotateZ(float rot)
{
    u.x1 = cos(rot);
    u.x2 = sin(rot);
    u.x3 = 0;
    u.y1 = -sin(rot);
    u.y2 = cos(rot);
    u.y3 = 0;
    u.z1 = 0;
    u.z2 = 0;
    u.z3 = 1;
}
//* with a vector

Vector3 Matrix3::operator *(Vector3 rhs)
{
    Vector3 intVect;
    intVect.x = u.x1 * rhs.x + u.y1 * rhs.y + u.z1 * rhs.z;
    intVect.y = u.x2 * rhs.x + u.y2 * rhs.y + u.z2 * rhs.z;
    intVect.z = u.x3 * rhs.x + u.y3 * rhs.y + u.z3 * rhs.z;
    return intVect;
}


//* with a matrix
Matrix3 Matrix3::operator *(Matrix3 rhs)
{

    Matrix3 IntMat;

    IntMat.u.x1 = u.x1 * rhs.u.x1
              + u.y1 * rhs.u.x2
              + u.z1 * rhs.u.x3;

    IntMat.u.x2 = u.x2 * rhs.u.x1
              + u.y2 * rhs.u.x2
              + u.z2 * rhs.u.x3;

    IntMat.u.x3 = u.x3 * rhs.u.x1
              + u.y3 * rhs.u.x2
              + u.z3 * rhs.u.x3;

    IntMat.u.y1 = u.x1 * rhs.u.y1
              + u.y1 * rhs.u.y2
              + u.z1 * rhs.u.y3;

    IntMat.u.y2 = u.x2 * rhs.u.y1
              + u.y2 * rhs.u.y2
              + u.z2 * rhs.u.y3;

    IntMat.u.y3 = u.x3 * rhs.u.y1
              + u.y3 * rhs.u.y2
              + u.z3 * rhs.u.y3;

    IntMat.u.z1 = u.x1 * rhs.u.z1
              + u.y1 * rhs.u.z2
              + u.z1 * rhs.u.z3;
              + u.z1 * rhs.u.z3;

    IntMat.u.z2 = u.x2 * rhs.u.z1
              + u.y2 * rhs.u.z2
              + u.z2 * rhs.u.z3;

    IntMat.u.z3 = u.x3 * rhs.u.z1
              + u.y3 * rhs.u.z2
              + u.z3 * rhs.u.z3;

    return IntMat;
}





Matrix3 & Matrix3::operator =(const Matrix3 & other)
{
    if (&other != this) // Prevent self-assignment
    {
        for (int i = 0; i < 9; i++)
        {
            u.M3[i] = other.u.M3[i];
        }
    }

    return *this;
}

Vector3& Matrix3::operator[](int input)
{
    switch (input)
    {
    case 0:
        return  u.matrix[0];

    case 1:
        return  u.matrix[1];

    case 2:
        return  u.matrix[2];
    }
    
}

Matrix3 Matrix3::operator + (const float& scalar)
{

    Matrix3 temp;
    for ( unsigned int i = 0; i < 9; i++)
    {
        temp.u.M3[i] = u.M3[i] + scalar;
    }
    return temp;
}

void Matrix3::operator += (const float& scalar)
{
    *this = *this + scalar;
}



Matrix3 Matrix3::identity()
{
    return Matrix3(1,0,0,0,1,0,0,0,1);
}



Matrix3::Matrix3()
{
    *this = identity();
}
//copy constructor

Matrix3::Matrix3(const Matrix3 & other)
{
    *this = other;
}


Matrix3::Matrix3(float X1, float X2, float X3, float Y1, float Y2, float Y3, float Z1, float Z2, float Z3)
{
    u.x1 = X1;
    u.x2 = X2;
    u.x3 = X3;
    u.y1 = Y1;
    u.y2 = Y2;
    u.y3 = Y3;
    u.z1 = Z1;
    u.z2 = Z2;
    u.z3 = Z3;
}


Matrix3::~Matrix3()
{
}
