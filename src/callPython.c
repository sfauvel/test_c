#include <stdio.h>
//#include <Python.h>
#include <python2.7/Python.h>
#include "../include/call.h"


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
   simpleCall("python/square.py", "square", "i", 4);
   return 0;
}


int hello() {
   printf("Hello, World!\n");
}

// Run a script written into the function.
int runPythonScript() {
   Py_Initialize();
   PyRun_SimpleString("from time import time,ctime\n"
                     "print 'Today is',ctime(time())\n"
                     "print 'Hello from python script'\n");
   Py_Finalize();
}

// Run a python file with arguments.
int runPythonFile(char *filename) {

   FILE* to_run_script= fopen(filename, "r");
   if (to_run_script != NULL)
   {
       int argc;
       char * argv[2];

       argc = 2;
       argv[0] = filename;
       argv[1] = "Hello from c";

       Py_SetProgramName(argv[0]);
       Py_Initialize();

       PySys_SetArgv(argc, argv);

       PyRun_SimpleFile(to_run_script, filename);

       Py_Finalize();
   }
   else
   {
        printf("File '%s' not found\n", filename);
   }
}


// see https://www.linuxjournal.com/article/8497
// Run a function hard coded into the method.
int runPythonFunction(char *filename) {

    FILE* to_run_script= fopen(filename, "r");
    if (to_run_script != NULL)
    {
        printf("Calling Python to make a sum.\n");

        // Initialize the Python interpreter.
        Py_Initialize();

        PyRun_SimpleFile(to_run_script, filename);

        // Get a reference to the main module.
        PyObject* main_module =   PyImport_AddModule("__main__");

        // Get the main module's dictionary
        PyObject* main_dict =   PyModule_GetDict(main_module);

        // Get function
        PyObject* expression = PyDict_GetItemString(main_dict, "add");

        // Execute function
        PyObject* result = PyObject_CallFunction(expression, "ii", 2, 5);

        // Convert result
        int value = PyInt_AsLong(result);

        printf("Result: %d\n", value);

        Py_Finalize();
    }
    else
    {
        printf("File '%s' not found\n", filename);
    }
}



#define _callPython(...) do { \
   printf("Calling Python function: %s\n", function); \
   Py_Initialize(); \
   PyRun_SimpleFile(to_run_script, filename); \
   PyObject* main_module =   PyImport_AddModule("__main__"); \
   PyObject* main_dict =   PyModule_GetDict(main_module); \
   PyObject* expression = PyDict_GetItemString(main_dict, function); \
   PyObject* result = PyObject_CallFunction(expression, __VA_ARGS__); \
   int value = PyInt_AsLong(result); \
   printf("Result: %d\n", value); \
   Py_Finalize(); \
} while(0)

// Call python function with variable arguments
int simpleCall(char * filename, char* function, char* types, int arg1, int arg2)
{
    FILE* to_run_script = fopen(filename, "r");
    if (to_run_script != NULL)
    {
        _callPython(types, arg1, arg2);
    }
    else
    {
        printf("File '%s' not found\n", filename);
    }
}

// Call function but with hard coded parameters
int callFunction(char * filename, char* function, int arg1, int arg2)
{
    FILE* to_run_script = fopen(filename, "r");
    if (to_run_script != NULL)
    {
        printf("Calling Python function: %s\n", function);

        // Initialize the Python interpreter.
        Py_Initialize();

        PyRun_SimpleFile(to_run_script, filename);

        // Get a reference to the main module.
        PyObject* main_module =   PyImport_AddModule("__main__");

        // Get the main module's dictionary
        PyObject* main_dict =   PyModule_GetDict(main_module);

        // Get function
        PyObject* expression = PyDict_GetItemString(main_dict, function);

        // Execute function
        PyObject* result = PyObject_CallFunction(expression, "ii", arg1, arg2);

        // Convert result
        int value = PyInt_AsLong(result);

        printf("Result: %d\n", value);

        Py_Finalize();
    }
    else
    {
        printf("File '%s' not found\n", filename);
    }
}



