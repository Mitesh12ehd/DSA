#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

//brute force n^2
// int totalFruit(vector<int>& fruits) {
//     int n = fruits.size();
//     int maxlen = 0;

//     for(int i=0; i<n; i++){
//         set<int> st;
//         for(int j=i; j<n; j++){
//             st.insert(fruits[j]);
//             if(st.size() <= 2){
//                 maxlen = max(maxlen , j-i+1);
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     return maxlen;
// }

//two pointer sliding window hashmap
int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> mp; //<number,freq>

    int n = fruits.size();
    int left = 0;
    int right = 0;
    int maxlen = 0;

    while(right < n){
        mp[fruits[right]]++;

        while(mp.size() > 2){
            mp[fruits[left]]--;
            if(mp[fruits[left]] == 0){
                mp.erase(fruits[left]);
            }
            left++;
        }

        int len = right-left+1;
        maxlen = max(maxlen,len);
        right++;
    } 

    return maxlen;
}

int main(){
    return 0;
}