#pragma once

#pragma once
#include <math.h>
#include "config.h"


template <typename dataType> class Vector
    {
    public:
        // Data
        dataType x = 0, y = 0;

        // Constructors and destructors
        Vector ()
            {}
        Vector (dataType X, dataType Y)
            {
            x = X;
            y = Y;
            }
        Vector (dataType alpha)
            {
            x = cos (alpha);
            y = sin (alpha);
            }

        // Getters
        dataType length ()
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
Vectord operator * (const Vectord &left, const double factor)
    {
    return Vectord (left.x * factor, left.y * factor);
    }
Vectord operator *= (Vectord &left, const double factor)
    {
    return Vectord (left.x = left.x * factor, left.y = left.y * factor);
    }

// Scalar division
Vectord operator / (const Vectord &left, const double factor)
    {
    return Vectord (left.x / factor, left.y / factor);
    }
Vectord operator /= (Vectord &left, const double factor)
    {
    return Vectord (left.x = left.x / factor, left.y = left.y / factor);
    }

// Vector multiplication
PHYSENG_VECTOR_DATA_TYPE operator ^ (const Vectord &left, const Vectord &right)
    {
    return left.x*right.y - left.y*right.x;
    }
