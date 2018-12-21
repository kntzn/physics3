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
    protected:
        State state;
        PHYSENG_DATA_TYPE m;

    public:
        MPoint (Vectord position,
                PHYSENG_DATA_TYPE mass,
                Vectord velocity);
        ~MPoint ();

        /*

        Derivative evaluate (const State & initial,
                             PHYSENG_DATA_TYPE dt,
                             const Derivative & d);
        
        
        void integrateRK4 (PHYSENG_DATA_TYPE dt);
        */

        void integrateEUL (PHYSENG_DATA_TYPE dt);

        // Setters
        void addForce (Vectord force);
        void accelerate (Vectord acceleration);

        // Getters
        Vectord getPos ();
        Vectord getVel ();
        PHYSENG_DATA_TYPE getMass ();

        State getState ();
        PHYSENG_DATA_TYPE getKinEnergy ();
            
    };