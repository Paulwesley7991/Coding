#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
{
 ofstream writingFile("employee.txt");
 ifstream readingFile("employee.txt");
 cout << "Employee no, name, salary" << endl;
 int no;
 string name;
 double salary;
 bool next;
 do
 {
 cin >> no >> name >> salary; //Input No, Name, Salary, separated by spaces
 writingFile << no << ' ' << name << ' ' << salary << endl; // User-defined output with the values
// Save in employee.txt file
 cout << "NEXT? [1] YES [0] NO: ";
 cin >> next;
 }while(next == 1); // Enter data as long as next equals 1
 writingFile.close(); // Closing file
 cout << endl << "--- READING ---" << endl;
 while(readingFile >> no >> name >> salary) // Reading from employee.txt file
 { // Assign each column value of a line to the variable.
 cout << no << ", " << name << ", " << salary << endl; // Output of the individual lines with the values
 }
 system("pause");
 return 0;
}
