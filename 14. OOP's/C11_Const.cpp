#include<iostream>
using namespace std;

class abc{
    int x;
    int *y;
    int z;

    public:
        abc(int _x,int _y,int _z=0){
            x = _x;
            y = new int(_y);
            z = _z;
        }

        int getX() const{
            // x = 50  --it gives error
            return x;
        }
        void setX(int val){
            x = val;
        }

        int getY() const{
            return *y;
        }
        void setY(int val){
            *y = val;
        }
        int getZ() const{
            return z;
        }
};
void printABC( const abc& a){
    //if any one of these three are not const it gives error
    cout << a.getX() <<" ";
    cout << a.getY() <<" ";
    cout << a.getZ() <<" ";
}
int main(){
    abc a(1,2,3);
    printABC(a); 

    return 0;
}