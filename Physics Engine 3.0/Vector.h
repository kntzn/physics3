#ifndef _VECTOR_H

#define _VECTOR_H

#include <math.h>
#include <iostream>
#include "config.h"

template <typename dataType> class Vector2
    {
    private:
        // Vectord = vector default
        typedef Vector2 <PHYSENG_DATA_TYPE> Vectord;

    public:
        // Data
        dataType x, y;

        // Constructors and destructors
        Vector2 ():
            x (0),
            y (0)
            { }
        Vector2 (dataType X, dataType Y):
            x (X),
            y (Y)
            { }
        Vector2 (dataType alpha):
            x (cos (alpha)),
            y (sin (alpha))
            { }

        // Getters
        dataType length () const
            {
            return dataType (sqrt (x*x + y*y));
            }
        Vector2 dir () const
            {
            return *this / length ();
            }

        // Casts
        operator bool () const
            {
            return (this->x != 0 && this->y != 0);
            }

        void operator = (const PHYSENG_DATA_TYPE &right) const
            {
            if (this->length ())
                {
                PHYSENG_DATA_TYPE k = right / this->length ();
                this->x *= k;
                this->y *= k;
                }
            }
        
        // Plus
        Vectord operator + (const Vectord &right) const
            {
            return Vectord (this->x + right.x,
                            this->y + right.y);
            }
        Vectord operator + () const
            {
            return *this;
            }
        Vectord operator += (const Vectord &right)
            {
            return Vectord (this->x = this->x + right.x,
                            this->y = this->y + right.y);
            }
        
        // Minus
        Vectord operator - (const Vectord &right) const
            {
            return Vectord (this->x - right.x,
                            this->y - right.y);
            }
        Vectord operator - () const
            {
            return Vectord (-this->x, -this->y);
            }
        Vectord operator -= (const Vectord &right)
            {
            return Vectord (this->x = this->x - right.x,
                            this->y = this->y - right.y);
            }

        // Vector multiplication
        PHYSENG_DATA_TYPE operator ^ (const Vectord &right) const
            {
            return this->x*right.y - this->y*right.x;
            }
        // Scalar multiplication
        PHYSENG_DATA_TYPE operator * (const Vectord &right) const
            {
            return (PHYSENG_DATA_TYPE)(this->x * right.x + this->y * right.y);
            }
        Vectord operator * (const PHYSENG_DATA_TYPE &factor) const
            {
            return Vectord (this->x*factor, this->y*factor);
            }
        Vectord operator *= (const PHYSENG_DATA_TYPE &factor) const
            {
            return Vectord (this->x = this->x * factor,
                            this->y = this->y * factor);
            }

        // Scalar division
        Vectord operator / (const PHYSENG_DATA_TYPE &factor) const
            {
            if (factor)
                return Vectord (this->x / factor, this->y / factor);
            else
                return Vectord (0, 0);
            }
        Vectord operator /= (const PHYSENG_DATA_TYPE &factor) const
            {
            if (factor)
                return Vectord (this->x = this->x / factor,
                                this->y = this->y / factor);
            else
                return Vectord (0, 0);
            }

        // Comparators
        const bool operator == (const Vectord &right) const
            {
            return ((this->x == right.x) && (this->y == right.y));
            }
        const bool operator != (const Vectord &right) const
            {
            return !(*this == right);
            }
        const bool operator < (Vectord &right) const
            {
            return (this->length () < right.length ());
            }
        const bool operator <= (Vectord &right) const
            {
            return (this->length () <= right.length ());
            }
        const bool operator > (Vectord &right) const
            {
            return (this->length () > right.length ());
            }
        const bool operator >= (Vectord &right) const
            {
            return (this->length () >= right.length ());
            }
        
        // Logical operators
        const bool operator ! () const
            {
            return ! ((bool) *this);
            }
        const bool operator && (Vectord &right) const
            {
            return (((bool) *this) && ((bool)right));
            }
        const bool operator || (Vectord &right) const
            {
            return (((bool) *this) || ((bool)right));
            }
        
        //operator PHYSENG_DATA_TYPE () const;

        
        #ifdef SFML_VECTOR2_HPP
        
        sf::Vector2f toSf ()
            {
            return sf::Vector2f (x, y);
            }

        #endif // SFML_VECTOR2_HPP

    };

// Vectord = vector default
typedef Vector2 <PHYSENG_DATA_TYPE> Vectord;

#endif // !_VECTOR_H


