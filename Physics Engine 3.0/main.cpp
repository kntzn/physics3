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

#include "Vector.h"
#include "MPoint.h"


struct State
    {
    Vectord r;      // позиция
    Vectord v;      // скорость
    };

struct Derivative
    {
    Vectord dr;      // dx/dt = скорость
    Vectord dv;      // dv/dt = ускорение
    };

Vectord acceleration (const State & state)
    {
    return Vectord (-state.r* 15.0);// -b * state.v;
    }

Derivative evaluate (const State & initial,
                     PHYSENG_DATA_TYPE dt,
                     const Derivative & d)
    {
    State state;
    state.r = initial.r + d.dr*dt;
    state.v = initial.v + d.dv*dt;

    Derivative output;
    output.dr = state.v;
    output.dv = acceleration (state);
    return output;
    }

void integrate (State & state,
                PHYSENG_DATA_TYPE dt)
    {
    Derivative a, b, c, d;

    a = evaluate (state, 0.0, Derivative ());
    b = evaluate (state, dt * 0.5, a);
    c = evaluate (state, dt * 0.5, b);
    d = evaluate (state, dt, c);

    Vectord dxdt = Vectord (a.dr + Vectord ((b.dr + c.dr) * 2.0) + d.dr) / 6.0;
    Vectord dvdt = Vectord (a.dv + Vectord ((b.dv + c.dv) * 2.0) + d.dv) / 6.0;

    state.r = state.r + dxdt * dt;
    state.v = state.v + dvdt * dt;
    }


int main() 
    {
    //MPoint mp (Vectord (0, 0), 1.0, .0);

    //mp.~MPoint ();

    State init;
    init.r = Vectord (0, 0);
    init.v = Vectord (10, 0);

    for (int i = 0; i < 1000; i++)
        {

        integrate (init, 0.001);
        
        //if (! (i%100))
        std::cout << init.v*init.v / 2.0 + init.r * init.r * 15.0 / 2.0 << std::endl;
        }


    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
