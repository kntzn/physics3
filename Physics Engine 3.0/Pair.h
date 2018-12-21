#pragma once
#include "darray.h"
#include "Body.h"

class Pair
    {
    protected:
        int id_left = -1, id_right = -1;
        Pair (size_t left, size_t right)
            {
            id_left = left;
            id_right = right;
            }

    public:
        virtual void update (darray <Body*> all_objects, PHYSENG_DATA_TYPE dt) = 0;

        virtual double getPotEnergy () = 0;
    };
