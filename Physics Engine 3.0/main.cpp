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

int main() 
    {
    MPoint mp (Vectord (0, 0), 1.0, .0);

    mp.~MPoint ();

    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
