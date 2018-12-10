//
//  main.cpp
//  test
//
//  Created by Эльдар Дамиров on 10.12.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//
//  Improved by kntzn on 10.12.2018.
//  Copyright © 2018 kntzn. All rights reserved.
//

#include <iostream>

struct State
    {
    float x;      // позиция
    float v;      // скорость
    };

struct Derivative
    {
    float dx;      // dx/dt = скорость
    float dv;      // dv/dt = ускорение
    };

float acceleration (const State & state, double t)
    {
    const float k = 15.0f;
    const float b = 0.1f;
    return -k * state.x - b * state.v;
    }

Derivative evaluate (const State & initial,
                     double t,
                     float dt,
                     const Derivative & d)
    {
    State state;
    state.x = initial.x + d.dx*dt;
    state.v = initial.v + d.dv*dt;

    Derivative output;
    output.dx = state.v;
    output.dv = acceleration (state, t + dt);
    return output;
    }

void integrate (State & state,
                double t,
                float dt)
    {
    Derivative a, b, c, d;

    a = evaluate (state, t, 0.0f, Derivative ());
    b = evaluate (state, t, dt*0.5f, a);
    c = evaluate (state, t, dt*0.5f, b);
    d = evaluate (state, t, dt, c);

    float dxdt = 1.0f / 6.0f *
        (a.dx + 2.0f * (b.dx + c.dx) + d.dx);

    float dvdt = 1.0f / 6.0f *
        (a.dv + 2.0f * (b.dv + c.dv) + d.dv);

    state.x = state.x + dxdt * dt;
    state.v = state.v + dvdt * dt;
    }

int main() 
    {
    
    const double dt_c = 0.01;

    State st;
    st.x = 0.f;
    st.v = 1.f;

    for (int i = 0; i < 1000; i++)
        {
        integrate (st, 0, dt_c);
        printf ("%f, ", st.x);
        }

    system ("pause");

    return 0;
    }
