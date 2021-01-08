#include "cstdlib"
#include "iostream"
using namespace std;

class Vehicle
{
private:
string brand;
string licencePlate;
int ps;
int yearOfConstruction;

public:

//Constructor with member initialization list
Vehicle(string b, string l, int p, int cy): brand(b), licencePlate(l), ps(p), yearOfConstruction(cy) {}

//Function to display data
void displayData(){
cout << "Brand: " << brand << endl;
cout << "Licence Pplate: " << licencePlate << endl;
cout << "Anzahl PS: " << ps << endl;
cout << "Year of construction: " << yearOfConstruction << endl;
}

string getBrand() { return brand; }
string getLicencePlate() { return licencePlate; }
int getPS() { return ps; }
int getYearOfConstruction() { return yearOfConstruction; }

//Operator <= is overloaded as member function
void operator<=(Vehicle v1) {
if (this->yearOfConstruction < v1.yearOfConstruction) {
cout << "Vehicle " << this->getBrand() << " is older than " << v1.getBrand() << endl; 
} else if (this->yearOfConstruction > v1.yearOfConstruction) {
cout << "Vehicle " << this->getBrand() << " is younger than " << v1.getBrand() << endl; 
} else {
cout << "Both vehicles are the same age" << endl; 
} 
} 

};

//Operator overloading - Operator == is overloaded
//The function is declared as an external function of the class 
void operator==(Vehicle v1, Vehicle v2) {
if (v1.getBrand() == v2.getBrand() && v1.getLicencePlate() == v2.getLicencePlate() && v1.getPS() == v2.getPS() && v1.getYearOfConstruction() == v2.getYearOfConstruction()) {
cout << "They are the same vehicles" << endl;
} else {
cout << "They are not the same vehicles" << endl; 
}
}

int main(){

//Create instance
Vehicle fz1("Opel", "PA AA 333", 66, 1999);
Vehicle fz2("BMW", "DEG DD 222", 103, 2005);

//Call comparative operator
fz1 == fz2;

//Greater than / less than Operator
fz1 <= fz2;


system("pause");
return 0;
};
