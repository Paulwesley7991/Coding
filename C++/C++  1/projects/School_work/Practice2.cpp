#include <iostream>
#include <cstdlib>
using namespace std;
class Birthday
{
 private:
 int year, month, day;
 public:
 Birthday(int j, int m, int t): year(j), month(m), day(t) {} // Constructor with member initializer list
 Birthday() {} // Default constructor

 void setYear (int j) { year = j; }
 void setMonth(int m) { month = m; }
 void setDay(int t) { day = t; }
 void displayData() { cout << day << "-" << month << "-" << year << endl; }
};
int main()
{
 Birthday Heinz;
 Birthday *Peter;

 Heinz.setYear(1964);
 Heinz.setMonth(1);
 Heinz.setDay(22);

 Peter = &Heinz;
 Peter->setMonth(12);
 Heinz.displayData();
 Peter->displayData();
 system("pause");
}
