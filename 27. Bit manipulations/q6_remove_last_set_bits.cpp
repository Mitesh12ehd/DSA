#include<iostream>
using namespace std;

//see notess

//remove last set bits

//num = 12
//1100
//after convert last set bit to 0 it become
//1000 = 8

// brute force 
// 1. covert into binary
// 2. travese to find last set bits, covert it into 0
// 3. convert into decimal

// optimal
int remove_last_set_bit(int num){
    return num & (num-1);
}


int main(){
    return 0;
}