#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

#include <cstdlib>
#include <iostream>
using namespace std;
class Numbers {
 private:
 float number1, number2;
 public:
 Numbers(): number1(0), number2(0) {}
 Numbers(float n1, float n2): number1(n1), number2(n2) {}

 // Prefix increment
 Numbers& operator++() {
 number1++;
 number2++;
 return *this;
 }

 // Postfix increment
 const Numbers operator++ (int) {
 Numbers t = *this;
 ++(*this);
 return t;
 }

 friend ostream& operator<< (ostream& os, const Numbers& b);
};
// Output
ostream& operator<< (ostream& os, const Numbers& a) {
 os << "Number1; " << a.number1 << " Number2: " << a.number2 << endl;
 return os;
}
int main()
{
 Numbers x(15,6), y(10,18), z;
 // Postfix
 cout << x++;
 // Prefix
 cout << ++x;

 system("pause");
 return 0;
}
