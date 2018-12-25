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

State acceleration (State state,
                      darray <Body*> &all_objects,
                      darray <Pair*> &object_pairs,
                      Body* body);

void integrateRK4 (PHYSENG_DATA_TYPE dt,
                   darray <Body*> &all_objects,
                   darray <Pair*> &object_pairs);

int main ()
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

    //all_objects.push_back (&mp);
    //all_objects.push_back (&mp1);

    //for (int i = 0; i < 10; i++)
        //all_objects.push_back (new Body (Vectord (rand ()%10, rand()%10), 10.0, Vectord (10, 0), 4, pArr));

    //SpringPair sp (all_objects, 100.0, 0, 1, 2, 3);

    //object_pairs.push_back (&sp);

    //all_objects.push_back (&mp);
    //all_objects.push_back (&mp1);
    
    #define N 10

    for (int i = 0; i < N; i++)
        all_objects.push_back (new Body (Vectord (rand()%10, rand()%10), 1.0, Vectord (i-5, i-5), 4, pArr));

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            {
            object_pairs.push_back (new SpringPair (all_objects, 10.0, i, j, 0, 1));
            }


    for (int i = 0; i < 10000; i++)
        {
        
        for (arrln i = 0; i < object_pairs.size (); i++)
            object_pairs [i]->update (all_objects);
      
        for (arrln i = 0; i < all_objects.size (); i++)
            all_objects [i]->integrateEUL (dt_c);

       /*
        integrateRK4 (dt_c, 
                      all_objects,
                      object_pairs);
             */

        
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
    state.aAng = 0.0;

    *(body->getState ());

    *(body->getState ()) = state;

    *(body->getState ());
 
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
    output.dr   = new_state.v;
    output.dAng = new_state.omega;

    output.dv = new_state.a;
    output.dw = new_state.aAng;

    return output;
    }


void integrateRK4 (PHYSENG_DATA_TYPE dt,
                   darray <Body*> &all_objects,
                   darray <Pair*> &object_pairs)
    {
    darray <Derivative> a, b, c, d;

    //std::cout << "before a: " << all_objects [0]->getState ()->angle << std::endl;

    for (int i = 0; i < all_objects.size (); i++)
        a.push_back (evaluate (all_objects [i],
                     *all_objects [i]->getState (),
                     0.0,
                     Derivative (),
                     all_objects,
                     object_pairs));

    //std::cout << "before b: " << all_objects [0]->getState ()->angle << std::endl;

    for (int i = 0; i < all_objects.size (); i++)
        b.push_back (evaluate (all_objects [i],
                     *all_objects [i]->getState (),
                     dt * 0.5,
                     a [i],
                     all_objects,
                     object_pairs));

    for (int i = 0; i < all_objects.size (); i++)
        c.push_back (evaluate (all_objects [i],
                     *all_objects [i]->getState (),
                     dt * 0.5,
                     b [i],
                     all_objects,
                     object_pairs));

    for (int i = 0; i < all_objects.size (); i++)
        d.push_back (evaluate (all_objects [i],
                     *all_objects [i]->getState (),
                     dt,
                     c [i],
                     all_objects,
                     object_pairs));

    for (int i = 0; i < all_objects.size (); i++)
        {
        Vectord drdt = Vectord (a [i].dr + Vectord ((b [i].dr + c [i].dr) * 2.0) + d [i].dr) / 6.0;
        Vectord dvdt = Vectord (a [i].dv + Vectord ((b [i].dv + c [i].dv) * 2.0) + d [i].dv) / 6.0;

        PHYSENG_DATA_TYPE dAngdt = (a [i].dAng + ((b [i].dAng + c [i].dAng) * 2.0) + d [i].dAng) / 6.0;
        PHYSENG_DATA_TYPE dwdt   = (a [i].dw   + ((b [i].dw   + c [i].dw)   * 2.0) + d [i].dw)   / 6.0;

        

        all_objects [i]->getState ()->r += drdt * dt;
        all_objects [i]->getState ()->v += dvdt * dt;
        all_objects [i]->getState ()->a = Vectord (0, 0);

        all_objects [i]->getState ()->angle += dAngdt * dt;
        all_objects [i]->getState ()->omega += dwdt * dt;
        all_objects [i]->getState ()->aAng  = 0.0;
        }
    }

/*
void MPoint::integrateEUL (PHYSENG_DATA_TYPE dt)
{
state.v += Vectord (state.a * dt);
state.r += Vectord (state.v * dt);
state.a = Vectord (0, 0);
}

*/