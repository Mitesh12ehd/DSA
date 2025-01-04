#include<iostream>
#include<limits.h>
using namespace std;

//brute force n^2 space = O(256)
string minWindow(string s, string t) {
    int n = s.length();
    int mini = INT_MAX;
    int sIndex = -1;

    for(int i=0; i<n; i++){
        int hash[256] = {0};
        for(auto it:t){
            hash[it]++;
        }
            
        int count = 0;
        for(int j=i; j<n; j++){
            if(hash[s[j]] > 0){
                count++;
            }
            hash[s[j]]--;

            if(count == t.length()){
                if(j-i+1 < mini){
                    mini = j-i+1;
                    sIndex = i;
                    break;
                }
            }
        }
    }

    if(mini == INT_MAX){
        return "";
    }

    string ans;
    int start = sIndex;
    int end = sIndex + mini - 1;
    for(int i=start; i<=end; i++){
        ans.push_back(s[i]);
    }
    return ans;
}

string minWindow(string s, string t) {
    int hash[256] = {0};
    int left=0, right=0;
    int minlength = INT_MAX;
    int count = 0;
    int sIndex = -1;

    for(auto it:t){
        hash[it]++;
    }

    while(right < s.length()){
        if(hash[s[right]] > 0){
            count++;
        }

        hash[s[right]]--;

        while(count == t.length()){
            //consider substring
            if(right-left+1 < minlength){
                minlength = right-left+1;
                sIndex = left;
            }

            //remove left charcter from window
            hash[s[left]]++;
            if(hash[s[left]] > 0){
                count--;
            }
            left++;
        }
        right++;
    }

    if(minlength == INT_MAX){
        return "";
    }
        
    string ans;
    int start = sIndex;
    int end = sIndex + minlength - 1;
    for(int i=start; i<=end; i++){
        ans.push_back(s[i]);
    }
    return ans;
}

int main(){
    return 0;
}