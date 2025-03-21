#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

//leetcode 1614
//maximum nesting depth of paranteses

int maxDepth(string s) {
    stack<int> st;

    int maxi = INT_MIN;
    int count = 0;
    for(auto it:s){
        if(it == '('){
            count++;
            maxi = max(maxi,count);
        }
        else if(it == ')'){
            count--;
        }
    }
    return maxi;
}

int main(){
    return 0;
}