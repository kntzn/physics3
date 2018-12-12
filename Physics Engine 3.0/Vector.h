#pragma once

#pragma once
#include <math.h>
#include "config.h"


template <typename dataType> class Vector
    {
    public:
        // Data
        dataType x, y;

        // Constructors and destructors
        Vector ():
            x (0),
            y (0)
            { }
        Vector (dataType X, dataType Y):
            x (X),
            y (Y)
            { }
        Vector (dataType alpha):
            x (cos (alpha)),
            y (sin (alpha))
            { }

        operator bool () const;
        operator PHYSENG_VECTOR_DATA_TYPE () const;

        // Getters
        dataType length () const
            {
            return sqrt (x*x + y*y);
            }
        Vector dir ()
            {
            return Vector (x / length (), y / length ());
            }

        #ifdef SFML_VECTOR2_HPP
        
        sf::Vector2f toSf ()
            {
            return sf::Vector2f (x, y);
            }

        #endif // SFML_VECTOR2_HPP

    };

// Vectord = vector default
typedef Vector <PHYSENG_VECTOR_DATA_TYPE> Vectord;

// Operators overload

// Binary plus
Vectord operator + (const Vectord &left, const Vectord &right)
    {
    return Vectord (left.x + right.x, left.y + right.y);
    }
Vectord operator += (Vectord &left, Vectord &right)
    {
    return Vectord (left.x = left.x + right.x, left.y = left.y + right.y);
    }
// Unary plus
Vectord operator + (const Vectord &right)
    {
    return right;
    }

// Binary minus
Vectord operator - (const Vectord &left, const Vectord &right)
    {
    return Vectord (left.x - right.x, left.y - right.y);
    }
Vectord operator -= (Vectord &left, Vectord &right)
    {
    return Vectord (left.x = left.x - right.x, left.y = left.y - right.y);
    }
// Unary minus
Vectord operator - (const Vectord &right)
    {
    return Vectord (-right.x, -right.y);
    }

// Scalar multiplication
PHYSENG_VECTOR_DATA_TYPE operator * (const Vectord &left, const Vectord &right)
    {
    return (double)(left.x * right.x + left.y * right.y);
    }
Vectord operator * (const Vectord &left, const PHYSENG_VECTOR_DATA_TYPE factor)
    {
    return Vectord (left.x * factor, left.y * factor);
    }
Vectord operator *= (Vectord &left, const PHYSENG_VECTOR_DATA_TYPE factor)
    {
    return Vectord (left.x = left.x * factor, left.y = left.y * factor);
    }

// Scalar division
Vectord operator / (const Vectord &left, const PHYSENG_VECTOR_DATA_TYPE factor)
    {
    return Vectord (left.x / factor, left.y / factor);
    }
Vectord operator /= (Vectord &left, const PHYSENG_VECTOR_DATA_TYPE factor)
    {
    return Vectord (left.x = left.x / factor, left.y = left.y / factor);
    }

// Vector multiplication
PHYSENG_VECTOR_DATA_TYPE operator ^ (const Vectord &left, const Vectord &right)
    {
    return left.x*right.y - left.y*right.x;
    }

// Logical operators
const bool operator == (const Vectord &left, const Vectord &right)
    {
    return ((left.x == right.x) && (left.y == right.y));
    }
const bool operator != (const Vectord &left, const Vectord &right)
    {
    return !(left == right);
    }

const bool operator < (const Vectord &left, const Vectord &right)
    {
    return (left.length () < right.length ());
    }
const bool operator <= (const Vectord &left, const Vectord &right)
    {
    return (left.length () <= right.length ());
    }
const bool operator > (const Vectord &left, const Vectord &right)
    {
    return (left.length () > right.length ());
    }
const bool operator >= (const Vectord &left, const Vectord &right)
    {
    return (left.length () >= right.length ());
    }

// Casts
template <typename dataType> 
Vector<dataType>::operator bool () const
    {
    return (this->x != 0 && this->y != 0);
    }

template<typename dataType>
inline Vector<dataType>::operator PHYSENG_VECTOR_DATA_TYPE() const
    {
    return PHYSENG_VECTOR_DATA_TYPE (this->x + this->y);
    }
