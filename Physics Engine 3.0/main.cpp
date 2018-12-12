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
#include "list.h"

#include "SFML/System.hpp"
#include "Vector.h"

int main() 
    {
    Vectord vec (10, 20);

    std::cin >> vec;

    std::cout << (double) vec;

    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
