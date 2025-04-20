#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

//Leetcode 907
//sum of subarray minimums

//see notes

int MOD = 1000000007;

//brute force
int sumSubarrayMins(vector<int>& arr) {
    int ans = 0;
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        int mini = INT_MAX;
        for(int j=i; j<n; j++){
            mini = min(mini,arr[j]);
            ans = (ans+mini) % MOD;
        }
    }
    return ans;
}

//optimal approach
const int MOD = 1e9 + 7;
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
int sumSubarrayMins(vector<int>& arr) {
    int ans = 0;
    int n = arr.size();
    vector<int> nextSmall = nextSmaller(arr);
    vector<int> prevSmall = prevSmaller(arr);

    for(int i=0; i<n; i++){
        long long left = i - prevSmall[i];
        long long right = nextSmall[i] - i;
        long long contribution = (arr[i] * left % MOD) * right % MOD;
        ans = (ans + contribution) % MOD;
    }
    return ans;
}

int main(){
    return 0;
}