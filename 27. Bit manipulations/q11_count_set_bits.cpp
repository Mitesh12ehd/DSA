#include<iostream>
using namespace std;

//Leetcode 191
//Number of 1 bits

//see notes for third approach

//brute force
int hammingWeight(int n) {
    int ans = 0;
    while(n != 0){
        if(n % 2 == 1){
            ans++;
        }
        n = n/2;
    }
    return ans;
}

//bit version slightly faster
int hammingWeight(int n) {
    int ans = 0;
    while(n != 0){
        if(n & 1){
            ans++;
        }
        n = n >> 1;
    }
    return ans;
}

//one more approach
int hammingWeight(int n) {
    int ans=0;
    while(n != 0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int main(){
    return 0;
}