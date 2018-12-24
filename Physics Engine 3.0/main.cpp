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

Vectord acceleration (State state,
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

    Vectord output = body->getState ()->a;
    
    *(body->getState ()) = initial;
    
    return output;
    }