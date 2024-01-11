#include<iostream>
using namespace std;

int climbstairs(int n){
    //base condition
    if(n==0 || n==1){
        return 1;
    }
    //recursive approach
    return climbstairs(n-1) + climbstairs(n-2);
}

int main(){
    int n;
    cout << "enter n";
    cin >> n;
    cout << climbstairs(n);

    return 0;
}