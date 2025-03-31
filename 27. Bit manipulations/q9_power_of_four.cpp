#include<iostream>
#include<cmath>
using namespace std;

//see notes

//Leetcode 342
//Power of four

// time = O(logn) base 4
bool isPowerOfFour(int n) {
    long long num = 1;
    while(num < n){
        num = num * 4;
    }
    return num == n;
}

// time = O(1)
bool isPowerOfFour(int n) {
    if(n <= 0){
        return false;
    }

    //find log(n) on base 4
    double result = log(n) / log(4); //log n on base 4 = logn/log4
    return fmod(result,1) == 0;
}

int main(){
    return 0;
}