#pragma once
#include "Vector.h"

class MPoint
    {
    private:
        Vectord r, v, a;
        PHYSENG_DATA_TYPE m;

    public:
        MPoint (Vectord position,
                PHYSENG_DATA_TYPE mass,
                Vectord velocity);
        ~MPoint ();
    };