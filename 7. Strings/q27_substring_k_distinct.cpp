#include<iostream>
#include<vector>
using namespace std;

//GFG
//substrings with k distinct

//brute force time = O(n^2) space = O(26)
int countSubstr(string& s, int k) {
    int n = s.length();
    int count = 0;

    for(int i=0; i<n; i++){
        int freq[26] = {0};
        int uniques = 0;
        for(int j=i; j<n; j++){
            if(freq[s[j] - 'a'] == 0){
                freq[s[j] - 'a']++;
                uniques++;
            }
            
            if(uniques == k){
                count++;
            }
        }
    }
    return count;
}

int countSubstr(string& s, int k) {
    int n = s.length();
    int left = 0;
    int right = 0;
    int freq[26] = {0};
    int uniques = 0;
    int ans = 0;

    while(right < n){
        if(freq[s[right] - 'a'] == 0){
            uniques++;
        }

        freq[s[right] - 'a']++;
        while(uniques > k){
            freq[s[left] - 'a']--;
            if(freq[s[left] - 'a'] == 0){
                uniques--;
            }
            left++;
        }

        if(uniques == k){
            ans = ans + (right-left+1);
        }

        right++;
    }

    return ans;
}

int main(){
    return 0;
}