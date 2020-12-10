#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
 ifstream output_data;
 ofstream copy_data;
 try
 {
 output_data.open("source.txt",ios::in);
 copy_data.open("backupcopy.txt");
 if(!output_data.good())
 throw (string)"source.txt"; // If the file does not exist
 else if(!copy_data.good())
 throw (string)"backupcopy.txt"; // If the file is write-protected

 char ch;
 while(output_data.get(ch)){ // Read character by character from the file
 copy_data.put(ch); // Copy character by character into the file
 }
 }
 catch(string filename)
 {
 cerr << "Error: " << filename << " cannot be opened." << endl; // cerr is used like cout
 } // Output as an error

 output_data.close();
 copy_data.close();

 system("pause");
 return 0;
}
