#include<iostream>
using namespace std;

class A{
    private:
        int x;

    public:
        A(int val){
            x=val;
        }
    
    friend class B;
    friend void print(A& a);
};
class B{
    public:
        void print(A& a){
            cout << a.x <<endl;
        }
};
void print(A& a){
    cout << a.x <<endl;
}
int main(){
    A a(5);
    B b;
    b.print(a);
    print(a);
    return 0;
}