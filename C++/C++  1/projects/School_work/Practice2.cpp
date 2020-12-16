#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

class exam{
    friend class test;
public:
    int x = 8;};
class test: public exam
{ friend class exam;
    public:
    int f =9;
    test(){
    cout<<"worked like magic"<<endl;}
};
int main(void){
exam Exam[2];
exam EXAM;
Exam[0] = EXAM;
cout<< Exam[0].x;
test Test;
Exam[1] = Test;
cout<< Exam[1].f;
system("pause"); }
