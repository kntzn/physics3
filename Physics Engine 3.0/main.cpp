//
//  main.cpp
//  test
//
//  Created by Эльдар Дамиров on 10.12.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//
//  Improved by kntzn on 10.12.2018.
//  Copyright © 2018 kntzn. All rights reserved.
//

#include <iostream>
#include "list.h"

int main() 
    {
    lst <int> list;
//    std::cout << list.begin ();
    list.push_back (2);
    list.push_back (2);

//    for (auto i = list.begin (); i != list.end (); )

    #ifdef __APPLE__
        getchar();
    #else
        system("pause");
    #endif
    
    return 0;
    }
