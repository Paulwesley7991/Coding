#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Date{
    friend class Customer;     // friend declaration so that the other class has access to the private elements
    friend class Reservations;
    friend class ListOfReservations;

private:
    //Private Data members of date class
    short day;
    short month;
    unsigned int year;
public:  //Member Function of date class
    short Get_day(){return day;}
    short Get_month(){return month;}
    unsigned int Get_year(){return year;}
    void Set_day(short day){this-> day = day;}
    void Set_month(short month){this-> month = month;}
    void Set_year(unsigned int year){this-> year = year;}
};

class Customer
{ // friend declaration so that the other class has access to the private elements
    friend class Reservations;
    friend class ListOfReservations;
  private:
       //Private Data members of Customer Class
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
      //Member Function of Customer class
    Customer(){}
    void Set_CustomerNo(int number){Customer_NO = number;}
    void Set_PLZ(unsigned PLZ){this-> PLZ = PLZ;}
    void Set_FirstName(string FirstName){this -> FirstName = FirstName;}
    void Set_Surname(string Surname){this -> Surname = Surname;}                         //Setter Functions
    void Set_Street(string Street){this -> Street = Street;}
    void Set_StreetNo(string StreetNo){this -> StreetNo = StreetNo;}
    void Set_City(string City){this -> City = City;}
    void Set_PhoneNumber(string PhoneNumber){this -> PhoneNumber = PhoneNumber;}
    void Set_LicenseNo(string LicenseNo){this -> LicenseNo = LicenseNo;}
    void Set_Dob(short day, short month, unsigned int year){
        Dob.Set_day(day);
        Dob.Set_month(month);
        Dob.Set_year(year);
    }

    unsigned Get_Customer_NO(){return Customer_NO;}
    unsigned int Get_PLZ(){return PLZ;}
    string Get_FirstName(){return FirstName;}
    string Get_Surname(){return Surname;}                         //Getter Function
    string Get_Street(){return Street;}
    string Get_StreetNo(){return StreetNo;}
    string Get_City(){return City;}
    string Get_PhoneNumber(){return PhoneNumber;}
    string Get_LicenseNo(){return LicenseNo;}
    Date Get_Dob(){return Dob;}
    friend istream& operator>> (istream& is, Customer& a);
    friend ostream& operator<< (ostream& os, Customer& a);
    };

class Reservations
{ // friend declaration so that the other class has access to the private elements
    friend class ListOfReservations;
    friend class Customer;
    friend class Date;
    private:
        string MotorCycle_Type;
        Reservations* Successor;   // Concatenation pointer
        string Status;
    public:
        Customer CUSTOMER;
        Reservations(){}     //Reservation Class default Constructor
        //Constructor Overloading
        Reservations(unsigned int Customer_No , string Firstname, string Lastname ,
                     string MotorCycle_type, unsigned int day , unsigned int month ,
                     unsigned int year , string Street , string StreetNo , unsigned int PLZ ,
                     string City , string Phonenumber , string LicenseNo , string Status)
                     {
                         CUSTOMER.Set_FirstName(Firstname);
                         CUSTOMER.Set_Surname(Lastname);
                         CUSTOMER.Set_PhoneNumber(Phonenumber);
                         CUSTOMER.Set_LicenseNo(LicenseNo);
                         CUSTOMER.Set_Street(Street);
                         CUSTOMER.Set_City(City);
                         CUSTOMER.Set_StreetNo(StreetNo);
                         Set_Status(Status);
                         Set_MotorCycle_Type(MotorCycle_type);
                         CUSTOMER.Set_Dob(day,month,year);
                         CUSTOMER.Set_PLZ(PLZ);
                         CUSTOMER.Set_CustomerNo(Customer_No);
                     }
        Reservations* next () { return Successor; } // Returns the successor of my current object
        Customer Get_Customer(){return CUSTOMER;}
        string Get_MotorCycle_Type(){return MotorCycle_Type;}
        string Get_Status(){return Status;}
        void Set_MotorCycle_Type(string MotorCycle_Type){this->MotorCycle_Type = MotorCycle_Type;}
        void Set_Status(string Status){this->Status = Status;}
};

class ListOfReservations
{
   private:
      Reservations* Headpointer;      //Declaration of the Head pointer of the list
   public:
      ListOfReservations():Headpointer(0){}
      //insert Member Function for adding new reservations
      void insert(Reservations * kp)
    {
     kp-> Successor = Headpointer; // My successor will be my new beginning
     Headpointer = kp; // and its successor is the new object I have created
    }
    //Find Member Function for searching for Reservations
    Reservations* find(int reserve)
    {
        Reservations* kp;
		for (kp = begin(); kp != 0; kp = kp->next())
			if (kp->CUSTOMER.Customer_NO  == reserve)
				break;
		return kp;
    }
     // Remove a Reservation from the beginning of the list
    void remove(int reserve)
    {
     if(Headpointer!=NULL)
		{
			if(Headpointer->CUSTOMER.Customer_NO == reserve) //check if the beginning is our dataset, as we may not have a successor

			{
				Headpointer = Headpointer->next(); //if yes, then our new beginning is the successor
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
					if(kp->next()->CUSTOMER.Customer_NO != reserve && kp->next()->next() == NULL) //check if the successor dataset is not equal to my dataset and if the successor of the successor is equal to NUL
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

istream& operator>> (istream& is, Customer& a) {
  //Operator Overloading of the input >>
  string String_input;
  unsigned int int_input;
  short day, month;

  cout << "--Enter Data --" << endl;
    cout << "First name: ";
    is >> String_input;
    a.Set_FirstName(String_input);
    cout << "Surname: ";
    is >> String_input;
    a.Set_Surname(String_input);
    //enter date datas
    cout << "Enter Date of birth:\n";
    cout << "Day: ";
    is >> day;
    cout << "Month: ";
    is >> month;
    cout << "Year: ";
    is >> int_input;
    a.Set_Dob(day,month,int_input);
    cout << "Street: ";
    is >> String_input;
    a.Set_Street(String_input);
    cout << "Street No: ";
    is >> String_input;
    a.Set_StreetNo(String_input);
    cout << "City: ";
    is >> String_input;
    a.Set_City(String_input);
    cout << "Postal Code: ";
    is >> int_input;
    a.Set_PLZ(int_input);
    cout << "Please enter Mobile Number: ";
    is >> String_input;
    a.Set_PhoneNumber(String_input);
    cout << "Please enter your Driving License Number: ";
    is >> String_input;
    a.Set_LicenseNo(String_input);
 return is;
}
// Output
ostream& operator<< (ostream& os,  Customer& a) {
 //output data of the reservation class
    os<<"CUSTOMER NUMBER: "<<a.Get_Customer_NO()<<endl;
    os<<"FirstName: "<<a.Get_FirstName()<<endl;
    os<<"Surname: "<<a.Get_Surname()<<endl;
    os<<"Date of Birth: "<<a.Get_Dob().Get_day()<<"."<<a.Get_Dob().Get_month()<<"."<<a.Get_Dob().Get_year()<<endl;
    os<<"Address: "<<a.Get_Street()<<" "<<a.Get_StreetNo() <<endl;
    os<<"City: "<<a.Get_City()<<endl;
    os<<"Postal Code: "<<a.Get_PLZ()<<endl;
    os<<"Phone Number: "<<a.Get_PhoneNumber()<<endl;
    os<<"License Number: "<<a.Get_LicenseNo()<<endl;
 return os;
}
ListOfReservations list;

int list_initialize(int[]); // Fills the list with the values from the file
void Make_Reservation(int, int*, string[]); // Make a Reservation
void Display(int); // Displays Reservations or Customer
void Delete(int, int*, string *); // Delete reservation
void empty();  // Empty reservation list


int main()  //Main Program
{       //Declaration and initialization of Variables
    string insert;
	int selection = 1;
	int counter = 0;
	string s;
	Reservations *tmpObject = NULL;
	ofstream fileWriter;
	string MotorCycle_List[] = {"Suzuki_Bandit","Honda_TransAlp","BMW_F_650_GS","Kawasaki_ZZR1400"};   //list of MotorCycle
	int Available_MotorCycle[] = {1,1,1,1};   //list of Available MotorCycle

	counter = list_initialize(Available_MotorCycle);    //Initialize the List with saved file and return counter
    cout << "\t\tWELCOME TO MOTORCYCLE MANAGEMENT\n\n" << endl;           //Output of First page
    system("pause");
	do
    {
    	system("cls");
        cout << "\t***** SELECT OPTION ******\n" << endl;
        cout << "[1]. MotorCycle Reservation" << endl;
        cout << "[2]. Return MotorCycle"<<endl;
        cout << "[3]. Display available MotorCycle" << endl;
        cout << "[4]. Search for MotorCycle Reservations" << endl;
        cout << "[5]. Display MotorCycle Reservations list" << endl;
        cout << "[6]. Empty MotorCycle Reservation list." << endl;
        cout << "[0]. Exit program" << endl;
        cout << "Your selection: ";
        cin >> selection;
        cout << endl;

        try             //try statement
        {
	        switch (selection)  //Switch Statement between options
	        {
	            case 0: {// End
	            	fileWriter.open("MotorcycleManagement.txt");
	            	if(fileWriter.good())
	            	{//Data are written into the "MotorcycleManagement.txt" file
						for (tmpObject=list.begin(); tmpObject != 0; tmpObject = tmpObject->next())
                            {
							fileWriter << tmpObject->CUSTOMER.Get_Customer_NO() << "\t" << tmpObject->CUSTOMER.Get_FirstName() << "\t"
                            << tmpObject->CUSTOMER.Get_Surname()<<"\t" << tmpObject->Get_MotorCycle_Type() <<"\t" << tmpObject->CUSTOMER.Get_Dob().Get_day()<<"\t"
                            << tmpObject->CUSTOMER.Get_Dob().Get_month()<<"\t" << tmpObject->CUSTOMER.Get_Dob().Get_year()<<"\t" << tmpObject->CUSTOMER.Get_Street()
							<<"\t" << tmpObject->CUSTOMER.Get_StreetNo()<<"\t" << tmpObject->CUSTOMER.Get_PLZ()<<"\t" << tmpObject->CUSTOMER.Get_City()<<"\t"
							<< tmpObject->CUSTOMER.Get_PhoneNumber() <<"\t" << tmpObject->CUSTOMER.Get_LicenseNo()<<"\t" << tmpObject->Get_Status()<<"\t"
							<<Available_MotorCycle[0]<<"\t"<<Available_MotorCycle[1]<<"\t"<<Available_MotorCycle[2]<<"\t"<<Available_MotorCycle[3]<<endl;
						}
						if(list.begin()!=0)
							cout << "List saved to file MotorcycleManagement.txt!" << endl;{
                            cout << "\n\nTHANK YOU FOR YOUR TIME" <<endl;}
					}
					else
						cout << "File MotorcycleManagement.txt cannot be opened. Old list remains." << endl;
                    cout << "Goodbye!" << endl;
	                break;
	                }
	                case 1:{
	                    if(Available_MotorCycle[0] == 0 && Available_MotorCycle[1] == 0      //If All MotorCycle Have being built
                           && Available_MotorCycle[2] == 0 && Available_MotorCycle[3] == 0){
                            cout<< "No Available MotorCycle, all have being Reserved"<<endl;
                            system("pause");
                            break;
                           }
                        else{
                            cout<<"Do you have a valid Drivers license? (Yes/No)"<<endl;
	                        cin>> s;
	                        if(s == "Yes"){
                            system("cls"); //Displays Available MotorCycle
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
                            Make_Reservation(select, &counter ,MotorCycle_List);  //calling the make reservation function
                            Available_MotorCycle[select] = 0;
                            system("pause");
                            system("cls");
                            break;
                }else{
                    cout<<"You need to have a valid Driver License to Make a Reservation!!!"<<endl;
                        system("pause");
                        system("cls");
                        break;
	                    }
	                    }}
                    case 2:{
                        if(list.begin()!=0)
	            	{
                        system("cls");
                        Delete(1,Available_MotorCycle,MotorCycle_List);
                    }else
						cout << "List is empty." << endl;
                    system("pause");
					break;
                    }
                    case 3:
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
                        Delete(2,Available_MotorCycle,MotorCycle_List);
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
			cout << msg << " Is Invalid" << endl << "Operation canceled." << endl;
			system("pause");
		}
    } while (selection != 0);
    system("pause");
	return 0;
	system("pause");
}
//Program Initializer function
int list_initialize(int *arr)
{ string Firstname;
  string Lastname;
  string Phonenumber;
  string LicenseNo;
  string Street;
  string City;
  string StreetNo;
  string Status;
  string MotorCycle_type;
  short day;
  short month;
  unsigned int year;
  unsigned int PLZ;
  unsigned int Customer_No;
  int counter =0;

//Reading contents of file "MotorcycleManagement.txt"
    ifstream fileReader("MotorcycleManagement.txt", ios::in);

	if(fileReader.good())
    {
		while(fileReader >> Customer_No >> Firstname>> Lastname >> MotorCycle_type>> day >>
              month >> year >> Street >> StreetNo >> PLZ >> City >> Phonenumber >> LicenseNo >>
              Status >> arr[0] >> arr[1] >> arr[2] >> arr[3])
    	{
		Reservations *reserve = new Reservations( Customer_No , Firstname, Lastname , MotorCycle_type , day ,
              month , year , Street ,StreetNo , PLZ , City , Phonenumber , LicenseNo , Status);
        	list.insert(reserve);
        	counter ++;
     	}
    }

    fileReader.close();
    return counter;
}

void Make_Reservation(int select, int *counter, string MotorCycle_List[])
{
  Reservations *object = new Reservations(); //Create new object with newly assigned address
  cin>> object->CUSTOMER;
  list.insert(object);
		cout << "\n\nRESERVATION HAVE BEING MADE" << endl;
		object->CUSTOMER .Set_CustomerNo(++(*counter));
		object->Set_MotorCycle_Type(MotorCycle_List[select]);
		object->Set_Status("Reserved");
}
void Display(int num)               //Display Function
{
    switch(num)
    {
        case 1:
            {   int num;
                cout<< "\tList of Names of Customers" <<endl;
                Reservations* object;
                for (object=list.begin(); object != 0; object = object->next())
	                  cout<< "["<<object->CUSTOMER.Get_Customer_NO()<<"] "<< object->CUSTOMER.Get_FirstName() <<" "<< object->CUSTOMER.Get_Surname()<<endl;
                cout<< "Please enter Customer Number:" <<endl;
                cin >> num;
                if(num <=0)
			       throw (string)"Customer Number";
                Reservations *tmpReserve = NULL;
	            tmpReserve = list.find(num);
	            cout<<"\t\t**** RESERVATION FOR "<< tmpReserve->Get_MotorCycle_Type()<<" *****" <<endl;
                cout << tmpReserve->CUSTOMER;
                cout<<"Status of Reservation: "<<tmpReserve->Get_Status()<<endl;
                break;
            }
        case 2:
            {
                Reservations* object;
                int no = 1;
                for (object=list.begin(); object != 0; object = object->next())
	                  {
		                  cout << "\t\t RESERVATION [" << no << "]";
		                  cout<<"\t\t**** RESERVATION FOR "<< object->Get_MotorCycle_Type()<<" *****" <<endl;
                          cout<< object->CUSTOMER;
                          cout<<"Status of Reservation: "<<object->Get_Status()<<endl;
                          no++;
                      }
             }
    }
}
void Delete(int num, int *arr, string *arr2)      //Delete Function
{
    switch(num)
    {  case 1: {
        int num;
        string choice;
        cout<< "\tList of Names of Customers" <<endl;
        Reservations* object;
        for (object=list.begin(); object != 0; object = object->next())
             cout<< "["<<object->CUSTOMER.Get_Customer_NO()<<"] "<< object->CUSTOMER.Get_FirstName() <<" "<< object->CUSTOMER.Get_Surname()<<endl;
        cout<< "Please enter Customer Number:" <<endl;
        cin >> num;
        if(num <=0)
           throw (string)"Customer Number";
        cout<< "!!!By returning this MotorCycle, your reservation would be canceled!!!\nAre you sure you want to Cancel Reservation for this Customer?? (Yes/No)"<<endl;
        cin >> choice;
        if(choice == "Yes"){
        Reservations *tmpReserve = NULL;
        tmpReserve = list.find(num);
        string s = tmpReserve->Get_MotorCycle_Type();
        for(int i = 0; i<4; i++)
            {
                if(s == arr2[i]){
                    arr[i] = 1;
                    break;
                }
            }
        list.remove(num);
	    cout << "MotorCycle Successfully Returned. Reservation has been Canceled and deleted." << endl;
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

