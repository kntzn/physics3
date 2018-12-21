#pragma once

#include <stdio.h>
#include <string.h>

#include "defstreams.h"

using namespace std;

class Error
    {
    public:

    size_t ErrorId;
    string message;

    Error():
        ErrorId (0),
        message()
        {}


    Error(size_t SEI):
        ErrorId (SEI),
        message()
        {}


    Error(size_t SEI, string SEM):
        ErrorId (SEI),
        message (SEM)
        {}
    };

class ErrorController
    {
    vector Errors <Error>;

    vector ErrorHandlers <Error>;
    };



