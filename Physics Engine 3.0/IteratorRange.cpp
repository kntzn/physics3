//
//  IteratorRange.cpp
//  Physics Engine 3.0
//
//  Created by Эльдар Дамиров on 28.12.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#pragma once
#include <algorithm>
#include <iterator>

/*
USAGE EXAMPLE:
#include "IteratorRange.cpp"

    ...
std::vector <int> tempVector { 1, 2, 3, 4, 5, 6 };
  
    for (  auto currentElement : UpTo ( tempVector, 4 ) )
        {
        printf ( "OUTPUT: %d\n", currentElement );
        }
    ...
*/

/*
REQUIRES PREDEFINED CONTAINER'S begin() & end() methods;
*/



template <typename Iterator> class IteratorRange 
    {
    public:
        IteratorRange ( Iterator begin, Iterator end ):
            first ( begin ),
            last  ( end )
            {
            
            }
                    
    Iterator begin() const
        {
        return first;
        }
        
    Iterator end() const 
        {
        return last;
        }
                    
    private:
        Iterator first = NULL;
        Iterator last = NULL;
    };

template <typename Container> auto UpTo ( Container& inputContainer, size_t top )
    {
    return IteratorRange { inputContainer.begin(), next ( inputContainer.begin(), std::min ( top, inputContainer.size() ) ) };
    }
