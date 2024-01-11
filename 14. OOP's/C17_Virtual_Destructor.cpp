#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout<<"base constructor" <<endl;
    }
    virtual ~Base(){
        cout << "base destructor" <<endl;
    }
};
class Derived:public Base{
    int *a;
    public:
    Derived(){
        a = new int[10];
        cout << "Derived constructor" <<endl;
    }
    ~Derived(){
        delete []a;
        cout << "Derived destructor" <<endl;
    }
};
int main(){
    Base *obj = new Derived();
    delete obj;
    return 0;
}