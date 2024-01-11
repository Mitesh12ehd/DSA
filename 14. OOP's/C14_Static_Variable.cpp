#include<iostream>
using namespace std;

class abc{
    public:
    static int x,y;
    void print(){
        cout << x << " ";
        cout << y << endl;
    }
};

int abc::x;
int abc::y;

int main(){
    abc obj1;
    obj1.abc::x = 1;
    obj1.abc::y = 2;
    obj1.print();

    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj1.print();
    obj2.print();

    return 0;
}