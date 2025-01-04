#include<iostream>
#include<vector>
using namespace std;

//brute force n^2
// int longestOnes(vector<int>& nums, int k) { 
//     int maxlen = 0;
//     int n = nums.size();

//     for(int i=0; i<n; i++){
//         int zeros = 0;
//         for(int j=i; j<n; j++){
//             if(nums[j] == 0){
//                 zeros++;
//             }

//             if(zeros <= k){
//                 int len = j - i + 1;
//                 maxlen = max(len,maxlen);
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     return maxlen;
// }

//two pointer sliding window
int longestOnes(vector<int>& nums, int k) { 
    int maxlen = 0;
    int n = nums.size();
    int zeros = 0;

    int left = 0,right = 0;
    while(right < n){
        if(nums[right] == 0){
            zeros++;
        }

        //move left pointer because zeros are exiceeding k
        //move untill we get zeros <= k
        while(zeros > k){
            if(nums[left] == 0){
                zeros--;
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