#include<iostream>
using namespace std;

//function to check numebr is prime or not

//defination of prime number 
//a number that have exactly two factor, a 1 and n self

//brute force time = O(n)
bool checkPrime(int n){
    int count = 0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            count++;
        } 
    }
    if(count == 2){
        return true;
    }
    return false;
}

//optimal time = O(squareroot(n))
bool checkPrime(int n){
    int count = 0;
    for(int i=1; i*i<=n; i++){
        if(n % i == 0){
            count++;
            if(n/i != i){
                count++;
            }
        } 
    }
    if(count == 2){
        return true;
    }
    return false;
}

int main(){
    cout << checkPrime(57);
    return 0;
}