#pragma once
#include <math.h>
#include <iostream>
#include "config.h"

template <typename dataType> class Vector2
    {
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

        void operator = (const PHYSENG_DATA_TYPE &right);
        
        // Casts
        operator bool () const;
        operator PHYSENG_DATA_TYPE () const;

        // Getters
        dataType length () const;
        Vector2 dir () const;

        #ifdef SFML_VECTOR2_HPP
        
        sf::Vector2f toSf ()
            {
            return sf::Vector2f (x, y);
            }

        #endif // SFML_VECTOR2_HPP

    };

// Vectord = vector default
typedef Vector2 <PHYSENG_DATA_TYPE> Vectord;
