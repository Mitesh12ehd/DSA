#include<iostream>
using namespace std;

//set ith bit from previous to 0

//num = 13, i=2
//1101
// set 2nd bit from last to 0
//1001 = 9

// brute force 
// 1. covert into binary
// 2. convert ith bit to 0
// 3. convert into decimal

// optimal
//we have num and i

// first we make mask = ~(1 << i)
// because 1 << 2 == 100
//         1 << 3 == 1000
//by taking ~ of that we have 0 at ith position and rest all bits are 1

//now we perform &,
// num | mask 
//it will set ith bit to 0 and rest bit are remain same
//take example of num=13,i=2

int setIthBit(int num,int i){
    int mask = 1 << i;

    int num = num | mask;
    return num;
}


int main(){
    return 0;
}