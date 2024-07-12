#include<iostream>
using namespace std;

class abc{
    public:
    int x;
    int *y;

    abc(int _x,int _y){
        x = _x;
        y = new int(_y);
    }

    //default dumb copy constructor
    //shallow copy
    abc(abc& obj){
        this->x = obj.x;
        this->y = obj.y;
    }

    void print() const {
        cout << "x = " << x << endl;
        cout << "content of y = " << y << endl;
        cout << "value of y = " << *y <<endl << endl;
    }
};

int main(){
    //shallow copy
    abc a(1,2);
    a.print();

    abc b = a;
    b.print();

    *(b.y) = 20;
    b.x = 10;
    cout << "printing b";
    b.print();
  
    cout << "printing a";
    a.print();
    return 0;
}