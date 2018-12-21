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
    const double dt_c = 0.1;

    darray <Vectord> pArr;
    
    pArr.push_back (Vectord (-0.5, 0.5));
    pArr.push_back (Vectord (0.5, 0.5));
    pArr.push_back (Vectord (0.5, -0.5));
    pArr.push_back (Vectord (-0.5, -0.5));

    Body mp (Vectord (-10, 0), 10.0, Vectord (10, 0), 4, pArr);
    Body mp1 (Vectord (10, 0), 10.0, Vectord (-10, 0), 4, pArr);

    darray <Body*> all_objects;

    all_objects.push_back (&mp);
    all_objects.push_back (&mp1);

    SpringPair sp (all_objects, 100.0, 0, 1, 2, 3);

    all_objects.push_back (&mp);
    all_objects.push_back (&mp1);

    for (int i = 0; i < 1000; i++)
        {
        sp.update (all_objects, dt_c);
      
        mp.integrateEUL (dt_c);
        mp1.integrateEUL (dt_c);

        printf ("%lf, ", sp.getPotEnergy () + mp.getKinEnergy () + mp1.getKinEnergy ());
        }

    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
