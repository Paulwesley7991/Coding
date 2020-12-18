#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date{
    friend class Employee;     // friend declaration so that the other class has access to the private elements
    friend class HolidayManagement;
private:
    //Data members of date class
    short day;
    short month;
    unsigned int year;
public:
    void enterDate();  //Member functions of date class
    void showData();
};
void Date::enterDate()
{
    cout << "Day: ";      //enter date function;
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
}

void Date::showData()
{
    cout << day << "." << month << "." << year << endl;    //show date function
}

class Employee
{
    friend class HolidayManagement;  // friend declaration so that the other class has access to the private elements
private:
    string Surname;    //data members of the employee class
    string FirstName;
    string MiddleName;
    Date Dob;              //date declaration
    unsigned int Holidays;
public:
    void GetData();           //declaration of member functions to get data and output data
    void ShowData();
    Employee(){}

};

void Employee::GetData()
{ //get data function for the employee class
    cout << "--Enter Data --" << endl;
    cout << "First name: ";
    cin >> FirstName;
    cout << "Surname: ";
    cin >> Surname;
    cout << "Enter Date of birth:\n";
    Dob.enterDate();
    // Determine current year
    time_t timestamp;
    tm *date;
    timestamp = time(0);
    date = localtime(&timestamp);
    int actYear = date->tm_year+1900;
    if((actYear-Dob.year) >= 50)           //check if employee is over 50 years on current year
        Holidays = 32;                     // assign 32 holidays if greater than 50 on current year
    else
        Holidays = 30;                     //else assign 30 holidays
}
void Employee::ShowData()
{// output data of the employee class
    cout<<"FirstName: "<<FirstName<<endl;
    cout<<"Surname: "<<Surname<<endl;
    cout<<"Date of Birth: ";
    Dob.showData();
}
class HourlyEmployee:public Employee             //declaration of Hourly employee class inheriting from Employee class
{
    private:
      double Hourly_wage;                         // additional data members for the Hourly Employees
      double Hours_worked;
    public:
       void GetData()
       {//definition of get data function for the hourly employee class
           Employee::GetData();     // calling the Employee class get data function
           cout<< "Hourly Wage:";
           cin>> Hourly_wage;                     //receiving additional data from user for the additional data members for the hourly employee class
           cout<< "Hours Worked:";
           cin>> Hours_worked;
       }
       void ShowData()
       {//definition of output data function for the hourly employee class
           Employee::ShowData();      // calling the Employee class output data function
           cout<< "Hourly Wage: "<< Hourly_wage<<endl;                  //output of the additional data of the additional data members for the hourly employee class
           cout<< "Hours Worked: "<< Hours_worked<<endl;
       }
};
class SalariedEmployee: public Employee                 //declaration of salary employee class inheriting from Employee class
{
    private:
      double Annual_Salary;        // additional data member for the Salary Employees
    public:
        void GetData()
       {//definition of get data function for the salary employee class
           Employee::GetData();       // calling the Employee class get data function
           cout<< "Annual Salary:";
           cin>> Annual_Salary;    //receiving additional data from user for the additional data members for the salary employee class
       }
       void ShowData()
       {//definition of output data function for the salary employee class
           Employee::ShowData();   // calling the Employee class output data function
           cout<< "Annual Salary: "<< Annual_Salary<<endl;    //output of the additional data of the additional data members for the salary employee class
       }
};
class Manager: public Employee          //declaration of managerial employee class inheriting from Employee class
{
    private:
        double Profit_sharing;        // declaration of additional data member for the Manager Employees
    public:
        void GetData()
       {//definition of get data function for the salary maanger class
           Employee::GetData();      // calling the Employee class get data function
           cout<< "Profit sharing:";
           cin>> Profit_sharing;    //receiving additional data from user for the additional data members for the manager employee class
       }
       void ShowData()
       {//definition of output data function for the manager employee class
           Employee::ShowData();  // calling the Employee class output data function
           cout<< "Profit sharing: "<< Profit_sharing<<endl;   //output of the additional data of the additional data members for the manager employee class
       }
};

class HolidayManagement        //class declaration and definition for HolidayManagement System
{
   private:                         //declaration of the private data members
   string Employee_type;
   Date Holiday_start;
   Date Holiday_end;
   HourlyEmployee hour_emp;                     //instance of the Hourly Employee class
   SalariedEmployee salary_emp;                 //instance of the Salary Employee class
   Manager manager_emp;                         //instance of the Manager Employee class
   short int choice_type;
   unsigned int Holidays;
   unsigned int Holidays_taken = 0;

   public:                                                  //declaration of the public data members
       HolidayManagement(){}         //default construct
       HolidayManagement(int select){     //constructor overloaded with integer parameter (select) : type of Employee to be created;
    switch(select){
       case 1:{
        HourlyEmployee employee;                //if hourly employee is selected
        employee.GetData();
        hour_emp = employee;
        Holidays = hour_emp.Holidays;
        choice_type = 1;
        break;}

       case 2:{
        SalariedEmployee employee;         //if salary employee is selected
        employee.GetData();
        salary_emp = employee;
        Holidays = salary_emp.Holidays;
        choice_type = 2;
        break;}

       case 3:{
        Manager employee;               //if manager employee is selected
        employee.GetData();
        manager_emp = employee;
        Holidays = manager_emp.Holidays;
        choice_type = 3;}
        }
       }
       ~HolidayManagement(){}   //destructor for class HolidayManagement
       void Delete_obj()
       {
           //HolidayManagement::~HolidayManagement();
       }
       void Book_Holidays()            //Declaration and definition of function that handles the booking of operation system
       {
          unsigned int leap_year = 0;     //variable that holds the number of days for the month of Febuary on leap years or normal year
          leap_year= ((Holiday_start.year%4)?29:28);   //using the ternary operator to assign the value of 28 on normal year and the value of 29 on leap years
          system("cls");
          cout <<"Please enter date of start of Holiday:"<<endl;
          Holiday_start.enterDate();              //User enters date information for the start of holiday.
          cout <<"\nPlease enter date of end of Holiday:"<<endl;
          Holiday_end.enterDate();              //User enters date information for the end of holiday.
          if((Holiday_end.year < Holiday_start.year)||(Holiday_end.year > Holiday_start.year))    // Checks if the user entered start of holiday year is different from the end year
            {
                cout<<"\nPlease Holiday Start and End year must be same!!!"<<endl;
            }
            else{
                    if(Holiday_end.month == Holiday_start.month)      // checks if the holiday starts and end the same month
                {
                         if((Holiday_end.day - Holiday_start.day)> (Holidays-Holidays_taken))    // checks if user entered holiday exceeds number of holidays left
                              {
                                   cout<<"\nYou have exceeded your amount of Holidays left!!!"<<endl;
                              }
                          else{
                                 Holidays_taken += Holiday_end.day - Holiday_start.day;     // adds the number of holiday booked to the total number of holidays taken already by the employee
                                 cout<<"\nHoliday Have being booked"<<endl;
                          }
                }   else if(Holiday_end.month < Holiday_start.month){      //checks if user wrongly inputed end month which is less than start month of holiday
                        cout<<"\nHoliday end month must be greater than start month!!!"<<endl;}
                    else{
                           switch(Holiday_start.month){     //switch between month of January to December depends on the holiday start month
                               case 1:{
                                   if((Holiday_end.month - Holiday_start.month)>2){  //checks if start month is January and end month is more than January by above 2 months
                                    cout<<"\nEntered Holiday exceeds assigned Holidays"<<endl;
                                   }
                                   else if((Holiday_end.month - Holiday_start.month)==2)    //checks if end month is march(if end month is greater than start month with 2 months )
                                   {
                                       if((Holiday_start.day+leap_year+ Holiday_end.day)> (Holidays - Holidays_taken))
                                        {   //checks if Holidays entered is more than Holidays left for current employee
                                          cout<<"\nYou have exceeded your amount of Holidays left!!!"<<endl;
                                       }
                                       else{
                                            Holidays_taken += (31-Holiday_start.day)+leap_year+ Holiday_end.day;   //adds booked Holidays to number of holidays already taken by the current employee;
                                            cout<<"\nHoliday Have being booked"<<endl;
                                       }
                                   }}
                               case 2:{   //case where holiday start month is Febuary
                                if(((leap_year-Holiday_start.day)+Holiday_end.day)>(Holidays - Holidays_taken)){  //checks if user entered Holiday is more than Holidays left for the current employee;
                                    cout<<"\nYou have exceeded your amount of Holidays left!!!"<<endl;
                                }else{
                                    Holidays_taken += (leap_year-Holiday_start.day)+Holiday_end.day;     //adds the booked holiday to number of holidays already taken by current employee
                                    cout<<"\nHoliday Have being booked"<<endl;
                                } break;}
                               case 3:
                               case 5:              //cases where the month after the entered start month of holiday have 30 days  .
                               case 8:
                               case 10:{
                                    if((Holiday_end.month - Holiday_start.month)>2){   //checks if end month of holiday is more than start month by more than 2
                                    cout<<"\nEntered Holiday exceeds assigned Holidays"<<endl;
                                   }
                                   else if((Holiday_end.month - Holiday_start.month)==2)     //checks if end month of holiday is more than start month with exactly 2 months
                                   {
                                      if((Holiday_start.day != 31)&& (Holiday_end.day != 1)){  //Condition can only be passed if the holiday start date is 31st and the end date is 1st of the month 2 months greater than the start month(e.g when the employee have 32 holidays)
                                        cout<<"\nEntered Holiday exceeds assigned Holidays!!!"<<endl;
                                      }else{
                                          Holidays_taken += 32;                            //means user entered a total of 32 days for Holiday to be booked
                                          cout<<"\nHoliday Have being booked"<<endl;
                                      }}
                                   else{
                                    Holidays_taken += (31-Holiday_start.day)+Holiday_end.day;   //This happens if the entered end month is just greater than the start month by just 1
                                    cout<<"\nHoliday Have being booked"<<endl;
                                   }
                                   break;}
                               case 7:{   //special case when the holiday start month is July
                                   if((Holiday_end.month - Holiday_start.month)>=2){       //when the holiday start month is July, no possible way the end month can be 2 months greater
                                    cout<<"\nEntered Holiday exceeds assigned Holidays"<<endl;
                                   }
                                   else{
                                    Holidays_taken += (31-Holiday_start.day)+Holiday_end.day;  //adds booked holidays to total holidays already taken
                                    cout<<"\nHoliday Have being booked"<<endl;
                                   }break;
                               }
                               case 4:
                               case 6:     //cases where the month after the entered start month of holiday is 31 days and holiday start month have 30 days.
                               case 9:
                               case 11: {
                                   if((Holiday_end.month - Holiday_start.month)>=2)  //if the entered start of holiday month have 30 days, no possible way the end month can be 2 months greater
                                    {
                                    cout<<"\nEntered Holiday exceeds assigned Holidays"<<endl;
                                   }
                                   else{
                                    Holidays_taken += (30-Holiday_start.day)+Holiday_end.day;   //adds booked holidays to total holidays already taken
                                    cout<<"\nHoliday Have being booked"<<endl;
                                   }break;
          }}}}}
       void Show_Data()
       {
           switch(choice_type)        //switch between employee type used in creating current holiday management object
           {
           case 1:{
            hour_emp.ShowData();  //calls the hour employee class (show data) function
            cout<<"Employee Type: Hourly Employee"<<endl;
            cout<<"Number of Assigned Holidays: "<<Holidays<<endl;
            cout<<"Number of Available Holidays: "<<hour_emp.Holidays - Holidays_taken<<endl;   //output additional informations
            break;}
           case 2:{
            salary_emp.ShowData();            //calls the salary employee class (show data) function
            cout<<"Employee Type: Salary Employee"<<endl;
            cout<<"Number of Assigned Holidays: "<<Holidays<<endl;
            cout<<"Number of Available Holidays: "<<salary_emp.Holidays - Holidays_taken<<endl;   //output additional informations
            break;}
           case 3:{}
            manager_emp.ShowData();          //calls the manager employee class (show data) function
            cout<<"Employee Type: Manager Employee"<<endl;
            cout<<"Number of Assigned Holidays: "<<Holidays<<endl;
            cout<<"Number of Available Holidays: "<<manager_emp.Holidays - Holidays_taken<<endl;   //output additional informations
            break;}
           }

};


int main()                 //Main program
{
    int select;                //declaration and definition of needed variables
    unsigned int counter;
    counter = 0;
    HolidayManagement Deggendorf[500];
    cout << "WELCOME TO STAFF HOLIDAY MANAGEMENT\n\n" << endl;           //Output of First page
    system("pause");
do{                                                    //do while loop
        system("cls");
        cout << "\t\t--MENU--\n" << endl;
        cout << "[1] Create Employee" << endl;                       //Menu and Options
        cout << "[2] Delete Employee" << endl;
        cout << "[3] Book Holidays" << endl;
        cout << "[4] Search for Employee" << endl;
        cout << "[5] Show All Employees" << endl;
        cout << "[0] Exit" << endl;
        cout << endl << "Please select: ";
        cin >> select;                                 //assign inputed option to variable select
        switch(select)                      //switch between selected options
        {
        case 1:{
            system("cls");
            if(counter >=  500)         // Only 500 employees can be created.
                {
                cout<<"cant create more employee. Maximum Number of Employee reached" <<endl;
                break;
                }
            cout<<"Please select which type of Employee:"<<endl;
            cout << "[1] HourlyEmployee" << endl;
            cout << "[2] SalariedEmployee" << endl;              //User select what type of employee to be created;
            cout << "[3] Manager" << endl;
            cout << endl << "Please select: ";
            cin >> select;                      //assigns user choice to variable select
            Deggendorf[counter] = HolidayManagement(select);            //instance of the HolidayManagement class is created calling the overloaded function
            counter++;            //counts the number of employees created
            cout<<"\nEmployee Created"<<endl;
            system("pause");
            system("cls");
            break;}
        case 2:{
            system("cls");
            if(counter == 0)                         //checks if there is employee
                {
                    cout<<"No Employee to delete"<<endl;
                     system("pause");
                     system("cls");
                    break;
                }
            else{
                int num;
                cout<<"Please enter employee number:"<<endl;
                cin>>num;               //Receives input from user on the employee that is to be deleted
                if((num < 0) || (num > counter)){    //checks if user entered invalid employee number
                cout <<"Please enter a valid Employee ID!!!"<<endl;
                system("pause");
                system("cls");
                break;
            }else{
                Deggendorf[num].~HolidayManagement(); //calls the Destructor of the object to be deleted.
                cout<<"Employee ["<<num<<"] have been deleted"<<endl;
                system("pause");
                system("cls");
                break;
            }}}
        case 3:{
            if(counter == 0)    //checks if there is employee
                {
                    cout<<"Please Create Employee first"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            else{
                int num;
                cout<<"Please Enter Employee Number: "<<endl;
                cin>> num;                   //Receives input from user on the employee that wants to book holiday
                if((num < 0) || (num > counter)){     //checks if user entered invalid employee number
                cout <<"Please enter a valid Employee ID!!!"<<endl;
                system("pause");
                system("cls");
                break;
            }else{
                Deggendorf[num].Book_Holidays();  //calls the Book Holiday function of the employee
                system("pause");
                system("cls");
                break;}}}
        case 4:{
            system("cls");
            if(counter == 0)          //checks if there is employee
                {
                    cout<<"Please Create Employee first"<<endl;
                    system("pause");
                     system("cls");
                    break;
                }
            else{
                int num;
            cout<<"Please Enter Employee number:"<<endl;
            cin>>num;                               //Receives input from user on the employee whose data is to be outputed
            if((num < 0) || (num > counter)){     //checks if user entered invalid employee number
                cout <<"Please enter a valid Employee ID!!!"<<endl;
                system("pause");
                system("cls");
                break;
            }else{
            Deggendorf[num].Show_Data();       //calling the show data function the selected employee
            system("pause");
            system("cls");
            break;
            }}}
        case 5:{
            system("cls");
            if(counter == 0)      //checks if there is employee
                {
                    cout<<"There are no Employees. Please Create Employee first"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            else{
            cout<< "\t\tLIST OF EMPLOYEES AND THEIR DATAS\n";
            for(int i = 0; i < counter; i++){       // for loop that counts all employees and output their data
                cout<< "Employee ["<<i<<"]"<<endl;
                Deggendorf[i].Show_Data();          //calling the show data function of each instance
                cout<< "\n";
            }
           system("pause");
           system("cls");
            break;}
        case 0:{
            system("cls");
            cout<<"THANK YOU FOR YOUR TIME"<<endl;
            select = 0;
            break;}
        default:
            {                                    //When user enter invalid option
               cout<<"Please enter a valid option!!!"<<endl;
               break;
            }
            }}}while(select!=0);     // do while loop condition
system("pause");
system("cls");
}

