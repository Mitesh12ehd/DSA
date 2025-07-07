#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Leetcode 2014
// Longest subsequence repeated k times


// time = O(n * 26 ^ (n/k) ) 
// our answer not exceed n/k and we call each for 26 character
// n time taken by countSubSequence() function

// space = O(26 ^ (n/k))
// in worst case we store  string of n/k size for each character a -> z

// dryrun to understand
int countSubSequence(string& s,string& subseq){
    // time = O(n)
    // space = O(1)
    int i = 0;
    int j = 0;

    int count = 0;
    while(i < s.length() && j < subseq.length()){
        if(s[i] == subseq[j]){
            i++,j++;
        }
        else{
            i++;
        }

        if(j >= subseq.length()){
            count++;
            j = 0;
        }
    }
    return count;
}
string longestSubsequenceRepeatedK(string s, int k) {
    int arr[26] = {0};
    for(auto it:s){
        arr[it-'a']++;
    }

    queue<string> q;
    q.push("");
    string ans = "";
    while(!q.empty()){
        string curr = q.front();
        q.pop();

        for(int i=0; i<26; i++){
            if(arr[i] >= k){
                string next = curr + (char)(i + 'a');
                if(countSubSequence(s,next) >= k){
                    ans = next;
                    q.push(next);
                }
            }
        }
    }
    return ans;
}

int main(){
    string s = "letsleetcode";
    int k = 2;
    cout  << longestSubsequenceRepeatedK(s,k);

    return 0;
}