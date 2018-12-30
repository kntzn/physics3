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

    Node ( dataType value, Node* left = nullptr, Node* right = nullptr ):
        value ( value ),
        prev ( left ),
        next ( right )
        {
        }


    Node ( Node* left = nullptr, Node* right = nullptr ):
        prev ( left ),
        next ( right )
        {
        }
        
    };

template <typename dataType> class List
    {
    private:
        size_t currentLength = 0;
        size_t reservedCapacity = 0;
        
        Node <dataType>* front = nullptr;
        Node <dataType>* back = nullptr;
        
        
        // ----Memory-safety precautions
        
        Node <dataType>* borderBack  = nullptr;
        Node <dataType>* borderFront = nullptr;
        
        // ----
        
    public:
    
        // Constructors and destructor
        List ( size_t reservedCapacity = 0 )
            {
            front = new Node <dataType>();
            back  = new Node <dataType>();
            borderFront = new Node <dataType>();
            borderBack  = new Node <dataType>();   
            
            clear();

            this->reservedCapacity = reservedCapacity;
            }
          
        // -------- DEEP BETA  ---------------------------------------------------------------------------
        // ---- Iterating backend
        dataType* begin() 
            {
            return front;
            }
            
        dataType* end()
            {
            return back;
            }
            
        //// ↑ non-const ones;
        //// ↓ const methods;
        
        const Node <dataType>* begin() const
            {
            return front;
            }
            
        const Node <dataType>* end() const
            {
            return back;
            }
            
        // ------    
        
        // ------------------------------------------------------------------------------------------------
        

        
        void clear() // puts key elements to their default position relatively to each other;
            {
            *front = { borderFront, back };
            *back = { borderBack, front };
            *borderFront = { borderFront, front };
            *borderBack = { back, borderBack };
            }
        
        
        size_t size() // returns quantity of filled cells;
            {
            return currentLength;
            }

        
        void push_back ( dataType value ) 
            {
            Node <dataType>* newElement = new Node ( value, back, borderBack );
            back->next = newElement;
            
            back = newElement;
            
            currentLength++;
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
            
            currentLength--;
            }
        
        void push_front ( dataType value )
            {
            Node <dataType>* newElement = new Node <dataType> ( value, borderFront, front );
            front->prev = newElement;
            
            front = newElement;
            
            currentLength++;
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
            
            currentLength--; 
            }
        
        
        void insert ( dataType value, size_t index ) // inserts new value in a such way that now: tempList [ index ] = value;
            {
            Node <dataType>* currentElement = front;
            
            index += 2;
            
            for ( int i = 0; i < index; i++ )
                {
                currentElement = currentElement->next;
                }
               
            Node <dataType>* newElement = new Node <dataType> ( value, currentElement->prev, currentElement );
            
            currentElement->prev->next = newElement;
            currentElement->prev = newElement;
            
            currentLength++;
            }
            
        #ifdef prsVal
        dataType erase ( size_t index )  // erases cell with index = index;
        #else
        void erase ( size_t index )
        #endif
            {
            index += 2;
            
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
            
            currentLength--;
            }


        const dataType& operator[] ( size_t index ) const // subscription 
            {
            Node <dataType>* currentElement = front;
            
            index += 2;
            
            for ( int i = 0; i < index; i++ )
                {
                currentElement = currentElement->next;
                }
                
            return currentElement->value;
            }
        
        // TODO:
        // Container getters
        // begin [IMPOSSIBLE FOR NOW]
        // end [IMPOSSIBLE FOR NOW]

        // Modifiers
        //void push_back (dataType value); [DONE]
        //bool pop_back (); [DONE]
        //bool push_front (dataType value); [DONE]
        //bool pop_front (); [DONE]
        //bool insert (dataType value, sarrln index); [DONE]
        //bool erase (sarrln index); [DONE]
        
        // Size getters
        //arrln size (); [DONE]
        //bool empty (); [DONE]
        //arrln capacity (); [POST-PONED]
        
        // Size setters
        //void clear (); [DONE]

    };
