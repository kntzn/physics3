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
        State state_temp;
        Vectord r, v, a;
        PHYSENG_DATA_TYPE m;

    public:
        MPoint (Vectord position,
                PHYSENG_DATA_TYPE mass,
                Vectord velocity);
        ~MPoint ();

    

        Derivative evaluate (const State & initial,
                             PHYSENG_DATA_TYPE dt,
                             const Derivative & d)
            {
            State state;
            state.r = initial.r + d.dr*dt;
            state.v = initial.v + d.dv*dt;

            Derivative output;
            output.dr = state.v;
            output.dv = (-state.r* 10.0);
            return output;
            }

        void integrate (PHYSENG_DATA_TYPE dt)
            {
            Derivative a, b, c, d;

            a = evaluate (state_temp, 0.0, Derivative ());
            b = evaluate (state_temp, dt * 0.5, a);
            c = evaluate (state_temp, dt * 0.5, b);
            d = evaluate (state_temp, dt, c);

            Vectord drdt = Vectord (a.dr + Vectord ((b.dr + c.dr) * 2.0) + d.dr) / 6.0;
            Vectord dvdt = Vectord (a.dv + Vectord ((b.dv + c.dv) * 2.0) + d.dv) / 6.0;

            state_temp.r = state_temp.r + drdt * dt;
            state_temp.v = state_temp.v + dvdt * dt;
            }

        State getState ()
            {
            return state_temp;
            }
    };