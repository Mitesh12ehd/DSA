#include<iostream>
using namespace std;

//Leetcode 2220
//Minimum bit flips to convert number

//after all we need to find number of bits that are 
//    not equivalent in both number

//so that we take ^ , it make 1 where two bits are same, else make 0
//and we count 1 using countSetBit question

int countSetBits(int n) {
    int ans=0;
    while(n != 0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}
int minBitFlips(int start, int goal) {
    return countSetBits(start ^ goal);
}

int main(){
    return 0;
}