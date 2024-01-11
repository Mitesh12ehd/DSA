#include<iostream>
using namespace std;

class Animal{
    private:
        int weight;
    public:
        int age;
        string name;
    
        //default constructor
        Animal(){
            this->weight = 0;
            this->age = 0;
            this->name = "";
            cout << "default constructor called" << endl;
        }

        //parameterized constructor
        Animal(int age){
            this->age = age;
            cout << "parameterized constructor 1 called" << endl;
        }
        Animal(int age,int weight){
            this->age = age;
            this->weight = weight;
            cout << "parameterized constructor 2 called" << endl;
        }

        //copy constructor
        Animal(Animal& obj){
            this->age = obj.age;
            this->weight = obj.weight;
            this->name  = obj.name;
            cout << "copy constructor called" << endl;
        }
};
int main(){
    Animal lion;
    Animal Deer(100);
    Animal cow(100,200);

    //copy object
    Animal monkey = cow;
    //or
    // Animal monkey(cow);

    return 0;
}