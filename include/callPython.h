#ifndef CALL_PYTHON_H_   /* Include guard */
#define CALL_PYTHON_H_

int hello();

// Run a script written into the function.
int runPythonScript();

// Run a python file with arguments.
int runPythonFile(char *filename);

// see https://www.linuxjournal.com/article/8497
// Run a function hard coded into the method.
int runPythonFunction(char *filename);

// Call python function with variable arguments
int simpleCall(char * filename, char* function, char* types, int arg1, int arg2);

// Call function but with hard coded parameters
int callFunction(char * filename, char* function, int arg1, int arg2);




#endif // CALL_PYTHON_H_