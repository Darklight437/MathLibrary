#include "Vector3.h"
#include <math.h>



//guessing that it wants me to translate the 1st vector by the second
//Vector::Vector3 Vector::Vector3Translate(const Vector3&a_first, const Vector3&a_second)
//{
//    Vector3 m_storage = a_first;
//    m_storage.x += a_second.x;
//
//}


 Vector3 Vector3:: operator+( Vector3& refVect)
{   
    Vector3 internalVect(x,y,z);

    internalVect.x += refVect.x;
    internalVect.y += refVect.y;
    internalVect.z += refVect.z;

    return internalVect;

}

 Vector3 Vector3::operator-(Vector3& refVect)
{
    Vector3 internalVect(x, y, z);
    internalVect.x -= refVect.x;
    internalVect.y -= refVect.y;
    internalVect.z -= refVect.z;
    return internalVect;
}

 Vector3::operator float*()
 { 
    
    return &x;
     
 }

 Vector3 operator *(float lhs, Vector3& rhs)
 {

     return rhs * lhs;
 }



 Vector3 Vector3::operator*(float scale)
 {
     Vector3 internalVect(x, y, z);
     internalVect.x *= scale;
     internalVect.y *= scale;
     internalVect.z *= scale;
     return internalVect;
 }

 Vector3 Vector3::operator*(Vector3 vect)
 {
     Vector3 internalVect;
     internalVect.x *= vect.x;
     internalVect.y *= vect.y;
     internalVect.z *= vect.z;
     return internalVect;
 }

 float Vector3::magnitude()
 {
     float magnitude;
     Vector3 internalVect;
     internalVect.x = x * x;
     internalVect.y = y * y;
     internalVect.z = z * z;
     magnitude = sqrt(internalVect.x + internalVect.y + internalVect.z);
     return magnitude;
 }

 float Vector3::dot(Vector3 rhs)
 {
     float finalfloat;
     Vector3 internalvect;
     internalvect.x = x * rhs.x;
     internalvect.y = y * rhs.y;
     internalvect.z = z * rhs.z;
     finalfloat = internalvect.x + internalvect.y + internalvect.z;
     return finalfloat;
 }


 Vector3 Vector3::Vector3CpNorm()
 {
     float mag = magnitude();
     Vector3 internalVect;
     internalVect.x = x;
     internalVect.y = y;
     internalVect.z = z;
     
     if (mag != 0)
     {
         internalVect.x / mag;
         internalVect.y / mag;
         internalVect.z / mag;
         return Vector3(internalVect.x, internalVect.y, internalVect.z);
     }
     
 }

 Vector3 Vector3::cross(Vector3 rhs)
 {
     Vector3 lhs(x, y, z);
     Vector3 resultantvect;
     resultantvect.x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
     resultantvect.y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
     resultantvect.z = (lhs.x * rhs.y) - (lhs.y * rhs.x);

     return resultantvect;
 }

 Vector3 &Vector3::operator=(const Vector3 & other)
 {
     x = other.x;
     y = other.y;
     z = other.z;
     return *this;

 }



 void Vector3::normalise()
 {

     float mag = magnitude();
     if (mag != 0)
     {
         x /= mag;
         y /= mag;
         z /= mag;
     }
     
 }

 Vector3::Vector3(const Vector3& other)
 {
     *this = other;
 }

Vector3::Vector3(float valuex, float valuey, float valuez)
{
    x = valuex;
    y = valuey;
    z = valuez;
}


Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3:: ~Vector3()
{
}
