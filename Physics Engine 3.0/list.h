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

    Node ():
        prev (nullptr),
        next (nullptr)
        {}
    Node (dataType val, Node* left, Node* right):
        value (val),
        prev (left),
        next (right)
        {
        }
    };

template <typename dataType> class lst
    {
    private:
        size_t currentLen;
        Node <dataType> * front, * tail;

    public:
        // Constructors and destructor
        lst ();
        ~lst ();

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


template<typename dataType>
inline lst<dataType>::lst ()
    {
    }

template<typename dataType>
inline lst<dataType>::~lst ()
    {
    }


