#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
class Person
{
 friend class ListOfPeople; // friend declaration so that the other class has access to the private elements
 // Data members
 private:
 string surname;
 string firstname;
 int yearOfBirth;
 Person* Successor; // Concatenation pointer
 // Member functions
 public:
 Person (string n, string f, int y): surname(n), firstname(f), yearOfBirth(y) {}

 string getSurname () const { return surname; }
 string getFirstname () const { return firstname; }
 int getYearOfBirth() const { return yearOfBirth; }

 void calculateAge () {
 // Determine current year
 time_t timestamp;
 tm *date;
 timestamp = time(0);
 date = localtime(&timestamp);
 int actYear = date->tm_year+1900;

 cout << "Age: " << actYear- yearOfBirth<< " years old" << endl;
 }
 Person* next () { return Successor; } // Returns the successor of my current object
 void displayData() {
 cout << "Surname: " << surname << ", First name: " << firstname;
 cout << ", Year of Birth: " << yearOfBirth << endl;
 }
};

class ListOfPeople
{
 private:
 Person* Headpointer;
 Person* tmp;
 public:
 ListOfPeople():Headpointer(0) {};
// Insert head pointer at the beginning of the list
 void insert (Person * kp)
 {
 kp-> Successor = Headpointer; // My successor will be my new beginning
 Headpointer = kp; // and its successor is the new object I have created
 }
 // Remove a person from the beginning of the list
 Person * remove ()
 {
 if (Headpointer!= 0)
 Headpointer = tmp-> Successor;

 return Headpointer;
 }

 // Access to the first person in the list
 Person * begin () { return Headpointer; }

 // Check if list is empty
 bool empty () const { return Headpointer == 0; } // Returns true if head pointer is 0, otherwise false
};

int main ()
{
ListOfPeople list; // Create empty list
char ans = 'y';
string surname="", firstname="";
int yearOfBirth=0;
Person * kp;
// Filling the list
while (ans != 'n')
{
 cout << "Surname: " << endl;
 cin >> surname;
 cout << endl << "First name: " << endl;
 cin >> firstname;
 cout << endl << "Year of birth: " << endl;
 cin >> yearOfBirth;
 kp = new Person(surname, firstname, yearOfBirth);
 list.insert (kp);
 cout << "Go on (y/n)" << endl;
 cin >> ans;
}
// Display list
for (kp=list.begin(); kp != 0; kp = kp->next()) // Start at the beginning of the list; Continue until NULL is reached.
kp->displayData(); // After each loop pass
// my new object is its successor
// Empty list
while (! list.empty ()) // As long as my list is not empty
 list.remove (); // delete every single object (always the head pointer)
system("pause");
return 0;
}
