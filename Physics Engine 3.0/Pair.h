#pragma once
#include "darray.h"
#include "Body.h"

class Pair
    {
    protected:
        int id_left = -1, id_right = -1;
        Vectord accelLeft, accelRight;

        // я спал 2 часа, опасно
        Pair (size_t left, size_t right):
            accelLeft (Vectord (0, 0)),
            accelRight (Vectord (0, 0)),
            id_left (left),
            id_right (right)
            {
            }

    public:
        virtual void update (darray <Body*> all_objects) = 0;

        virtual double getPotEnergy () = 0;

        int getIdxLeft ()
            { return id_left; }
        int getIdxRight ()
            { return id_right; }
    };
