#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main(){
     string Firstname;
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
  int test1;
  int test2;
  int test3;
  int test4;
   ifstream fileReader("MotorcycleManagement.txt");

	if(fileReader.good())
    {
        //cout<<"working 2";
		while(fileReader >> Customer_No >> Firstname>> Lastname >> MotorCycle_type>> day >>
              month >> year >> Street >> StreetNo >> PLZ >> City >> Phonenumber >> LicenseNo >>
              Status >> test1 >> test2 >> test3 >> test4){
              cout<<"worked";}}
    /*string name;
	float price;
	int quantity;
//	Item *it;

	ifstream fileReader("shoppinglist.txt", ios::out);

	if(fileReader.good())
    {
		while(fileReader >> name >> price
        >> quantity)
    	{  cout<<"working well";
			//it = new Item(name,price,quantity);
        	//list.insert(it);
     	}
    }*/
}
