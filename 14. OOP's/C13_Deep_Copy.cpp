#include<iostream>
using namespace std;

class abc{
    public:
    int x;
    int *y;

    abc(int _x,int _y) : x(_x),y(new int(_y)) {}

    //deep copy ctor
    abc(abc& obj){
        this->x = obj.x;
        this->y = new int(*obj.y);
    }

    void print() const {
        cout << "x = " << x << endl;
        cout << "content of y = " << y << endl;
        cout << "value of y = " << *y <<endl << endl;
    }

    ~abc(){
        delete y;
    }
};
int main(){
    abc a(1,2);
    a.print();

    abc b = a;
    b.print();

    *(b.y) = 20;
    b.x = 10;
    cout << "printing b" << endl;
    b.print();
  
    cout << "printing a" << endl;
    a.print();
    return 0;
}