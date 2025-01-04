#include<iostream>
using namespace std;

//leetcode 2490
//circular sentence

bool isCircularSentence(string str) {
    int n = str.length();
    if(str[0] != str[n-1]){
        return false;
    }

    int i=0;
    while(i<n){
        if(str[i] == ' ' && i <= n-2 && i>0){
            if(str[i-1] != str[i+1]){
                return false;
            }
        }
        i++;
    }

    return true;
}

int main(){
    return 0;
}