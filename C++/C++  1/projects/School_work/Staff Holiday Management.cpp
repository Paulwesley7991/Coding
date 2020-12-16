#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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
    string FirstName;
    string MiddleName;
    Date Dob;
    unsigned int Holidays;
    unsigned int Holidays_Taken;
    static int counter;
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
    cout << "Enter Date of birth";
    Dob.enterDate();
    // Determine current year
    time_t timestamp;
    tm *date;
    timestamp = time(0);
    date = localtime(&timestamp);
    int actYear = date->tm_year+1900;
    if((actYear-Dob.year) >= 50)
        Holidays = 32;
    else
        Holidays = 30;
}
class HourlyEmployee:public Employee
{
    private:
   double Hourly_wage;
   double Hours_worked;
};
class SalariedEmployee: public Employee
{
    private:
    double Annual_Salary;
};
class Manager: public Employee
{
private:
    double Profit_sharing;
};
class
class HolidayManagement
{private:
   string Employee_type;
   public:
       HolidayManagement(int select){
           switch(select){
       case 1:
        HourlyEmployee employee;
        employee.GetData();
        break;
       case 2:
        SalariedEmployee employee;
        employee.GetData();
        break;
       case 3:
        Manager employee;
        employee.GetData();
        }
       }
};
int main()
{
    int select;
    unsigned int counter;
    HolidayManagement Deggendorf[500];
    cout << "WELCOME TO STAFF HOLIDAY MANAGEMENT\n\n" << endl;
do{
        cout << "\t\t--MENU--\n" << endl;
        cout << "[1] Create Employee" << endl;
        cout << "[2] Delete Employee" << endl;
        cout << "[3] Book Holidays" << endl;
        cout << "[4] Search for Employee" << endl;
        cout << "[5] Show All Employees" << endl;
        cout << "[0] Exit" << endl;
        cout << endl << "Please select: ";
        cin >> select;
        switch(select)
        {
        case 1:
            if(counter >=  500){
                cout<<"cant create more employee. Maximum Number of Employee reached" <<endl;
                break;
            }
            cout<<"Please select which type of Employee:"<<endl;
            cout << "[1] HourlyEmployee" << endl;
            cout << "[2] SalariedEmployee" << endl;
            cout << "[3] Manager" << endl;
            cout << endl << "Please select: ";
            cin >> select;
            Deggendorf[counter] = HolidayManagement(select);
}
system("pause");
system("cls");
}
