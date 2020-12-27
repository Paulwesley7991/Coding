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
    unsigned int Customer_NO;
    unsigned int PLZ;
    Date Dob;
  public:
    void GetData();           //declaration of member functions to get data and output data
    void ShowData();
    void SetCustomerNo(int number)
    {
        Customer_NO = number;
    }
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
        Reservations Successor;              // Concatenation pointer
    public:
        Reservations* next () { return Successor; } // Returns the successor of my current object

};
class ListOfReservations
{
   private:
      Reservations* Headpointer;
   public:
      ListOfReservations()Headpointer(0){}
      void insert(Reservations * kp)
    {
     kp-> Successor = Headpointer; // My successor will be my new beginning
     Headpointer = kp; // and its successor is the new object I have created
    }
    Reservations* find(int reserve)
    {
        Reservations* kp;
		for (kp = begin(); kp != 0; kp = kp->next())
			if (kp->CUSTOMER.Customer_NO  == reserve)
				break;
		return kp;
    }
     // Remove a person from the beginning of the list
    Reservations* remove(int reserve)
    {
     if(Headpointer!=NULL)
		{
			if(Headpointer->CUSTOMER.Customer_NO == reserve) //check if the beginning is our dataset, as we may not have a successor

			{
				Headpointer = Headpointer->next(); //falls ja, dann ist unser neuer Anfang der Nachfolger
			}
			else if(Headpointer->CUSTOMER.Customer_NO != reserve && Headpointer->next() == NULL) //check if start is not equal to dataset and if next dataset is NULL
			{
				return;
			}
			else
			{
				Reservations* kp;
				for (kp = begin(); kp != 0; kp = kp->next())
				{
					if(kp->next()->CUSTOMER.Customer_No != reserve && kp->next()->next() == NULL) //check if the successor dataset is not equal to my dataset and if the successor of the successor is equal to NUL
						break;														  //is needed if we are at the second to last dataset & last data is not equal, because last does not provide any data
					else if (kp->next()->CUSTOMER.Customer_NO == reserve) //check if successor is our dataset
					{
						kp->Successor = kp->next()->next(); //If yes, then our new successor is the successor of the successor of the current object.
						break;
					}
				}
			}
		}
 }
     // Access to the first person in the list
     Reservations* begin () { return Headpointer; }
     Reservations *clear()
	{
    // Remove a node from the beginning of the list
        Reservations * kp = Headpointer;
        if (kp != 0)
        {
        	cout << kp->CUSTOMER.Customer_NO << " deleted." << endl;
            Headpointer = kp->Successor;
            kp->Successor = 0;
        }
        return kp;
	}

      // Check if list is empty

      bool empty () const { return Headpointer == 0; } // Returns true if head pointer is 0, otherwise false
};

ListOfReservations list;

void list_initialize(); // Fills the list with the values from the file
void Make_Reservation(); // Add item
void modify(); // Modify item
void display(); // Displays all items and price
void remove(); // Delete item
void empty(); // Empty shopping list

int main()
{

}

    // Determine current year
