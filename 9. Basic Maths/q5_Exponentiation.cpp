#include<iostream>
using namespace std;

int fastExpontiation(int a,int b){
    //Time = O(b)
    int ans = 1;
    while(b > 0){
        if( b % 2 == 1){
            //odd
            ans = ans * a;
        }
        a = a * a;
        b = b / 2;
    }
    return ans;
}

int slowExpontiation(int a,int b){
    //Time = O(b)
    int ans = 1;
    for(int i=1; i<=b; i++){
        ans = ans * a;
    }
    return ans;
}

int main(){
    cout << slowExpontiation(5,4) << endl;
    cout << fastExpontiation(5,4);

    return 0;
}