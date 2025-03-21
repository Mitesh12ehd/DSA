#include<iostream>
#include<limits.h>
using namespace std;

//Leetcode 1781
//sum of beauty of all substrings

//time = O(n^3) space = O(26)
int beautySum(string s) {
    int n = s.length();
    int ans = 0;

    for(int i=0; i<n; i++){
        int hash[26] = {0};
        for(int j=i; j<n; j++){
            hash[s[j]-'a']++;

            int maxfreq = INT_MIN;
            int minfreq = INT_MAX;
            for(int k=0; k<26; k++){
                if(hash[k] > 0){  
                    maxfreq = max(maxfreq,hash[k]);
                    minfreq = min(minfreq,hash[k]);
                }
            }
            ans = ans + maxfreq - minfreq;
        }
    }
    return ans;
}

int main(){
    return 0;
}