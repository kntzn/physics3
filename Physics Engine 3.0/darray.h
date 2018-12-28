#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef size_t arrln;
typedef signed int sarrln;
#define SZ_DEFAULT 5

template <typename dataType> class darray
    {
    private:
        arrln currentLen, allocLen;
        dataType* container;
        
        // Allocates memory and fils it with poison value
        bool allocate (dataType* & newContainer, arrln len);
        
    public:
        // Constructors and destructor
        darray (darray <dataType> &darrayToCopy);
        darray (arrln Size = SZ_DEFAULT);
        ~darray ();
        
        // Container getters
        dataType & back ();
        dataType & front ();

        // Operators
        dataType & operator [] (sarrln index);
        
        // Modifiers
        bool push_back (dataType value);
        bool pop_back ();
        bool push_front (dataType value);
        bool pop_front ();
        bool insert (dataType value, sarrln index);
        bool erase (sarrln index);
        
        // Size getters
        arrln size ();
        bool empty ();
        arrln capacity ();

        // Size setters
        bool shrink ();
        bool resize (arrln newSize);
        void clear ();

    };


// Util
template<typename dataType>
inline bool darray<dataType>::allocate (dataType *& newContainer, arrln len)
    {
    if (!allocLen)
        {
        printf ("Size of array must be greater than zero\n");
        return false;
        }

    newContainer = nullptr;
    newContainer = (dataType*)calloc (len, sizeof (dataType));

    if (newContainer == nullptr)
        {
        printf ("Failed to allocate memory\n");
        return false;
        }

    return true;    
    }

// Constructors and destructors
template<typename dataType>
inline darray<dataType>::darray (darray <dataType> &darrayToCopy)
    {
    // Default values
    allocLen = darrayToCopy.capacity ();
    currentLen = darrayToCopy.size ();

    // Allocates memory
    allocate (container, allocLen);

    // Copies values
    for (arrln i = 0; i < currentLen; i++)
        container [i] = darrayToCopy [i];
    }


template<typename dataType>
inline darray<dataType>::darray (arrln Size)
    {
    // Default values
    currentLen = 0;
    allocLen = Size;
    
    // Allocates memory
    allocate (container, allocLen);
    }

template<typename dataType>
inline darray<dataType>::~darray ()
    {
    delete container;
    }


// Container getters
template<typename dataType>
dataType & darray <dataType>::back ()
    {
    if (!currentLen)
        {
        printf ("Unable to back ():\n\tArray is empty\n");
        assert (NULL);
        }


    return container [currentLen - 1];
    }

template<typename dataType>
dataType & darray <dataType>::front ()
    {
    msgassert (currentLen, "Unable to back ():\n\tArray is empty\n");
    return container [0];
    }


// Operators
template<typename dataType>
inline dataType & darray<dataType>::operator[](sarrln index)
    {
    if (index < 0)
        index += currentLen;

    if (!(0 <= index && index < (int) currentLen))
        printf ("index was %d / %zu\n", index, currentLen);
    assert (0 <= index && index < (int) currentLen);

    return container [index];
    }


// Modifiers
template<typename dataType>
inline bool darray<dataType>::push_back (dataType value)
    {
    if (currentLen == allocLen - 1)
        if (!resize ((allocLen * 3 / 2) + 1))
            return false;

    container [currentLen] = value;
    currentLen++;

    return true;
    }

template<typename dataType>
bool darray<dataType>::pop_back ()
    {
    if (!currentLen)
        {
        printf ("Unable to pop ():\n\tArray is empty\n");
        return false;
        }

    currentLen--;

    return true;
    }

template<typename dataType>
bool darray<dataType>::push_front (dataType value)
    {
    if (currentLen == allocLen - 1)
        if (!resize ((allocLen * stretch_k) + 1))
            return false;

    for (int i = currentLen+1; i > 0; i--)
        container [i] = container [i - 1];

    container [0] = value;
    currentLen++;

    return true;
    }

template<typename dataType>
bool darray<dataType>::pop_front ()
    {
    for (int i = 0; i < currentLen - 1; i++)
        container [i] = container [i + 1];
    
    currentLen--;

    return true;
    }

template<typename dataType>
inline bool darray<dataType>::insert (dataType value, sarrln index)
    {
    if (index < 0)
        index = currentLen + index;
    if (index < 0 || index > currentLen)
        {
        printf ("Index is out of range\n");
        return false;
        }

    if (currentLen == allocLen - 1)
        if (!resize ((allocLen * stretch_k) + 1))
            return false;

    for (int i = currentLen + 1; i > index; i--)
        container [i] = container [i - 1];

    container [index] = value;
    currentLen++;

    return true;
    }

template<typename dataType>
inline bool darray<dataType>::erase (sarrln index)
    {
    if (index < 0)
        index = currentLen + index;
    if (index < 0 || index > currentLen)
        {
        printf ("Index is out of range\n");
        return false;
        }

    for (int i = index; i < currentLen; i++)
        container [i] = container [i + 1];

    currentLen--;

    return true;
    }


// Size getters
template<typename dataType>
arrln darray<dataType>::size ()
    {
    return currentLen;
    }

template<typename dataType>
bool darray<dataType>::empty ()
    {
    return (currentLen == 0);
    }

template<typename dataType>
inline arrln darray<dataType>::capacity ()
    {
    return allocLen;
    }

template<typename dataType>
inline void darray<dataType>::clear ()
    {
    currentLen = 0;
    }

// Size setters
template<typename dataType>
bool darray<dataType>::shrink ()
    {
    return resize (currentLen);
    }

template<typename dataType>
bool darray<dataType>::resize (arrln newSize)
    {
    if (newSize >= currentLen)
        {
        dataType* newContainer = nullptr;

        if (allocate (newContainer, newSize))
            {
            // Copies the memory
            for (arrln i = 0; i < currentLen; i++)
                newContainer [i] = container [i];

            allocLen = newSize;

            // Releases memory
            free (container);
            container = newContainer;

            return true;
            }
        else
            return false;
        }
    else
        printf ("Failed to 'resize ()'\n\tNew length is less than old one\n");

    return false;
    }

#undef SZ_DEFAULT
