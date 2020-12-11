#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Date{
private:
    short day;
    short month;
    unsigned int year;
public:
    void enterDate();
    void showData();
};
void Date::enterDate()
{
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
}

void Date::showData()
{
    cout << day << "." << month << "." << year << endl;
}

class Employee
{
private:
    string Surname;
    string Firstname;
    string Middlename;
    Date Dob;
    int Holidays;
    static int counter= 0;
public:
    void GetData();
    void ShowData();
    Employee(){}

};

void Employee::GetData()
{
    cout << "--Enter Data --" << endl;
    cout << "First name: ";
    cin >> FirstName;
    cout << "Surname: ";
    cin >> Surname;
}
int main()
{cout << "Testing Program" << endl;
system("pause");
system("cls");
}
