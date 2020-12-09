#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class ACCOUNT // Definition of the class "ACCOUNT"
{
 private:
     int ACCOUNTBALANCE;
 public:
     ACCOUNT(string);
     ~ ACCOUNT();
     string NAME;
     string ADDRESS;
     int PHONENUMBER;
     int ACCOUNTNUMBER;
     bool CHANGE_BALANCE (int);
     int READ_ACCOUNTBALANCE();
     bool WITHDRAWMONEY(float);
};

ACCOUNT::ACCOUNT(string Name):ACCOUNTBALANCE(100),NAME(Name)
{
cout<<"Account Created\n\n"<<endl;}

ACCOUNT::~ACCOUNT(){
cout<<"Account Deleted"<<endl;}

bool ACCOUNT::CHANGE_BALANCE(int INPUT) // Definition of the member function "CHANGE_BALANCE"
{
if((INPUT>=0)&&(INPUT<=100000)) // The entered value must be between 0 and 100000
{
   ACCOUNTBALANCE=INPUT; // ACCOUNTBALANCE is changed
   return(1); // Change is made
}
   return(0);} // Change failed (e.g. when entering a negative value)

bool ACCOUNT::WITHDRAWMONEY(float AMOUNT){
   if(AMOUNT > ACCOUNTBALANCE){
      cout<<"Not of enough money, go and work or pray!!!(Smiley)"<<endl;
      return (0);}
   else if(AMOUNT <0){
      cout<<"Please enter a positive amount to be withdrawn"<<endl;
      return (0);}
   else if(AMOUNT == 0){
      cout<< " The amount 0 cannot be withdrawn, Please enter an amount that can be withdrawn"<<endl;
      return (0);
      }
    else
    {
        ACCOUNTBALANCE = ACCOUNTBALANCE - AMOUNT;
        return (1);
    }

   }

int ACCOUNT::READ_ACCOUNTBALANCE() // Definition of member function "READ_ACCOUNTBALANCE"
{ return(ACCOUNTBALANCE); }

int main() // main program
{
 ACCOUNT TESTACCOUNT("WESLEY"); // Definition of TESTACCOUNT
 float WITHDRAWAMOUNT; // Declaration of Withdrawal amount
 int AUXILIARY =0, BALANCE =0; // Initialization of variables
 TESTACCOUNT.CHANGE_BALANCE(BALANCE); // Initialization of a the member
 // function CHANGE_BALANCE to 0
 cout << "A C C O U N T M A N A G E M E N T" << endl; // User menu
do // ! do-while loop !
{
cout << "1 = CHANGE ACCOUNT BALANCE\n"; // User makes a selection
cout << "2 = READ ACCOUNT BALANCE\n";
cout << "3 = WITHDRAW MONEY\n";
cout << "0 = Exit program" << endl << endl;
cout << "Please select:";
cin >> AUXILIARY; // Keyboard input
 switch(AUXILIARY) // Following functions
{
case 0:
    continue;
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

case 3:
    cout << "Please enter the amount you would like to withdraw"<<endl;
    cin >> WITHDRAWAMOUNT;
    if(TESTACCOUNT.WITHDRAWMONEY(WITHDRAWAMOUNT))
        cout << "Thank you for Banking with us. Merry Christmas!!!" << endl;
    break;
default:
    cout<< "Please enter a valid option. Thanks!!!"<<endl;
    break;
}
 } while(AUXILIARY); // As long as AUXILIARY is required!
 system("pause");
} // End of the program!
