#include <iostream>
#include <cstdlib>
using namespace std;
// DoSomething throws different types, depending on the
// value of the Problem parameter.
void DoSomething(int Problem)
{
 switch (Problem)
 {
 case 0: throw 5; break; // throws int
 case 1: throw (string)"test.dat"; break; // throws string
 case 2: throw 2.1; break; // throws double
 case 3: throw 'c'; break; // throws char
 }
}
// Test program
int main()
{
 // insert a number for the Problem variable
 int Selection;
 cout << "Insert a number between 0 and 3:" << endl;
 cin >> Selection;
 // The try block catches the exception in DoSomething
 try
 {
 DoSomething (Selection);
 }
 catch(int i) // Handler for int
 {
 cerr << "Integer " << i << endl;
 }
 catch(string s) // Handler for string
 {
 cerr << "String " << s << endl;
 }
 catch(double f) // Handler for double
 {
 cerr << "Float " << f << endl;
 }
 catch(...) // Handles all the other types of exceptions
 {
 cerr << "General Error" << endl;
 }
 system("pause");
 return 0;
}
