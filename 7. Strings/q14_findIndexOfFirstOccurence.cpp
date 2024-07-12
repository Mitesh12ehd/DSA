#include<iostream>
#include<string>
using namespace std;

//this is brute force of string matching called naive appproach
//other algortihm of string matching are kmp,rabin karp,finite automata
int strStr(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();

    for(int i=0; i<=n-m; i++){
        for(int j=0; j<m; j++){
            if(needle[j] != haystack[i+j]){
                break;
            }
            if(j == m-1){
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