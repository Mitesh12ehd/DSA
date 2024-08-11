#include<iostream>
#include<string>
using namespace std;

//this is brute force of string matching called naive appproach
//other algortihm of string matching are kmp,rabin karp,finite automata
int strStr(string haystack, string needle) {
    int m = haystack.length();
    int n = needle.length();

    for(int i=0; i<=m-n; i++){
        for(int j=0; j<n; j++){
            if(needle[j] != haystack[i+j]){
                break;
            }
            if(j == n-1){
                return i;
            }
        }
    }
    return -1;
}
int main(){
    //leetcode que 28
    string haystack = "letsadu";
    string needle = "sad";
    cout << strStr(haystack,needle);

    return 0;
}