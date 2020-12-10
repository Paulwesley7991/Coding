#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
 try // Instruction where an error could occur
 {
 int divisor = 0;
 int dividend = 1;
 int quotient = dividend/divisor; // An error occurs, the program would crash!
 }
 catch (...) // This generally intercepts the error and throws an error message.
 {
 cerr << "Problem detected…"<< endl; // Output of the error using cerr
 }

 system("pause");
 return 0;
}
