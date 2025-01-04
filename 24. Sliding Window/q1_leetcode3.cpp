#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//longest substring without repeating chracter

//brute force 1 : time=O(n^3)
// bool noRepeatedChar(string& s,int& i,int& j){
//     int arr[256] = {0};
//     for(int m=i; m<=j; m++){
//         char ch = s[m];
//         if(arr[ch] >=1){
//             return false;
//         }
//         arr[ch]++;
//     }
//     return true;
// }
// int lengthOfLongestSubstring(string& s) {
//     int n = s.length();
//     string ans = "";

//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             if(noRepeatedChar(s,i,j)){
//                 string newStr = s.substr(i,j-i+1);
//                 if(newStr.length() > ans.length()){
//                     ans = newStr;
//                 }
//             }
//         }
//     }

//     return ans.length();
// }

//brute force 2 : time=O(N^2) : space = O(256) = O(1)
// int lengthOfLongestSubstring(string s) {
//     int n = s.length();
//     int ans = 0;

//     for(int i=0; i<n; i++){
//         int hash[256] = {0};
//         for(int j=i; j<n; j++){
//             if(hash[s[j]] == 1){
//                 break;
//             }

//             int len = j-i+1;
//             ans = max(ans,len);
//             hash[s[j]] = 1;
//         }
//     }
//     return ans;
// }

//sliding window
int lengthOfLongestSubstring(string s) {
    if(s.length() == 0){
        return 0;
    }

    vector<int> hash(256,-1); //map of <char,index>
    int left=0; 
    int right=0;
    int n = s.length();
    int maxlen = 1;

    while(right < n){
        if(hash[s[right]] != -1 && hash[s[right]] >= left){
            //repeated case
            left = hash[s[right]] + 1;
        }

        hash[s[right]] = right;
        int len = right-left+1;
        if(len > maxlen){
            maxlen = len;
            cout << "maxlen changed";
        }
        right++;
    }
    return maxlen;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);

    return 0;
}