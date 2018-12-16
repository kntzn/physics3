#pragma once

typedef enum StreamErrorCodes
    {
    ERRNO = 0
    } StrErrCodes;

class stream
    {
    public:
    stream()
        {}

    virtual ~stream()
        {};

    virtual StreamErrorCodes read  (char* str, unsigned* length) = 0;
    virtual StreamErrorCodes write (const char* str, unsigned length) = 0;
    };
