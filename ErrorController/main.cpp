#include "includes.h"

int main()
    {
    console con;

    con.write ("Hello, world");

    char str[256] = "";

    con.read (str);

    con.write("SheEt: ");
    con.write(str);

    return 0;
    }
