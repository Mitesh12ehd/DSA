#include<iostream>
#include<cmath>
using namespace std;

bool checkPrime(int num){
    if(num <= 1){
        return false;
    }
    for(int i=2; i<=num/2; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void printAllPrime(int n){
    for(int i=1; i<=n; i++){
        if(checkPrime(i)){
            cout << i << " ";
        }
    }
}

int main(){

    int n;
    cout << "enter n = ";
    cin >> n;
    printAllPrime(n);

    return 0;
}