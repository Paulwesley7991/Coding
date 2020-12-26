#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date{
    friend class Customer;     // friend declaration so that the other class has access to the private elements
    friend class Reservations;
    friend class ListOfReservations;
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

class Customer
{
  private:
    string firstName;
    string Surname;
    string Street;
    string StreetNo;
    string City;
    string PhoneNumber;
    string LicenseNo;
    unsigned int PLZ;
    Date Dob;
  public:
    void GetData();           //declaration of member functions to get data and output data
    void ShowData();
    Customer(){}
    };

    void Customer::GetData()
{ //get data function for the employee class
    cout << "--Enter Data --" << endl;
    cout << "First name: ";
    cin >> FirstName;
    cout << "Surname: ";
    cin >> Surname;
    cout << "Enter Date of birth:\n";
    Dob.enterDate();
    cout << "Street: ";
    cin >> Street;
    cout << "Street No: "
    cin >> StreetNo;
    cout << "City: "
    cin >> City;
    cout << "Postal Code: "
    cin >> PLZ;
    cout << "Please enter your Driving License Number: ";
    cin >> LicenseNo;
}

void Customer::ShowData()
{// output data of the employee class
    cout<<"FirstName: "<<FirstName<<endl;
    cout<<"Surname: "<<Surname<<endl;
    cout<<"Date of Birth: ";
    Dob.showData();
    cout<<"Address: "<<Street<<" "<<StreetNo;
    cout<<"City: "<<City;
    cout<<"Postal Code: "<<PLZ;
    cout<<"Phone Number: "<<PhoneNumber;
    cout<<"License Number: "<<LicenseNo;
}

class Reservations
{
    friend class ListOfReservations;
    private:
        Customer CUSTOMER;
        string MotorCycle_Type;
    public:



};
class ListOfReservations
{
};

    // Determine current year
