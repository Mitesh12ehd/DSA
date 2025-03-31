#include<iostream>
#include<limits.h>
using namespace std;

//Leetcode 29
//Divide two intergers

//read notes

//brute force  time = O(divid/divir) = O(quetient);
int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }
    if(dividend == INT_MIN && divisor == 1){
        return INT_MIN;
    }

    bool sign = (dividend > 0) == (divisor > 0) ? true : false;
    long long divid = abs((long long)dividend);
    long long divir = abs((long long)divisor);

    int count = 0;
    while(divid - divir >= 0){
        divid = divid - divir;
        count++;
    }

    count = sign ? count : -count;
    return count;
}

//optimal approach 
//22 written as 3 * (7) = 3* (2^2 + 2^1 + 2^0)
//it is lograthimc represntation 
//so that outer while loop runs for logn time

//inner loop runs for find out largest power of 2 that we can substract
//it takes log(n) time

//overall time = O(logn * logn) on base 2

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }
    if(dividend == INT_MIN && divisor == 1){
        return INT_MIN;
    }

    bool sign = (dividend > 0) == (divisor > 0) ? true : false;
    long long divid = abs((long long)dividend);
    long long divir = abs((long long)divisor);

    int ans = 0;
    while(divid >= divir){
        int count = 0;
        //(divisor << (count+1)) is same as divisor * pow(2,n+1)
        while(divid >= (divir << (count+1))){
            count++;
        }
        
        //1<< count  same as 2^count
        ans = ans + (1 << count); 
        divid = divid - (divir << count);
    }

    ans = sign ? ans : -ans;
    return ans;
}

int main(){
    return 0;
}