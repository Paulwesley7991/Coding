#include <iostream>
#include <cstdlib>

using namespace std;

class Euro
{
private:
    int euro;
    int cent;
public:
    Euro() : euro(0), cent(0) {}
    Euro(int e) : euro(e), cent(0) {}
    Euro(int e, int c) : euro(e), cent(c) {}
    void output()
    {
        cout << euro << "," << cent << endl;
    }
    friend Euro operator+ (const Euro &a, const Euro &b);
    friend Euro operator- (const Euro &a, const Euro &b);
    Euro operator* (const double &z);
};

Euro operator+ (const Euro &a, const Euro &b)
{
   Euro erg;

   erg.euro = a.euro + b.euro;
   erg.cent = a.cent + b.cent;
   while(erg.cent >= 100)
   {
      erg.cent = erg.cent - 100;
      erg.euro++;
   }
   return erg;
}

Euro operator- (const Euro &a, const Euro &b)
{
   Euro erg;

   erg.euro = a.euro - b.euro;
   erg.cent = a.cent - b.cent;
   while(erg.cent < 0)
   {
       erg.cent = 100 + erg.cent;
       erg.euro--;
   }
   return erg;
}

Euro Euro::operator* (const double &z)
{
    cent = cent * z;
    euro = euro * z;
    
    if(z > 0)
    {
        while(cent >= 100)
        {
           cent = cent - 100;
           euro++;
        }
    }
    else if(z < 0)
    {
        while(cent <= -100)
        {
           cent = cent + 100;
           euro--;
        }
    }
    
    return *this;
}

int main()  
{  
	Euro myMoney(100,80), yourMoney(45,30), fee(25,80), ourMoney;
	double interestrate = 3.5;
	ourMoney = myMoney + yourMoney;
	ourMoney.output();
	ourMoney = ourMoney - fee;
	ourMoney.output();
	ourMoney = ourMoney.operator*(interestrate);
	ourMoney.output();
    
    system("pause");
    return 0;
} 
