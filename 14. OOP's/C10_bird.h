#if !defined(C10_BIRD_H)
#define C10_BIRD_H
#include<iostream>
using namespace std;

class Bird{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;
        //class can inherit this class
        //those class have to implement virtual function
};

class Sparrow : public Bird{
    public:
        void eat(){
            cout << "Sparrow is eating" << endl;
        }
        void fly(){
            cout << "Sparrow is flying" << endl;
        }
};

class Eagle : public Bird{
    public:
        void eat(){
            cout << "eagle is eating" << endl;
        }
        void fly(){
            cout << "eagle is flying" << endl;
        }
};

#endif