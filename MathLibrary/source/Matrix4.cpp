#include "Matrix4.h"
#include <math.h>

Matrix4::operator float*()
{
    return &matrix[0][0];
}

void Matrix4::setRotateX(float rot)
{

    x1 = 1;
    x2 = 0;
    x3 = 0;
    x4 = 0;
    y1 = 0;
    y2 = cos(rot);
    y3 = sin(rot);
    y4 = 0;
    z1 = 0;
    z2 = -sin(rot);
    z3 = cos(rot);
    z4 = 0;
    w1 = 0;
    w2 = 0;
    w3 = 0;
    w4 = 1;
}

void Matrix4::setRotateY(float rot)
{
    x1 = cos(rot);
    x2 = 0;
    x3 = -sin(rot);
    x4 = 0;
    y1 = 0;
    y2 = 1;
    y3 = 0;
    y4 = 0;
    z1 = sin(rot);
    z2 = 0;
    z3 = cos(rot);
    z4 = 0;
    w1 = 0;
    w2 = 0;
    w3 = 0;
    w4 = 1;
}

void Matrix4::setRotateZ(float rot)
{
    x1 = cos(rot);
    x2 = sin(rot);
    x3 = 0;
    x4 = 0;
    y1 = -sin(rot);
    y2 = cos(rot);
    y3 = 0;
    y4 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 1;
    z4 = 0;
    w1 = 0;
    w2 = 0;
    w3 = 0;
    w4 = 1;

}

Vector4 Matrix4::operator*(Vector4 rhs)
{
    Vector4 intVect;
    intVect.x = x1 * rhs.x + y1 * rhs.y + z1 * rhs.z + w1 * rhs.w;
    intVect.y = x2 * rhs.x + y2 * rhs.y + z2 * rhs.z + w2 * rhs.w;
    intVect.z = x3 * rhs.x + y3 * rhs.y + z3 * rhs.z + w3 * rhs.w;
    intVect.w = x4 * rhs.x + y4 * rhs.y + z4 * rhs.z + w4 * rhs.w;

    return intVect;
}

Matrix4 Matrix4::operator *(Matrix4 rhs)
{

    Matrix4 IntMat;

    IntMat.x1 = x1 * rhs.x1
              + y1 * rhs.x2
              + z1 * rhs.x3
              + w1 * rhs.x4;

    IntMat.x2 = x2 * rhs.x1
              + y2 * rhs.x2
              + z2 * rhs.x3
              + w2 * rhs.x4;

    IntMat.x3 = x3 * rhs.x1
              + y3 * rhs.x2
              + z3 * rhs.x3
              + w3 * rhs.x4;

    IntMat.x4 = x4 * rhs.x1
              + y4 * rhs.x2
              + z4 * rhs.x3
              + w4 * rhs.x4;

    IntMat.y1 = x1 * rhs.y1
              + y1 * rhs.y2
              + z1 * rhs.y3
              + w1 * rhs.y4;

    IntMat.y2 = x2 * rhs.y1
              + y2 * rhs.y2
              + z2 * rhs.y3
              + w2 * rhs.y4;

    IntMat.y3 = x3 * rhs.y1
              + y3 * rhs.y2
              + z3 * rhs.y3
              + w3 * rhs.y4;

    IntMat.y4 = x4 * rhs.y1
              + y4 * rhs.y2
              + z4 * rhs.y3
              + w4 * rhs.y4;

    IntMat.z1 = x1 * rhs.z1
              + y1 * rhs.z2
              + z1 * rhs.z3
              + w1 * rhs.z4;

    IntMat.z2 = x2 * rhs.z1
              + y2 * rhs.z2
              + z2 * rhs.z3
              + w2 * rhs.z4;

    IntMat.z3 = x3 * rhs.z1
              + y3 * rhs.z2
              + z3 * rhs.z3
              + w3 * rhs.z4;

    IntMat.z4 = x4 * rhs.z1
              + y4 * rhs.z2
              + z4 * rhs.z3
              + w4 * rhs.z4;

    IntMat.w1 = x1 * rhs.w1
              + y1 * rhs.w2
              + z1 * rhs.w3
              + w1 * rhs.w4;

    IntMat.w2 = x2 * rhs.w1
              + y2 * rhs.w2
              + z2 * rhs.w3
              + w2 * rhs.w4;

    IntMat.w3 = x3 * rhs.w1
              + y3 * rhs.w2
              + z3 * rhs.w3
              + w3 * rhs.w4;

    IntMat.w4 = x4 * rhs.w1
              + y4 * rhs.w2
              + z4 * rhs.w3
              + w4 * rhs.w4;

    

    return IntMat;
}


Vector4& Matrix4::operator [](int input)
{
    switch (input)
    {
    case 0:
        return matrix[0];

    case 1:
        return matrix[1];

    case 2:
        return matrix[2];

    case 3:
        return matrix[3];
    }



}


Matrix4::Matrix4(const Matrix4 & other)
{
    *this = other;
}

void Matrix4::operator=(const Matrix4 & other)
{
    for (int i = 0; i < 16; i++)
    {
        M4[i] = other.M4[i];
    }
}

Matrix4 Matrix4::identity()
{
    return Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

Matrix4::Matrix4()
{
    *this = identity();
}

Matrix4::Matrix4(float X1, float X2, float X3, float X4, float Y1, float Y2, float Y3, float Y4, float Z1, float Z2, float Z3, float Z4, float W1, float W2, float W3, float W4)
{
    x1 = X1;
    x2 = X2;
    x3 = X3;
    x4 = X4;
    y1 = Y1;
    y2 = Y2;
    y3 = Y3;
    y4 = Y4;
    z1 = Z1;
    z2 = Z2;
    z3 = Z3;
    z4 = Z4;
    w1 = W1;
    w2 = W2;
    w3 = W3;
    w4 = W4;
}


Matrix4::~Matrix4()
{
}
