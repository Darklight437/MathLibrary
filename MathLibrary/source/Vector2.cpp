#include "Vector2.h"
#include <math.h>




Vector2 Vector2::operator+(Vector2& refVect)
{
    Vector2 internalVect (x, y);
    
    internalVect.x += refVect.x;
    internalVect.y += refVect.y;
    return internalVect;

}

Vector2 Vector2::operator-(Vector2& refVect)
{
    Vector2 internalVect(x, y);
    internalVect.x -= refVect.x;
    internalVect.y -= refVect.y;
    
    return internalVect;
}

Vector2 Vector2::operator*(float scale)
{
    Vector2 internalVect(x, y);
    internalVect.x *= scale;
    internalVect.y *= scale;
    return internalVect;
}

Vector2 Vector2::operator*(Vector2 vect)
{
    Vector2 internalVect(x, y);
    internalVect.x *= vect.x;
    internalVect.y *= vect.y;
    return internalVect;
}

Vector2 operator *(float lhs, Vector2& rhs)
{
    
    return rhs * lhs;
}


float Vector2::magnitude()
{
    float magnitude;
    Vector2 internalVect(x * x, y * y);
    magnitude = sqrt(internalVect.x + internalVect.y);
    return magnitude;
}

Vector2 Vector2::Vector2CpNorm()
{
    float mag = magnitude();
    Vector2 internalVect;
    internalVect.x = x;
    internalVect.y = y;
    

    if (mag = !0)
    {
        internalVect.x / mag;
        internalVect.y / mag;
        return Vector2(internalVect.x, internalVect.y);
    }

}


void Vector2::normalise()
{

    float mag = magnitude();
    if (mag != 0)
    {
      x = x / mag;
      y = y / mag;
        
    }


}

 Vector2::operator float*()
{
    return &x;
}


Vector2::Vector2(float valuex, float valuey)
{
    x = valuex;
    y = valuey;
}


float Vector2::dot(Vector2 rhs)
{
    float finalfloat;
    Vector2 internalvect;
    internalvect.x = x * rhs.x;
    internalvect.y = y * rhs.y;
    finalfloat = internalvect.x + internalvect.y;
    return finalfloat;
}

Vector2::Vector2()
{
}


Vector2::~Vector2()
{
}


