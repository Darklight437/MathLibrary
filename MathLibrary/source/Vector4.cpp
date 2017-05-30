#include "Vector4.h"
#include<math.h>


Vector4 Vector4:: operator+(Vector4& refVect)
{
    Vector4 internalVect(x, y, z, w);

    internalVect.x += refVect.x;
    internalVect.y += refVect.y;
    internalVect.z += refVect.z;
    internalVect.w += refVect.w;

    return internalVect;

}

Vector4 Vector4::operator-(Vector4& refVect)
{
    Vector4 internalVect(x, y, z, w);
    internalVect.x -= refVect.x;
    internalVect.y -= refVect.y;
    internalVect.z -= refVect.z;
    internalVect.w -= refVect.w;
    return internalVect;
}

Vector4::operator float*()
{

    return &x;

}


Vector4 Vector4::cross(Vector4 rhs)
{
    Vector4 lhs(x, y, z, w);
    Vector4 resultantvect;
    resultantvect.x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
    resultantvect.y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
    resultantvect.z = (lhs.x * rhs.y) - (lhs.y * rhs.x);
    resultantvect.w = 0;
    return resultantvect;
}

Vector4 Vector4::operator*(float scale)
{
    Vector4 internalVect(x, y, z, w);
    internalVect.x *= scale;
    internalVect.y *= scale;
    internalVect.z *= scale;
    internalVect.w *= scale;

    return internalVect;
}

Vector4 Vector4::operator*(Vector4 vect)
{
    Vector4 internalVect;
    internalVect.x *= vect.x;
    internalVect.y *= vect.y;
    internalVect.z *= vect.z;
    internalVect.w *= vect.w;
    return internalVect;
}

float Vector4::magnitude()
{
    float magnitude;
    Vector4 internalVect;
    internalVect.x = x * x;
    internalVect.y = y * y;
    internalVect.z = z * z;
    internalVect.w = w * w;
    magnitude = sqrt(internalVect.x + internalVect.y + internalVect.z);
    return magnitude;
}

Vector4 Vector4::Vector4CpNorm()
{
    float mag = magnitude();
    Vector4 internalVect;
    internalVect.x = x;
    internalVect.y = y;
    internalVect.z = z;
    internalVect.w = w;

    if (mag != 0)
    {
        internalVect.x / mag;
        internalVect.y / mag;
        internalVect.z / mag;
        internalVect.w / mag;
        return Vector4(internalVect.x, internalVect.y, internalVect.z, internalVect.w);
    }

}

float Vector4::dot(Vector4 rhs)
{
    float finalfloat;
    Vector4 internalvect;
    internalvect.x = x * rhs.x;
    internalvect.y = y * rhs.y;
    internalvect.z = z * rhs.z;
    internalvect.w = w * rhs.w;
    finalfloat = internalvect.x + internalvect.y + internalvect.z;
    return finalfloat;
}


Vector4 operator *(float lhs, Vector4& rhs)
{

    return rhs * lhs;
}



void Vector4::normalise()
{

    float mag = magnitude();
    if (mag != 0)
    {
        x /= mag;
        y /= mag;
        z /= mag;
        w /= mag;
    }

}


Vector4::Vector4(float valuex, float valuey, float valuez, float valuew)
{
    x = valuex;
    y = valuey;
    z = valuez;
    w = valuew;
}





Vector4::Vector4()
{
}


Vector4::~Vector4()
{
}
