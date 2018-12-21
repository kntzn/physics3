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

int main() 
    {
    const double dt_c = 0.1;

    darray <Vectord> pArr;
    pArr.push_back (Vectord (-0.5, -0.5));
    pArr.push_back (Vectord (0.5, -0.5));
    pArr.push_back (Vectord (0.5, 0.5));
    pArr.push_back (Vectord (-0.5, 0.5));

    Body mp (Vectord (-10, 0), 1.0, Vectord (10, 0), 4, pArr);
    Body mp1 (Vectord (10, 0), 1.0, Vectord (-10, 0), 4, pArr);
    Spring spr (mp.getPos (), mp1.getPos (), 10.0);

    darray <Body*> all_objects;

    all_objects.push_back (new Body (mp));
    all_objects.push_back (new Body (mp1));

    for (int i = 0; i < 1000; i++)
        {
        spr.update (mp.getPos (), mp1.getPos ());
        
        mp.accelerate (spr.getForceBegin ());
        mp1.accelerate (spr.getForceEnd ());

        mp.integrateEUL (dt_c);
        mp1.integrateEUL (dt_c);

        std::cout << spr.getPotEnergy () + mp.getKinEnergy () + mp1.getKinEnergy ()
            << ", ";
        }

    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
