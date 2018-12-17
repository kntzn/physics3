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
#include "MPoint.h"
#include "Spring.h"

int main() 
    {
    const double dt_c = 0.1;
    MPoint mp (Vectord (0, 0), 1.0, Vectord (10, 0));
    MPoint mp1 (Vectord (0, 0), 1.0, Vectord (-10, 0));
    Spring spr (mp.getPos (), mp1.getPos (), 10.0);

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
