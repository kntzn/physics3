#pragma once
#include "Vector.h"

struct State
    {
    Vectord r;
    Vectord v;
    Vectord a;
    };

struct Derivative
    {
    Vectord dr;
    Vectord dv;
    };

class MPoint
    {
    private:
        State state;
        PHYSENG_DATA_TYPE m;

    public:
        MPoint (Vectord position,
                PHYSENG_DATA_TYPE mass,
                Vectord velocity);
        ~MPoint ();

    

        Derivative evaluate (const State & initial,
                             PHYSENG_DATA_TYPE dt,
                             const Derivative & d);
            

        void integrate (PHYSENG_DATA_TYPE dt);

        State getState ()
            {
            return state;
            }
    };