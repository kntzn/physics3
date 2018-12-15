//
//  Physics Engine 3.0
//  main.cpp
//
//  Created by Эльдар Дамиров on 10.12.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//
//  Improved by kntzn on 10.12.2018.
//  Copyright © 2018 kntzn. All rights reserved.
//
#include <iostream>
#include "FileIO 2.1 (24.06).h"

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

float acceleration (const State & state)
    {
    const float k = 15.0f;
    const float b = 0.1f;
    return -k * state.x;// -b * state.v;
    }

Derivative evaluate (const State & initial,
                     float dt,
                     const Derivative & d)
    {
    State state;
    state.x = initial.x + d.dx*dt;
    state.v = initial.v + d.dv*dt;

    Derivative output;
    output.dx = state.v;
    output.dv = acceleration (state);
    return output;
    }

void integrate (State & state,
                float dt)
    {
    Derivative a, b, c, d;

    a = evaluate (state, 0.0f, Derivative ());
    b = evaluate (state, dt*0.5f, a);
    c = evaluate (state, dt*0.5f, b);
    d = evaluate (state, dt, c);

    float dxdt = 1.0f / 6.0f *
        (a.dx + 2.0f * (b.dx + c.dx) + d.dx);

    float dvdt = 1.0f / 6.0f *
        (a.dv + 2.0f * (b.dv + c.dv) + d.dv);

    state.x = state.x + dxdt * dt;
    state.v = state.v + dvdt * dt;
    }

int main() 
    {
    const double dt_c = 0.1;
    MPoint mp (Vectord (0, 0), 1.0, Vectord (10, 0));

    //mp.~MPoint ();

    std::string out;

    for (int i = 0; i < 10000; i++)
        {
        mp.integrateRK4 (0.001);
        
        //if (! (i%100))
        std::cout << mp.getState ().v*mp.getState ().v / 2.0 + 
                     mp.getState ().r * mp.getState ().r * 10.0 / 2.0 << std::endl;
        }

    

    system ("pause");

    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
