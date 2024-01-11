#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    string name;
    void eat(){
        cout << "eating";
    }

    private:
    int weight;

    protected:
    int height;
};
int main(){
    Animal lion;
    lion.age = 18;
    lion.name = "lion";
    cout << lion.name << lion.age <<endl ;
    lion.eat();
    return 0;
}