#pragma once
#include "darray.h"
#include "Body.h"

class Pair
    {
    protected:
        int id_left = -1, id_right = -1;
        Body *leftPtr, *rightPtr;

        // я спал 2 часа, опасно
        Pair (size_t left, size_t right):
            id_left (left),
            id_right (right),
            leftPtr (nullptr),
            rightPtr (nullptr)
            {
            }

    public:
        virtual void update (darray <Body*> all_objects) = 0;

        virtual double getPotEnergy () = 0;

        Body* getLeft ()
            { return leftPtr; }
        Body* getRight ()
            { return rightPtr; }
    };
