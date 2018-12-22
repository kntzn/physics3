#pragma once
#include "Vector.h"
#include "darray.h"

struct State
    {
    // Coords
    Vectord r;
    Vectord v;
    Vectord a;

    // Angle
    PHYSENG_DATA_TYPE angle;
    PHYSENG_DATA_TYPE omega;
    PHYSENG_DATA_TYPE aAng;
    };

struct Derivative
    {
    // Coords
    Vectord dr;
    Vectord dv;

    // Angle
    Vectord dAng;
    Vectord dOmega;
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