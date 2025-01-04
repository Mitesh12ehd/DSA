#include<iostream>
#include<unordered_map>
using namespace std;

//coding ninjas
//longest substring that have at most k unique charcter

//brute force N^2 and O(26) space
int kDistinctChars(int k, string &s){
    int ans = 0;
    int n = s.length();
        
    for(int i=0; i<n; i++){
        unordered_map<char,int> mp;
        for(int j=i; j<n; j++){
            mp[s[j]]++;
            if(mp.size() <= k){
                ans = max(ans,j-i+1);
            }
            else{
                break;
            }
        }
    } 
    return ans;
}

//O(2N) time    O(26) space
int kDistinctChars(int k, string &str){
    int n = str.length();
    int ans = 0;
        
    int left = 0;
    int right = 0;
    unordered_map<char,int> mp;

    while(right < n){
        mp[str[right]]++;

        while(mp.size() > k){
            mp[str[left]]--;
            if(mp[str[left]] == 0){
                mp.erase(str[left]);
            }
            left++;
        }

        ans = max(ans,right-left+1);
        right++;
    }
    return ans;
}

//O(N) time    O(26) space
//for previous solution when we go mp.size() more than k 
//we trim window untill mp.size() becomes k
//but there is no need to trim window, we just remove one element from window
//and check if it valid then update length
int kDistinctChars(int k, string &str){
    int n = str.length();
    int ans = 0;
        
    int left = 0;
    int right = 0;
    unordered_map<char,int> mp;

    while(right < n){
        mp[str[right]]++;

        if(mp.size() > k){
            mp[str[left]]--;
            if(mp[str[left]] == 0){
                mp.erase(str[left]);
            }
            left++;
        }

        if(mp.size() <= k){
            ans = max(ans,right-left+1);
        }
        right++;
    }
    return ans;
}

int main(){
    string str = "aaabbccd";
    int k = 2;
    cout << kDistinctChars(k,str);
    return 0;
}