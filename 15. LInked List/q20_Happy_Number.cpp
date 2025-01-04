#include<iostream>
using namespace std;

int digitSquare(int num){
    int ans = 0;
    while(num){
        int digit = num % 10;
        ans = ans + (digit*digit);
        num = num / 10;
    }
    return ans;
}

bool isHappy(int n){
    int slow = n;
    int fast = n;

    do{
        slow = digitSquare(slow);
        fast = digitSquare(digitSquare(fast));
    }while(slow != fast);

    if(slow == 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n = 19;
    cout << isHappy(n);
    return 0;
}