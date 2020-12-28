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
    string FirstName;
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
        Reservations Successor;
        string Status;          // Concatenation pointer
    public:
        Reservations(){}
        Reservations(unsigned int Customer_No , string Firstname. string Lastname ,
                     string MotorCycle_type, unsigned int day , unsigned int month ,
                     unsigned int year , string Street , string StreetNo , unsigned int PLZ ,
                     string City , string Phonenumber , string LicenseNo , string Status)
                     {
                         this->CUSTOMER.FirstName =Firstname;
                         this->CUSTOMER.Lastname  = Lastname;
                         this->CUSTOMER.PhoneNumber = Phonenumber;
                         this->CUSTOMER.LicenseNo  = LicenseNo;
                         this->CUSTOMER.Street  = Street;
                         this->CUSTOMER.City   = City;
                         this->CUSTOMER.StreetNo = StreetNo;
                         this->Status = Status;
                         this->MotorCycle_Type = MotorCycle_type;
                         this->CUSTOMER.Dob.day = day;
                         this->CUSTOMER.Dob.month = month;
                         this->CUSTOMER.Dob.year = year;
                         this->CUSTOMER.PLZ = PLZ;
                         this->CUSTOMER.Customer_NO = Customer_No;
                     }
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

void list_initialize(int*); // Fills the list with the values from the file
void Make_Reservation(int, string); // Add item
void Display(int); // Displays all items and price
void Delete(int); // Delete reservation
void empty();  // Empty shopping reservation list
void Return(); //Return MotorCycle

int main()
{
    string insert;
	int selection = 1;
	Reservations *tmpObject = NULL;
	ofstream fileWriter;
	string MotorCycle_List[] = {"Suzuki Bandit","Honda TransAlp","BMW F 650 GS","Kawasaki ZZR1400"};
	int Available_MotorCycle[] = {1,1,1,1};

	list_initialize(Available_MotorCycle);
    cout << "\n\t\tWELCOME TO MOTORCYCLE MANAGEMENT\n\n" << endl;           //Output of First page
	do
    {
    	system("cls");
        cout << "\t***** SELECT OPTION ******\n" << endl;
        cout << "[1]. MotorCycle Reservation" << endl;
        cout << "[2]. Return MotorCycle"
        cout << "[3]. Display available MotorCycle" << endl;
        cout << "[4]. Search for MotorCycle Reservations" << endl;
        cout << "[5]. Display MotorCycle Reservations list" << endl;
        cout << "[6]. Empty MotorCycle Reservation list." << endl;
        cout << "[0]. Exit program" << endl;
        cout << "Your selection: ";
        cin >> selection;
        cout << endl;

        try
        {
	        switch (selection)
	        {
	            case 0: {// End
	            	fileWriter.open("MotorcycleManagement.txt");
	            	if(fileWriter.good())
	            	{
						for (tmpObject=list.begin(); tmpObject != 0; tmpObject = tmpObject->next())
                            {
							fileWriter << tmpObject->CUSTOMER.Customer_NO << "\t" << tmpObject->CUSTOMER.firstName << "\t"
                            << tmpObject->CUSTOMER.Surname<<"\t" << tmpObject->MotorCycle_Type <<"\t" << tmpObject->CUSTOMER.Dob.day<<"\t"
                            << tmpObject->CUSTOMER.Dob.month"\t" << tmpObject->CUSTOMER.Dob.year<<"\t" << tmpObject->CUSTOMER.Street
							<<"\t" << tmpObject->CUSTOMER.StreetNo<<"\t" << tmpObject->CUSTOMER.PLZ<<"\t" << tmpObject->CUSTOMER.City<<"\t"
							<< tmpObject->CUSTOMER.PhoneNumber <<"\t" << tmpObject->CUSTOMER.LicenseNo<<"\t" << tmpObject->Status
							<<Available_MotorCycle[0]<<"\t"<<Available_MotorCycle[1]<<"\t"<<Available_MotorCycle[2]<<"\t"<<Available_MotorCycle[3]<<endl;
						}
						if(list.begin()!=0)
							cout << "List saved to file MotorcycleManagement.txt!" << endl;
							cout << "\n\nTHANK YOU FOR YOUR TIME" <<endl;
					}
					else
						cout << "File MotorcycleManagement.txt cannot be opened. Old list remains." << endl;
                    cout << "Goodbye!" << endl;
	                break;
	                }
	                case 1:{
	                    if(Available_MotorCycle[0] == 0 && Available_MotorCycle[1] == 0
                           && Available_MotorCycle[2] == 0 && Available_MotorCycle[3] == 0){
                            cout<< "No Available MotorCycle, all have being Reserved"<<endl;
                            system("pause");
                            break;
                           }
                           else{
	                    int select;
	                    system("cls");
	                    cout << "\t\tPlease select MotorCycle type:"<< endl;
                        for(int i = 0; i<4; i++)
                            {
                                if(Available_MotorCycle[i] == 0)
                                continue;
                                else{
                                    cout<<"["<< i << "] "<< MotorCycle_List[i]<< endl;
                                    }
                            }
                        cout<<"Please Enter:";
	                    cin >> select;
                        Make_Reservation(select, MotorCycle_List);
                        system("pause");
                        system("cls");
                        break;
	                    }}
                    case 2:{
                        if(list.begin()!=0)
	            	{
                        system("cls");
                        Return();
                    }else
						cout << "List is empty." << endl;
                    system("pause");
					break;
                    }
                    case 3:{
                        if(list.begin()!=0)
	            	{  int counter = 1;
                        system("cls");
                        cout<< "\t\tLIST AVAILABLE MOTORCYCLE FOR RESERVATION"<< endl;
                        for(int i = 0; i<4; i++)
                            {
                                if(Available_MotorCycle[i] == 0)
                                continue;
                                else{
                                    cout<<"["<< counter<< "] "<< MotorCycle_List[i]<< endl;
                                    counter ++;
                                }
                            }
                            system("pause");
                            break;
                    }else
						cout << "List is empty." << endl;
                    system("pause");
					break;
                    }
                    case 4:{
                        if(list.begin()!=0)
	            	{
                        system("cls");
                        Display(1);
                    }else
						cout << "List is empty." << endl;
                    system("pause");
					break;
                    }
                    case 5:{
                        if(list.begin()!=0)
	            	{
                        system("cls");
                        Display(2);
                    }else
						cout << "List is empty." << endl;
					system("pause");
					break;
                    }
                    case 6:{
                        if(list.begin()!=0)
	            	{
                        system("cls");
                        Delete(2);
	            	}else
						cout << "List is empty." << endl;
					system("pause");
					break;
                    }
                    default:{
                    cerr << "Incorrect input" << endl;
	            	system("pause");
	                break;
                    }
	        }
        }
        catch(string msg)
		{
			cout << msg << " cannot be negative or null!" << endl << "Transaction canceled." << endl;
			system("pause");
		}
    } while (selection != 0);
    system("pause");
	return 0;
	system("pause");
}

void list_initialize(int *array)
{ string Firstname;
  string Lastname;
  string Phonenumber;
  string LicenseNo;
  string Street;
  string City;
  string StreetNo;
  string Status;
  string MotorCycle_type;
  unsigned int day;
  unsigned int month;
  unsigned int year;
  unsigned int PLZ;
  unsigned int Customer_No;

    ifstream fileReader("MotorcycleManagement.txt", ios::out);

	if(fileReader.good())
    {
		while(fileReader >> Customer_No >> Firstname>> Lastname >> MotorCycle_type>> day >>
              month >> year >> Street >> StreetNo >> PLZ >> City >> Phonenumber >> LicenseNo >>
              Status >> array[0] >> array[1] >> array[2] >> array[3])
    	{
		Reservations *reserve = new Reservations( Customer_No , Firstname, Lastname , MotorCycle_type , day ,
              month , year , Street ,StreetNo , PLZ , City , Phonenumber , LicenseNo , Status);
        	list.insert(reserve);
     	}
    }

    fileReader.close();
}
void Make_Reservation(int select, string MotorCycle_List[])
{
  Reservations *reserve = new Reservations();
  cin>> reserve;
  list.insert(reserve);
		cout << "\n\nRESERVATION HAVE BEING MADE" << endl;
}
void Display(int num)
{
    switch(num)
    {
        case 1:
            {   int num;
                cout<< "\tList of Names of Customers" <<endl;
                Reservations object;
                for (object=list.begin(); object != 0; object = object->next())
	                  cout<< "["<<object->CUSTOMER.Customer_NO<<"] "<< object->CUSTOMER.FirstName <<" "<< object->CUSTOMER.Surname<<endl;
                cout<< "Please enter Customer Number:" <<endl;
                cin >> num;
                if(num <=0)
			       throw (string)"Customer Number";
                Reservations *tmpReserve = NULL;
	            tmpReserve = list.find(num);
                cout << tmpReserve;
                break;
            }
        case 2:
            {
                Reservations object;
                int no = 1;
                for (object=list.begin(); object != 0; object = object->next())
	                  {
		                  cout << "\t\t***** RESERVATION [" << no << "] *****\t";
                          cout<< object;
                          no++;
                      }
             }
    }
}
void Delete(int num)
{
    switch(num)
    {  case 1: {
        int num;
        string choice;
        cout<< "\tList of Names of Customers" <<endl;
        Reservations object;
        for (object=list.begin(); object != 0; object = object->next())
             cout<< "["<<object->CUSTOMER.Customer_NO<<"] "<< object->CUSTOMER.FirstName <<" "<< object->CUSTOMER.Surname<<endl;
        cout<< "Please enter Customer Number:" <<endl;
        cin >> num;
        if(num <=0)
           throw (string)"Customer Number";
        cout<< "Are you sure you want to Cancel Reservation for this Customer?? (Yes/No)"<<endl;
        cin >> choice;
        if(choice == "Yes"){
        list.remove(num);
	    cout << "Reservation has been Canceled and deleted." << endl;
	    break;}
	    break;
   }
    case 2:
        {
            while(!list.empty())
		    list.clear();
            cout << endl << "Reservation List have been cleared" << endl;
            break;
        }
    }
}

