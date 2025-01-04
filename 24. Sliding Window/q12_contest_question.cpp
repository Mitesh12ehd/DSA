#include<iostream>
#include<unordered_map>
using namespace std;

//3325 count substring with k frequences character I

int numberOfSubstrings(string s, int k) {
    int n = s.length();
    int ans = 0;

    for(int i=0; i<n; i++){
        int hash[26] = {0};
        int maxfreq = 0;

        for(int j=i; j<n; j++){
            hash[s[j] - 'a']++;
                
            maxfreq = max(maxfreq,hash[s[j] - 'a']);
            if(maxfreq >= k){
                ans++;
            }
        }
    }
    return ans;
}

int numberOfSubstrings(string s, int k) {
    int n = s.length();
    int count = 0;
    unordered_map<char,int> mp;
    int left = 0, right = 0;

    while(right < n){
        char ch = s[right];
        mp[ch]++;

        while(mp[ch] >= k){
            count = count + n-right;
            mp[s[left]]--;
            left++;
        }
        right++;
    }
    return count;
}

int main(){
    

    return 0;
}