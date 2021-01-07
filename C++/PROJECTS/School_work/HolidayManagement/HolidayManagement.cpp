#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date{
    friend class Employee;
    friend class HolidayManagement;
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
    friend class HolidayManagement;
private:
    string Surname;
    string FirstName;
    string MiddleName;
    Date Dob;
    static int Holidays;
    unsigned int Holidays_Taken;
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
void Employee::ShowData()
{
    cout<<"FirstName: "<<FirstName<<endl;
    cout<<"Surname: "<<Surname<<endl;
    cout<<"Date of Birth: ";
    Dob.showData();
}
class HourlyEmployee:public Employee
{
    private:
      double Hourly_wage;
      double Hours_worked;
    public:
       void GetData()
       {
           Employee::GetData();
           cout<< "Hourly Wage:";
           cin>> Hourly_wage;
           cout<< "Hours Worked:";
           cin>> Hours_worked;
       }
       void ShowData()
       {
           Employee::ShowData();
           cout<< "Hourly Wage: "<< Hourly_wage<<endl;
           cout<< "Hours Worked: "<< Hours_worked<<endl;
       }
};
class SalariedEmployee: public Employee
{
    private:
      double Annual_Salary;
    public:
        void GetData()
       {
           Employee::GetData();
           cout<< "Annual Salary:";
           cin>> Annual_Salary;
       }
       void ShowData()
       {
           Employee::ShowData();
           cout<< "Annual Salary: "<< Annual_Salary<<endl;
       }
};
class Manager: public Employee
{
    private:
        double Profit_sharing;
    public:
        void GetData()
       {
           Employee::GetData();
           cout<< "Profit sharing:";
           cin>> Profit_sharing;
       }
       void ShowData()
       {
           Employee::ShowData();
           cout<< "Profit sharing: "<< Profit_sharing<<endl;
       }
};

class HolidayManagement
{
   private:
   string Employee_type;
   Date Holiday_start;
   Date Holiday_end;
   HourlyEmployee hour_emp;
   SalariedEmployee salary_emp;
   Manager manager_emp;
   short int choice_type;
   unsigned int Holidays;

   public:
       HolidayManagement(){}
       HolidayManagement(int select){
    switch(select){
       case 1:{
        HourlyEmployee employee;
        employee.GetData();
        hour_emp = employee;
        Holidays = hour_emp.Holidays;
        choice_type = 1;
        break;}

       case 2:{
        SalariedEmployee employee;
        employee.GetData();
        salary_emp = employee;
        Holidays = salary_emp.Holidays;
        choice_type = 2;
        break;}

       case 3:{
        Manager employee;
        employee.GetData();
        manager_emp = employee;
        Holidays = manager_emp.Holidays;
        choice_type = 3;}
        }
       }
       ~HolidayManagement(){}
       void Delete_obj()
       {
           //HolidayManagement::~HolidayManagement();
       }
       void Book_Holidays()
       {
          bool pass = false;
          system("cls");
          cout <<"Please enter date of start of Holiday:"<<endl;
          Holiday_start.enterDate();
          Holiday_end.enterDate();
          if((Holiday_end.year < Holiday_start.year)||(Holiday_end.year < Holiday_start.year))
            {
                cout<<"Please Holiday Start and End year must be same!!!"<<endl;
                pass = true;
            }
            else{
                if((Holiday_end.day - Holiday_start.day)> Holidays)
                {
                    cout<<"You have exceeded your amount of Holidays left!!!"<<endl;
                    pass = true;
                }
          switch(Holiday_start.month)
          {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
               if(pass){break;}
                else{
                    cout<<"Holiday have being booked."<<endl;

                }
            }

          }

       }
       void Show_Data()
       {
           switch(choice_type)
           {
           case 1:{
            hour_emp.ShowData();
            cout<<"Number of Assigned Holidays: "<<Holidays<<endl;
            cout<<"Number of Available Holidays: "<<hour_emp.Holidays - hour_emp.Holidays_Taken<<endl;
            break;}
           case 2:{
            salary_emp.ShowData();
            cout<<"Number of Assigned Holidays: "<<Holidays<<endl;
            cout<<"Number of Available Holidays: "<<salary_emp.Holidays - salary_emp.Holidays_Taken<<endl;
            break;}
           case 3:{}
            manager_emp.ShowData();
            cout<<"Number of Assigned Holidays: "<<Holidays<<endl;
            cout<<"Number of Available Holidays: "<<manager_emp.Holidays - manager_emp.Holidays_Taken<<endl;
            break;}
           }

};


int main()
{
    int select;
    unsigned int counter;
    counter = 0;
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
            if(counter >=  500)
                {
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
            break;
        case 2:
            system("cls");
            if(counter == 0)
                {
                    cout<<"No Employee to delete"<<endl;
                    break;
                }
            else{
                int num;
                cout<<"Please enter employee number:"<<endl;
                cin>>num;
                Deggendorf[num].Delete_obj(); //Destructor
                cout<<"Employee ["<<num<<"] have been deleted"<<endl;
                break;
            }
        case 3:{
            if(counter == 0)
                {
                    cout<<"Please Create Employee first"<<endl;
                    break;
                }
            else{
                int num;
                cout<<"Please Enter Employee Number: "<<endl;
                cin>> num;
                Deggendorf[num].Book_Holidays();
                break;}}
        case 4:{
            system("cls");
            if(counter == 0)
                {
                    cout<<"Please Create Employee first"<<endl;
                    break;
                }
            else{
                int num;
            cout<<"Please Enter Employee number:"<<endl;
            cin>>num;
            if((num < 0) || (num > counter)){
                cout <<"Please enter a valid Employee ID!!!"<<endl;
                break;
            }else{
            Deggendorf[select].Show_Data();
            break;}}}
        case 5:{
            system("cls");
            if(counter == 0)
                {
                    cout<<"There are no Employees. Please Create Employee first"<<endl;
                    break;
                }
            else{
            cout<< "\t\tLIST OF EMPLOYEES AND THEIR DATAS\n";
            for(int i = 0; i <= counter; i++){
                cout<< "Employee ["<<i<<"]"<<endl;
                Deggendorf[i].Show_Data();
                cout<< "\n";
            }
            break;}
        case 6:{
            system("cls");
            cout<<"THANK YOU FOR YOUR TIME"<<endl;
            select = 0;
            break;}
        default:
            {
               cout<<"Please enter a valid option!!!"<<endl;
               break;
            }
            }}}while(select!=0);
system("pause");
system("cls");
}

