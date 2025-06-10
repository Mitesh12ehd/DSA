#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 1048
// Longest String Chain

// Prerequisite : Print LIS

/*
 - question is asking about longest string subset with given rules
 - here instead of inserting char, we can look for difference of one char in 
   two words
 - we can map this question with length of LIS ,
   in that question we check if curr element is greater that previous element or not
 - here we can check for previous string and current string is differ with one
   char or not
 - else part remain same

 - how to compare curr and prev string with one char difference?
   ex. curr = "bdca"
       prev = "bda"

       take two pointer i and j 
       - when char at both index match, increase i and j
       - when char not match at i and j, mismatchcount = 1 and increase i only
       - if we found another mismatch , straight away return false
       - dryrun
*/

// time = O(n^2 * maxlength of string)
// space = O(n)
bool is_Differ_with_one_char(string& prev,string& curr){
    int m = curr.size();
    int n = prev.size();

    if(m != n+1){
        return false;
    }

    int i=0,j=0;
    int mismatchCount = 0;
    while(i<m && j<n){
        if(curr[i] == prev[j]){
            i++,j++;
        }
        else{
            if(mismatchCount == 1)
                return false; 
                
            mismatchCount++;
            i++;
        }
    }
    return true;
}
static bool myComp(string& a,string& b){
    return a.length() < b.length();
}
int longestStrChain(vector<string>& words) {
    int n = words.size();
    vector<int> dp(n,1);

    sort(words.begin(),words.end(),myComp);
    
    int ans = 1;
    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(is_Differ_with_one_char(words[prev],words[i])){
                dp[i] = max(dp[i],1 + dp[prev]);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main(){
    return 0;
}