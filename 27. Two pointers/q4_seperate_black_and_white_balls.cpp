#include<iostream>
using namespace std;

//leetcode 2938 
//seprate black and white balls

long long minimumSteps(string s) {
    int n = s.length();
    if(n == 1){
        return 0;
    }

    int i = 0;
    int j = n-1;
    long long ans = 0;
    while(i < j){
        if(s[j] == '1'){
            j--;
        }
        else if(s[i] == '0'){
            i++;
        }
        else{
            ans = ans + (j-i);
            i++,j--;
        }
    }
    return ans;
}

int main(){
    return 0;
}