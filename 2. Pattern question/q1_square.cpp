#include<iostream>
using namespace std;
int main(){
    for(int i=0; i<3; i++){      //row
        for (int i=0; i<5; i++){ //column
            cout << "*" ;
        }
        cout << endl;
    }
    return 0;
}