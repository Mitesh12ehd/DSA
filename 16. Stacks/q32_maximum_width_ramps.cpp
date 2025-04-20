#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//brute force
// int maxWidthRamp(vector<int>& nums) {
//     int ans = 0;
//     int n = nums.size();
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(nums[i] <= nums[j]){
//                 ans = max(ans,j-i);
//             }
//         }
//     }
//     return ans;
// }

//optimal
int maxWidthRamp(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();

    for(int i=0; i<n; i++){
        if(st.empty() || nums[st.top()] > nums[i]){
            st.push(i);
        }
    }
    int maxwidth = 0;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && nums[st.top()] <= nums[i]){
            maxwidth = max(maxwidth, i - st.top());
            st.pop();
        }
    }

    return maxwidth;
}


int main(){
    return 0;
}