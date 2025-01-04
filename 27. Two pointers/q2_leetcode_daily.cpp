#include<iostream>
using namespace std;

//leetcode 2825
//make string a subsequence using cyclic increaments

bool canMakeSubsequence(string str1, string str2) {
    int i = 0;
    int j = 0;

    int m = str1.length();
    int n = str2.length();

    while(i<m && j<n){
        if(str1[i] == str2[j]){
            i++,j++;
        }
        else if(str1[i]+1 == str2[j]){
            i++,j++;
        }
        //cycle case
        else if(str1[i] == 'z' && str2[j] == 'a'){
            i++,j++;
        }
        else{
            i++;
        }
    }
    return j==n;
}

int main(){
    return 0;
}