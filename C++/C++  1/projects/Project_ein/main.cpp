#include <iostream>
#include <cstdlib>
using namespace std;
class ACCOUNT // Definition of the class "ACCOUNT"
{
 private:
     int ACCOUNTBALANCE;
 public:
     bool CHANGE_BALANCE (int);
     int READ_ACCOUNTBALANCE();
};

bool ACCOUNT::CHANGE_BALANCE(int INPUT) // Definition of the member function "CHANGE_BALANCE"
{
if((INPUT>=0)&&(INPUT<=100000)) // The entered value must be between 0 and 100000
{
   ACCOUNTBALANCE=INPUT; // ACCOUNTBALANCE is changed
   return(1); // Change is made
}
   return(0);} // Change failed (e.g. when entering a negative value)

int ACCOUNT::READ_ACCOUNTBALANCE() // Definition of member function "READ_ACCOUNTBALANCE"
{ return(ACCOUNTBALANCE); }

int main() // main program
{
 ACCOUNT TESTACCOUNT; // Definition of TESTACCOUNT
 int AUXILIARY =0, BALANCE =0; // Initialization of variables
 TESTACCOUNT.CHANGE_BALANCE(BALANCE); // Initialization of a the member
 // function CHANCE_BALANCE to 0
 cout << "A C C O U N T M A N A G E M E N T" << endl; // User menu
do // ! do-while loop !
{
cout << "1 = CHANGE ACCOUNT BALANCE\n"; // User makes a selection
cout << "2 = READ ACCOUNT BALANCE\n";
cout << "0 = Exit program" << endl << endl;
cout << "Please select:";
cin >> AUXILIARY; // Keyboard input
 switch(AUXILIARY) // Following functions
{
 case 1: // Entering a new VALUE
cout << "New BALANCE:";
cin >> BALANCE; // Value is read from the keyboard
  if(TESTACCOUNT.CHANGE_BALANCE(BALANCE)) // Calling function and query: 1 (true) or 0 (false)
cout << "BALANCE has been changed." << endl << endl;
  else
cout << " BALANCE has not been changed." << endl << endl;
  break;

case 2: // Query of the current BALANCE
cout << "Actual BALANCE:";
 cout << TESTACCOUNT. READ_ACCOUNTBALANCE () << endl << endl;
break;
}
 } while(AUXILIARY); // As long as AUXILIARY is required!
 system("pause");
} // End of the program!
