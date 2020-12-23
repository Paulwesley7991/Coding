#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

class Numbers {
 private:
 float number1, number2;
 public:
 Numbers(): number1(0), number2(0) {}
 Numbers(float n1, float n2): number1(n1), number2(n2) {}

 // Declaring input/output functions as friend of the class
 friend istream& operator>> (istream& is, Numbers& a);
 friend ostream& operator<< (ostream& os, const Numbers& b);
};
// Input
istream& operator>> (istream& is, Numbers& a) {
 cout << endl << "Number1: ";
 is >> a.number1;
 cout << "Number2: ";
 is >> a.number2;
 return is;
}
// Output
ostream& operator<< (ostream& os, const Numbers& a) {
 os << "Number1; " << a.number1 << " Number2: " << a.number2 << endl;
 return os;
}
int main()
{
 Numbers x;
 cin >> x;
 cout << x;

 system("pause");
 return 0;
}
