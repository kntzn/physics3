#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>


//#define prsVal // preserves and returns value during pop and erase operations;

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
        
    Node ( dataType value = NULL, Node* left = nullptr, Node* right = nullptr ):
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
        size_t reservedCapacity = 0;
        
        Node <dataType>* front = nullptr;
        Node <dataType>* back = nullptr;
        
        
        // ----Memory-safety precautions
        dataType poisonValue = dynamic_cast <dataType> ( NULL );
        Node <dataType>* borderBack  = nullptr;
        Node <dataType>* borderFront = nullptr;
        
        // ----
        
    public:
    
        // Constructors and destructor
        list ( size_t reservedCapacity = 0 ): 
            borderBack ( poisonValue, back, this ),
            borderFront ( poisonValue, this, front ),
            front ( poisonValue, borderFront, back ),
            back ( poisonValue, borderBack, front )
            {
            this->reservedCapacity = reservedCapacity;
            }
        
        ~list ();

        
        void push_back ( dataType value )
            {
            Node <dataType>* newElement ( value, back, borderBack );
            back->next = newElement;
            
            back = newElement;
            }
        
        #ifdef prsVal
        dataType pop_back()
        #else
        void pop_back()
        #endif
            {
            #ifdef prsVal
            dataType preservedValue = back->value;
            #endif 
            
            back = back->prev;
            delete back->next;
            
            back->next = borderBack;
            
            #ifdef prsVal
            return preservedValue;
            #endif 
            }
        
        void push_front ( dataType value )
            {
            Node <dataType>* newElement ( value, borderFront, front );
            front->prev = newElement;
            
            front = newElement;
            }
            
        #ifdef prsVal
        dataType pop_front()
        #else
        void pop_front()
        #endif
            {
            #ifdef prsVal
            dataType preservedValue = front->value;
            #endif 
            
            front = back->next;
            delete front->prev;
            
            front->prev = borderFront;
            
            #ifdef prsVal
            return preservedValue;
            #endif 
            }
        
        
        void insert ( dataType value, size_t index )
            {
            Node <dataType>* currentElement = front;
            
            for ( int i = 0; i < index; i++ )
                {
                currentElement = currentElement->next;
                }
               
            Node <dataType>* newElement ( value, currentElement->prev, currentElement );
            }
            
        #ifdef prsVal
        dataType erase ( size_t index )
        #else
        void erase ( size_t index )
        #endif
            {
            Node <dataType>* currentElement = front;
            
            for ( int i = 0; i < index; i++ )
                {
                currentElement = currentElement->next;
                }
                
            #ifdef prsVal
            dataType preservedValue = currentElement->value;
            #endif 
            
            currentElement->prev->next = currentElement->next;
            currentElement->next->prev = currentElement->prev;
            
            delete currentElement;
            
            #ifdef prsVal
            return preservedValue;
            #endif 
            }

        // TODO:
        // Container getters
        // begin
        // end

        // Modifiers
        //void push_back (dataType value); [DONE]
        //bool pop_back (); [DONE]
        //bool push_front (dataType value); [DONE]
        //bool pop_front (); [DONE]
        //bool insert (dataType value, sarrln index); [DONE]
        //bool erase (sarrln index); [DONE]
        
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
