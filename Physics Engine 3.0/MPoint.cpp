#include "MPoint.h"

MPoint::MPoint (Vectord position,
                PHYSENG_DATA_TYPE mass,
                Vectord velocity)
    {
    state.r = position;
    m = mass;
    state.v = velocity;
    state.a = Vectord (0, 0);
    }

MPoint::~MPoint ()
    {
    }

/*
Derivative MPoint::evaluate (const State & initial, 
                             PHYSENG_DATA_TYPE dt, 
                             const Derivative & d)
    {
    State new_state;
    new_state.r = initial.r + d.dr*dt;
    new_state.v = initial.v + d.dv*dt;

    Derivative output;
    output.dr = new_state.v;
    output.dv = (-new_state.r* 10.0);
    return output;
    }

void MPoint::integrateRK4 (PHYSENG_DATA_TYPE dt)
    {
    Derivative a, b, c, d;

    a = evaluate (state, 0.0, Derivative ());
    b = evaluate (state, dt * 0.5, a);
    c = evaluate (state, dt * 0.5, b);
    d = evaluate (state, dt, c);

    Vectord drdt = Vectord (a.dr + Vectord ((b.dr + c.dr) * 2.0) + d.dr) / 6.0;
    Vectord dvdt = Vectord (a.dv + Vectord ((b.dv + c.dv) * 2.0) + d.dv) / 6.0;

    state.r += Vectord (drdt * dt);
    state.v += Vectord (dvdt * dt);
    state.a = Vectord (0, 0);
    }
*/
void MPoint::integrateEUL (PHYSENG_DATA_TYPE dt)
    {
    state.v += Vectord (state.a * dt);
    state.r += Vectord (state.v * dt);
    state.a = Vectord (0, 0);
    }

void MPoint::addForce (Vectord force)
    {
    state.a += force / m;
    }
void MPoint::accelerate (Vectord acceleration)
    {
    state.a += acceleration;
    }

Vectord MPoint::getPos ()
    {
    return state.r;
    }
Vectord MPoint::getVel ()
    {
    return state.v;
    }
PHYSENG_DATA_TYPE MPoint::getMass ()
    {
    return m;
    }

State MPoint::getState ()
    {
    return state;
    }
PHYSENG_DATA_TYPE MPoint::getKinEnergy ()
    {
    return PHYSENG_DATA_TYPE (state.v * state.v * m / 2.0);
    }
