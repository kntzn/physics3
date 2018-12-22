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
#include "MPoint.h"
#include "Spring.h"
#include "Body.h"
#include "SpringPair.h"

#define printLine printf ("File %s\n\tLine %d\n\n", __FILE__, __LINE__)

int main() 
    {
    const double dt_c = 0.01;

    darray <Vectord> pArr;
    
    pArr.push_back (Vectord (-0.5, 0.5));
    pArr.push_back (Vectord (0.5, 0.5));
    pArr.push_back (Vectord (0.5, -0.5));
    pArr.push_back (Vectord (-0.5, -0.5));

    Body mp (Vectord (-10, 0), 10.0, Vectord (10, 0), 4, pArr);
    Body mp1 (Vectord (10, 0), 10.0, Vectord (-10, 0), 4, pArr);

    darray <Body*> all_objects;
    darray <Pair*> object_pairs;

    all_objects.push_back (&mp);
    all_objects.push_back (&mp1);

    SpringPair sp (all_objects, 100.0, 0, 1, 2, 3);

    object_pairs.push_back (&sp);

    all_objects.push_back (&mp);
    all_objects.push_back (&mp1);

    for (int i = 0; i < 1000; i++)
        {
        for (arrln i = 0; i < object_pairs.size (); i++)
            object_pairs [i]->update (all_objects, dt_c);
      
        for (arrln i = 0; i < all_objects.size (); i++)
            all_objects [i]->integrateEUL (dt_c);

        PHYSENG_DATA_TYPE e = 0;

        for (arrln i = 0; i < all_objects.size (); i++)
            e += all_objects [i]->getKinEnergy ();
        for (arrln i = 0; i < object_pairs.size (); i++)
            e += object_pairs [i]->getPotEnergy ();

        printf ("%lf, ", e);
        }



    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }


void RK4 (darray <Body*> all_objects, 
          darray <Pair*> object_pairs)
/*
Derivative evaluate (const State & initial,
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

void MPoint::integrateEUL (PHYSENG_DATA_TYPE dt)
    {
    state.v += Vectord (state.a * dt);
    state.r += Vectord (state.v * dt);
    state.a = Vectord (0, 0);
    }

*/
