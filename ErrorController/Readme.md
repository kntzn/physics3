Simple error handlers' module.

To use:

1. #include "ErrorController.h"
2. Create ErrorController
3. Add handlers(1)
4. When the error appears call PushError method of ErrorController and pass Error (size_t id, string  message) as parameter.

Error handling starts with the first handler added to the ErrorController.
(1) Handler is a function bool ErrorHandler (Error err). If it return true the handling stops. Otherwise it continues.
If there was no handlers that returns true, error adds to vector <Error> that can be accesed by GetErrors(); 