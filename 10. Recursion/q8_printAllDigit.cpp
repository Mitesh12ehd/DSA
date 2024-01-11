#include<iostream>
using namespace std;

void printDigit(int number){
    //basecase
    if(number == 0){
        return;
    }
    //recursive approach
    printDigit(number / 10);
    //processing
    int digit = number % 10;
    cout << digit << ",";
}

int main(){
    int number = 647;
    printDigit(647);

    return 0;
}