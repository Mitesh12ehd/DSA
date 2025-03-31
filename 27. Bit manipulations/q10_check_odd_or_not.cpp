#include<iostream>
using namespace std;

// Tips : we should use bit operator to reduce time
//        bits operator are faster than other operators

bool isNumberOdd(int num){
    return num % 2 == 1;

    return num % 2;

    return num & 1 == 1;

    return num & 1;
}

int main(){
    return 0;
}