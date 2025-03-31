#include<iostream>
#include<cmath>
using namespace std;

//Leetcode 231
//Power of two

//brute force 1 time=O(logn)
bool isPowerOfTwo(int n) {
    long long num = 1;
    while(num < n){
        num = num * 2;
    }
    return num == n;
}

//brute force 2 time=O(logn)
//convert into binary
//count set bits
//if set bits = 1 it is binary otherwise not


//optimal approach time = O(1)
//we have seen the bianry of num and num-1

//if num is power of two it has 1 set bits
//      num-1 have 0 at first place, and rest bit becomes 1
//ex. num=16,  10000
//    num-1=15,01111
//and now if take num & num-1 answer becomes zero

//if num is not power of two then
//    it not becomes zero after num & num-1

bool isPowerOfTwo(int n) {
    if(n<=0){
        return false;
    }

    return (n & (n-1)) == 0;
}

int main(){
    return 0;
}