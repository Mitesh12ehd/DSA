#include<iostream>
using namespace std;

class Animal{
    public:
    Animal(){
        cout << "animal constructor" << endl;
    }
    void speak(){
        cout << "speaking" <<endl;
    }
};
class Dog:public Animal{
    public:
    Dog(){
        cout << "dog constructor" << endl;
    }
    void speak(){
        cout << "barking" <<endl;
    }
};
int main(){
    return 0;
}