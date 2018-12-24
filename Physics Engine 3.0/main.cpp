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

Vectord acceleration (State state,
                      darray <Body*> &all_objects,
                      darray <Pair*> &object_pairs,
                      Body* body);

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
        /*
        for (arrln i = 0; i < object_pairs.size (); i++)
            object_pairs [i]->update (all_objects);
      
        for (arrln i = 0; i < all_objects.size (); i++)
            all_objects [i]->integrateEUL (dt_c);
*/
        State state;
        state.r = Vectord (-10.0 - double (i) / 100, 0);

        Vectord acc = acceleration (state, all_objects, object_pairs, all_objects [0]);

        

        /*
        PHYSENG_DATA_TYPE e = 0;

        for (arrln i = 0; i < all_objects.size (); i++)
            e += all_objects [i]->getKinEnergy ();
        for (arrln i = 0; i < object_pairs.size (); i++)
            e += object_pairs [i]->getPotEnergy ();

        printf ("%lf, ", e);*/
        }



    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }

void updateAllPairs (darray <Body*> &all_objects,
                     darray <Pair*> &object_pairs)
    {
    for (int i = 0; i < object_pairs.size (); i++)
        object_pairs [i]->update (all_objects);
    }

State acceleration (State state,
                    darray <Body*> &all_objects,
                    darray <Pair*> &object_pairs,
                    Body* body)
{
    State initial = *(body->getState ());

    state.a = Vectord (0, 0);
    *(body->getState ()) = state;

 
    for (int i = 0; i < object_pairs.size (); i++)
        if (object_pairs [i]->getLeft () == body ||
            object_pairs [i]->getRight () == body)
            object_pairs [i]->update (all_objects);

    State output = *body->getState ();
    
    *(body->getState ()) = initial;
    
    return output;
    }

Derivative evaluate (Body* body,
                     const State & initial,
                     const PHYSENG_DATA_TYPE dt,
                     const Derivative & d,
                     darray <Body*> &all_objects,
                     darray <Pair*> &object_pairs)
    {
    State new_state;
    new_state.r = initial.r + d.dr*dt;
    new_state.v = initial.v + d.dv*dt;

    new_state.angle = initial.angle + d.dr*dt;
    new_state.omega = initial.omega + d.dv*dt;

    State accelerated_state = acceleration (new_state, all_objects, object_pairs, body);
    new_state.a    = accelerated_state.a;
    new_state.aAng = accelerated_state.aAng;

    Derivative output;
    output.dr = new_state.v;
    output.dAng = new_state.omega;

    output.dv = new_state.a;
    output.dw = new_state.aAng;

    return output;
    }

/*
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