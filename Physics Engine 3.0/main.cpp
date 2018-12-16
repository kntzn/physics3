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

int main() 
    {
    const double dt_c = 0.1;
    MPoint mp (Vectord (0, 0), 1.0, Vectord (10, 0));

    std::string out;

    for (int i = 0; i < 10000; i++)
        {
        mp.integrateEUL (dt_c);
        }

    system ("pause");

    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
