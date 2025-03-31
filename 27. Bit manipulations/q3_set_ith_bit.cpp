#include<iostream>
using namespace std;

//set ith bit from previous to 1

//num = 9, i=2
//1001
// set 2nd bit from last to 1
//1101 = 13

// brute force 
// 1. covert into binary
// 2. convert ith bit to 1
// 3. convert into decimal

// optimal
//we have num and i

// first we make mask = 1 << i
// because 1 << 2 == 100
//         1 << 3 == 1000
//it set ith bit to 1 and rest all the bits remain zero

//now we perform |,
// num | mask 
//it will set ith bit to 1

int setIthBit(int num,int i){
    int mask = 1 << i;

    int num = num | mask;
    return num;
}


int main(){
    return 0;
}