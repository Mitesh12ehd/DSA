#include<iostream>
#include<cmath>
using namespace std;

int formNumber(int digits[],int n){
    int num = 0;
    for(int i=0; i<n; i++){
        num = (num * 10) + digits[i];
    }
    return num;
}

int main(){
    int totalDigit;
    cout << "Enter total digit = ";
    cin >> totalDigit;

    int digits[totalDigit];
    for(int i=0; i<totalDigit; i++){
        cin >> digits[i];
    }
    cout << formNumber(digits,totalDigit);

    return 0;
}