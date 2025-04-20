#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Leetcode 503
//Next greater element II

//brute force
//time = O(n^2) space = O(1)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,-1);

    for(int i=0; i<n; i++){
        bool found = false;
        for(int j=i+1; j<n; j++){
            if(nums[j] > nums[i]){
                ans[i] = ans[j];
                found = true;
                break;
            }
        }

        if(!found){
            for(int j=0; j<i; j++){
                if(nums[j] > nums[i]){
                    ans[i] = ans[j];
                    break;
                }
            }
        }
    }
    return ans;
}

//just better approach to understand optimal approach later
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,-1);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<=i+n-1; j++){
            int index = j % n;
            if(nums[index] > nums[i]){
                ans[i] = nums[index];
                break;
            }
        }
    }
    return ans;
}

//optimal approach
//time = O(n) space = O(n)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=2*n-1; i>=0; i--){
        while(!st.empty() && st.top() <= nums[i % n]){
            st.pop();
        }
        
        if(i<n && !st.empty()){
            ans[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return ans;
}

int main(){
    return 0;
}