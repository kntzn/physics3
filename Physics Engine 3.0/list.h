#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>


template <typename dataType> struct Node
    {
    dataType value;
    Node* next;
    Node* prev;

    Node():
        prev (nullptr),
        next (nullptr)
        {
        }
        
    Node ( dataType value, Node* left, Node* right ):
        value ( value ),
        prev ( left ),
        next ( right )
        {
        }
        
    };

template <typename dataType> class list
    {
    private:
        size_t currentLength = 0;
        size_t wholeSpaceReserved = 0;
        
        Node <dataType>* front = nullptr;
        Node <dataType>* tail = nullptr;
        
        
        // ----Memory-safety precautions
        dataType poisonValue = dynamic_cast <dataType> ( NULL );
        Node <dataType> borderBack  = NULL;
        Node <dataType> borderFront = NULL;
        
        // ----
        
    public:
        // Constructors and destructor
        list ( size_t reservedCapacity = 0 ): 
            borderBack ( poisonValue, &borderFront, this ),
            borderFront ( poisonValue, this, &borderBack )
            {
            
            }
        
        ~list ();

        

        // TODO:
        // Container getters
        // begin
        // end

        // Modifiers
        //void push_back (dataType value);

        //bool pop_back ();
        //bool push_front (dataType value);
        //bool pop_front ();
        //bool insert (dataType value, sarrln index);
        //bool erase (sarrln index);
        
        // Size getters
        //arrln size ();
        //bool empty ();
        //arrln capacity ();
        
        // Size setters
        //void clear ();

    };


//template<typename dataType>
//inline lst<dataType>::lst ()
//    {
//    }
//
//template<typename dataType>
//inline lst<dataType>::~lst ()
//    {
//    }
