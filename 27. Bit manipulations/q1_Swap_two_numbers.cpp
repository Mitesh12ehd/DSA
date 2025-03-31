#include<iostream>
using namespace std;

//see notes

void swapNumbers(int& a,int& b){
    int temp = a;
    a = b; 
    b = temp;
}

void swapNumbers(int& a,int& b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void swapNumbers(int& a,int& b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){
    return 0;
}