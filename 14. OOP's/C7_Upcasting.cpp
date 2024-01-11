#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout << "speaking";
    }
};
class Dog:public Animal{
    public:
    void speak(){
        cout << "barking";
    }
};
int main(){
    Animal *a = new Dog();
    a->speak();

    return 0;
}