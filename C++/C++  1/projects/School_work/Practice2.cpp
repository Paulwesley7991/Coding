#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
int array[]={5,10,15,20,25};
cout << "The address of the first array is: " << array << endl;
// or
cout << "The address of the first array is: " << &array[0] << endl;
cout << "The value of the first array element is: " << *array << endl;
// or
cout << " The value of the first array element is: " << array[0] << endl;
system("pause");
}
