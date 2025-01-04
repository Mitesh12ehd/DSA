#include<iostream>
using namespace std;

//brute force n^2
// int characterReplacement(string s, int k) {
//     int n = s.length();

//     int maxlen = 0;
//     for(int i=0; i<n; i++){
//         int hash[26] = {0};
//         int maxfreq = 0;

//         for(int j=i; j<n; j++){
//             hash[s[j] - 'A']++;
//             maxfreq = max(maxfreq,hash[s[j] - 'A']);
                
//             //here j-i+1 denote length
//             int numOfChanges = (j-i+1) - maxfreq;

//             if(numOfChanges <= k){
//                 maxlen = max(maxlen,j-i+1);
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     return maxlen;
// }

//optimizied O(n)  time complexity = 26(n+n) space = O(26)
int characterReplacement(string s, int k) {
    int n = s.length();

    int maxlen = 0;
    int maxfreq = 0;
    int left = 0;
    int right = 0;
    int hash[26] = {0};

    while(right < n){
        hash[s[right] - 'A']++;
        maxfreq = max(maxfreq,hash[s[right] - 'A']);

        while((right-left+1) - maxfreq > k){
            hash[s[left] - 'A']--;

            //update max freqency
            maxfreq = 0;
            for(int i=0; i<26; i++){
                maxfreq  = max(maxfreq,hash[i]);
            }
            left++;
        }

        //now at this point (length - mexfreq <= k) become true
        maxlen = max(maxlen, right-left+1);
        right++;
    }
    return maxlen;
}

//time = O(n+n)
// int characterReplacement(string s, int k) {
//     int n = s.length();

//     int maxlen = 0;
//     int maxfreq = 0;
//     int left = 0;
//     int right = 0;
//     int hash[26] = {0};

//     while(right < n){
//         hash[s[right] - 'A']++;
//         maxfreq = max(maxfreq,hash[s[right] - 'A']);

//         while((right-left+1) - maxfreq > k){
//             hash[s[left] - 'A']--;
//             left++;
//         }

//         //now at this point (length - mexfreq <= k) become true
//         maxlen = max(maxlen, right-left+1);
//         right++;
//     }
//     return maxlen;
// }

//time = O(n)
// int characterReplacement(string s, int k) {
//     int n = s.length();

//     int maxlen = 0;
//     int maxfreq = 0;
//     int left = 0;
//     int right = 0;
//     int hash[26] = {0};

//     while(right < n){
//         hash[s[right] - 'A']++;
//         maxfreq = max(maxfreq,hash[s[right] - 'A']);

//         if((right-left+1) - maxfreq > k){
//             hash[s[left] - 'A']--;
//             left++;
//         }

//         //now at this point (length - mexfreq <= k) become true
//         maxlen = max(maxlen, right-left+1);
//         right++;
//     }
//     return maxlen;
// }

int main(){
    string s = "AABABBA";
    int k = 2;
    cout << characterReplacement(s,k);
    return 0;
}