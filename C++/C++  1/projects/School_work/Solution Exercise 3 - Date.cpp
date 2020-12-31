#include <iostream>
#include <cstdlib>

using namespace std;
  
class Date  
{  
    public:
    int day, month, year;
public:  
    friend istream &operator>>(istream &is, const Date &dt);  
    friend ostream &operator<<(ostream &os, const Date &dt);  
};  

istream &operator>>(istream &is, Date& dt)  
{  
    cout << "Month: ";
    do
    {
        is >> dt.month;
    }while (dt.month<1 || dt.month>12);
    cout << "Day: ";
    int tmp = 0;
    do
    {
    is >> dt.day;
    if(dt.day >= 1)
    {
        if(dt.month == 1 || dt.month == 3 || dt.month == 5 || dt.month == 7 || dt.month == 8 || dt.month == 10 || dt.month == 12)
        {
            if(dt.day <= 31)
            {
                tmp = 1;
            }
        }
        else if(dt.month == 2 && dt.day <= 28)
        {
            tmp = 1;
        }
        else if(dt.month != 2 && dt.day <= 30)
        {
            tmp = 1;
        }
    }
    }while(tmp == 0);
    cout << "Year: ";
    do
    {
        is >> dt.year;
    }while(dt.year<0);
    return is;  
} 
  
ostream &operator<<(ostream &os, const Date &dt)  
{  
    os << dt.day << '.' << dt.month << '.' << dt.year;  
    return os;  
}  
  
int main()  
{  
    Date dt;
    cin >> dt;
    cout << dt;  
    
    system("pause");
    return 0;
}  
