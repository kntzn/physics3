#pragma once

#include "stream.h"
#include <string>
#include <iostream>
#include <string.h>

class console : stream
    {
    public:

    console():
        stream()
        {}

    ~console()
        {}

    StreamErrorCodes read  (char* str, unsigned* length);
    StreamErrorCodes write (const char* str, unsigned length);

    StreamErrorCodes write (const char* str)
        {
        return write (str, 0);
        }

    StreamErrorCodes read (char* str)
        {
        return read (str, 0);
        }
    };

StreamErrorCodes console :: read (char* str, unsigned* length)
    {
    std :: string str_;
    std :: cin >> str_;

    sprintf(str, "%s", str_.c_str());

    if (length) *length = str_.length();

    return ERRNO;
    }

StreamErrorCodes console :: write (const char* str, unsigned length)
    {
    std :: cout << std :: string(str);

    return ERRNO;
    }
