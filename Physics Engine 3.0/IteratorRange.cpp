//
//  IteratorRange.cpp
//  Physics Engine 3.0
//
//  Created by Эльдар Дамиров on 28.12.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#pragma once
#include <iterator>

template <typename typeOfContainer> class IteratorRange 
    {
    public:
        IteratorRange ( typeOfContainer begin, typeOfContainer end ):
            first ( begin ),
            last  ( end )
            {
            
            }
                    
                    
    private:
        typeOfContainer first = NULL;
        typeOfContainer last = NULL;
    };
