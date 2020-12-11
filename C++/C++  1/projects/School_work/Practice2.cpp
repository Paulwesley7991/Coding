#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
 int x=18, *z;
 z=&x;
 cout << "Own address of pointer z: = " << &z << endl;
 cout << "Value of variable x: " << *z << endl;
 cout << " The address of variable x stored in z is" << z << endl;
 cout << "Address of variable x is: " << &x << endl;
 system("pause");
}
