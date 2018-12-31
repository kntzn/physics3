#pragma once

#include <stdio.h>

#include <string>
#include <vector>
#include <list>

using namespace std;

class Error
    {
    public:

    size_t Id;
    string message;

    Error():
        Id (0),
        message()
        {}


    Error(size_t SEI):
        Id (SEI),
        message()
        {}


    Error(size_t SEI, string SEM):
        Id (SEI),
        message (SEM)
        {}
    };

typedef bool ErrorHandler (Error err);

class ErrorController
    {
    vector <Error> Errors;
    list <ErrorHandler*> ErrorHandlers;

    public:
        ErrorController():
            Errors(),
            ErrorHandlers()
            {}

        ~ErrorController()
        {}

    bool AddErrorHandler (ErrorHandler*, bool);
    bool PushError (Error);

    const vector<Error>& GetErrors();
    };

const vector<Error>& ErrorController :: GetErrors()
    {
    return Errors;
    }

bool ErrorController :: AddErrorHandler (ErrorHandler* hndlr, bool at_start = false)
    {
    if (!hndlr) return false;

    if (at_start)
        ErrorHandlers.push_front (hndlr);
    else
        ErrorHandlers.push_back (hndlr);

    return true;
    }

bool ErrorController :: PushError (Error error)
    {
    for (auto handler = ErrorHandlers.begin(); handler != ErrorHandlers.end(); handler++)
        {
        if ((*(*handler)) (error))
            return true;
        }

    Errors.push_back (error);

    return false;
    }


