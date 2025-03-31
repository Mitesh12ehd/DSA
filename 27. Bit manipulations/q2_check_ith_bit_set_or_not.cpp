#include<iostream>
using namespace std;

//given num and i check ith bit is set or not?
//check ith bit is 1 or not?
//i is 0-indexed and counted from backwards of binary format

// ex. num = 13,  i=2
//     num = (1101)
//     here 2nd bit from last is 1 so return true;

//brute force
bool checkIthBit(int num, int i) {
    string binaryFormat = "";

    while(num>0){
        int bit = num & 1; //we get last bits
        binaryFormat.push_back(bit+'0');
        num = num / 2;
    }
    
    if(i >= binaryFormat.length()){
        return false;
    }
    return binaryFormat[i]  == '1';
}

//better approach
//we have num and i

// first we make mask = 1 << i
// because 1 << 2 == 100
//         1 << 3 == 1000
//it set ith bit to 1 and rest all the bits remain zero

//now we perform &,
// num & mask 
//if it is non-zero number than ith bit is 1
//else ith bit is 0

bool checkIthBit(int num, int i) {
    int mask = 1 << i;
    
    if(num & mask != 0){
        return true;
    }
    return false;
}


int main(){
    return 0;
}