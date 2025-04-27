#include<iostream>
using namespace std;

//Given N,find xor from 1 to N
//see notes

//brute force can be using loop

int findXOR(int n){
    if(n % 4 == 1){
        return 1;
    }
    if(n % 4 == 2){
        return n+1;
    }
    if(n % 4 == 3){
        return 0;
    }
    if(n % 4 == 0){
        return n;
    }
}

int main(){
    return 0;
}