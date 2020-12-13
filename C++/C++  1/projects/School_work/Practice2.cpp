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
