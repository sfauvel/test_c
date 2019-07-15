#include <stdio.h>
//#include <Python.h>
#include <python2.7/Python.h>
#include "../include/callPython.h"


// See https://medium.com/just-me-me-programming-life/python-c-and-symbols-4628fb71a257
int main()
{
   // printf() displays the string inside quotation
   hello();
   runPythonScript();
   runPythonFile("python/hello.py");
   runPythonFile("python/readFile.py");
   runPythonFunction("python/square.py");
   callFunction("python/square.py", "add", 2, 7);
   simpleCall("python/square.py", "add", "ii", 4, 7);
   simpleCall("python/square.py", "square", "i", 4, 0);
   return 0;
}



