#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//refer next greater element question instead of notes

//brute force
vector<int> nextSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

//optimal approach
vector<int> nextSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }
        
        st.push(arr[i]);
    }
    return ans;
}



int main(){
    vector<int> arr = {2,1,5,6,2,3};
    vector<int> ans = nextSmaller(arr);

    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}