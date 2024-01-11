#include<iostream>
#include<limits.h>
using namespace std;

int myAtoi(string s) {
    int ans = 0;
    int sign = 1; //take positive fisrt

    int i=0;
    while(s[i] == ' '){
        i++;
    }
    if(i<s.length()  &&  (s[i] == '-' || s[i] == '+')){
        sign = (s[i]=='+') ? (1) : (-1);
        i++;
    }

    while(i<s.length()  &&  isdigit(s[i])){
        if(ans > INT_MAX/10  ||  ( ans == INT_MAX/10 && s[i]>'7' )){
            return (sign == -1) ? (INT_MIN) : (INT_MAX);
        }

        ans = (ans*10) + (s[i]-'0');
        i++; 
    }
    return sign*ans;
}


int main(){
    //leetcode 8
    string s = "   -55mitesh";
    cout << myAtoi(s);

    return 0;
}