#include "includes.h"

bool Logger (Error err);
bool CheckId (Error err);

FILE* log = NULL;

int main()
    {
    log = fopen ("log.txt", "w");

    ErrorController controller;

    controller.AddErrorHandler (&Logger);
    controller.AddErrorHandler (&CheckId);

    controller.PushError (Error(0, "first error"));
    controller.PushError (Error(1, "second error"));

    printf ("raw errors:\n");

    for (auto error = controller.GetErrors().begin(); error != controller.GetErrors().end(); error++)
        printf ("Error[%d]: %s\n", error->Id, error->message.c_str());

    return 0;
    }

bool Logger (Error err)
    {
    fprintf (log, "Error[%d]: %s\n", err.Id, err.message.c_str());

    return false;
    }

bool CheckId (Error err)
    {
    if (err.Id == 1)
        {
        printf ("Solve!\n");
        return true;
        }

    return false;
    }
