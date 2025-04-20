#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

//Leetcode 2104
//Sum of subarray ranges

//optimal approach
//first solve sum of subarray minimum 
//second solve sum of subarray maximum
//ans = sum of subarray maximum - sum of subarray minimum

//note : apply change in nextGreater and prevGreater as
//we had done in nextSmaller and prevSmaller

vector<int> nextSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,n);
    stack<int> st;
    
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> nextGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,n);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> prevGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long sumMinimum = 0;
    long long sumMaximum = 0;

    vector<int> nextSmall = nextSmaller(nums);
    vector<int> prevSmall = prevSmaller(nums);
    vector<int> nextGreat = nextGreater(nums);
    vector<int> prevGreat = prevGreater(nums);

    for(int i=0; i<n; i++){
        sumMinimum = sumMinimum + ((i - prevSmall[i]) * (nextSmall[i] - i) * nums[i]);
        sumMaximum = sumMaximum + ((i - prevGreat[i]) * (nextGreat[i] - i) * nums[i]);
    }

    return sumMaximum - sumMinimum;
}

int main(){
    return 0;
}