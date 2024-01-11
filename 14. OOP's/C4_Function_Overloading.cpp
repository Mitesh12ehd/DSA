#include<iostream>
using namespace std;

class Maths{
    public:
        int sum(int a,int b){
            cout << "inside function 1" << " : ";
            return a+b;
        }
        int sum(int a,int b,int c){
            cout << "inside function 2" << " : ";
            return a+b+c;
        }
        int sum(int a,float b){
            cout << "inside function 3" << " : ";
            return a+b;
        }
};
int main(){
    Maths obj;
    cout << obj.sum(1,2) <<endl ;
    cout << obj.sum(1,2,3) <<endl;
    cout << obj.sum(1,1.1f) <<endl;

    return 0;
}