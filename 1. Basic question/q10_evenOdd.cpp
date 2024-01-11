#include<iostream>
using namespace std;

bool checkEvenOdd(int n){
    if((n & 1) == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;

    if(checkEvenOdd(n)){
        cout<<"Number is even";
    }
    else{
        cout<<"Number is odd";
    }

    return 0;
}