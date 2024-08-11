#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    string name;
    void eat(){
        cout << "eating";
    }

    //destructor
    ~Animal(){
        cout << "destructor called" <<endl;
    }
};
int main(){
    cout << "b object creation" << endl;
    Animal* lion = new Animal;
    lion->age = 12;

    //manually destructor call
    delete lion;

    return 0;
}