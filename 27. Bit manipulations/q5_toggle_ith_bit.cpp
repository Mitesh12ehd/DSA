#include<iostream>
using namespace std;

//toggle ith bit from previous.

//num = 13, i=2
//1101
// toggle ith bit from last.
//1001 = 9

// brute force 
// 1. covert into binary
// 2. toggle ith bit
// 3. convert into decimal

// optimal
//we have num and i

// first we make mask = 1 << i
// because 1 << 2 == 100
//         1 << 3 == 1000
//by taking ~ of that we have 0 at ith position and rest all bits are 1

//now we perform ^,
// num ^ mask 
//it will toggle ith bit
//and rest bit are ensured because 
    // if it is ith bit
    //     if it is 0 , it perform ^ with 1 and final bit become 1
    //     if it is 1 , it perfomr ^ with 1 and final bit become 0
    // if it is non ith bit_and
    //     if it is 0, it perform ^ with 0 and final bit become 0
    //     if it is 1, it perfomr ^ with 0 and final bit become 1

int toggleIthBit(int num,int i){
    int mask = 1 << i;

    int num = num ^ mask;
    return num;
}


int main(){
    return 0;
}