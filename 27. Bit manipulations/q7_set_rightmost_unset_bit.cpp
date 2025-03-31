#include<iostream>
using namespace std;

//The problem is to set the rightmost unset bit 

int setBit(int n) {
    return n | (n+1);
}

int main(){
    return 0;
}