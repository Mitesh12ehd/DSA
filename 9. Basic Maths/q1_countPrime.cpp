#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isPrime(int i){
    //method 1 normal O(n^2)
    // if(i <= 1){
    //     return false;
    // }
    // for(int m=2; m<i; m++){
    //     if(i%m == 0){
    //         return false;
    //     }
    // }
    // return true;

    //method 2 square root O( n*n^1/2);
    if(i <= 1){
        return false;
    }
    int sqrtN = sqrt(i);
    for(int m=2; m<=sqrtN; m++){
        if(i%m == 0){
            return false;
        }
    }
    return true;
}
int countPrimes(int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}
int main(){
    //leetcode 204
    int n = 35;
    cout << countPrimes(n);

    return 0;
}