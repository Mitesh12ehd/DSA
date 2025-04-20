#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//see notes

//brute force 
//time = O(n^2) space = O(1)
vector<int> nextGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

//optimal 
//time = O(2n) space = O(n)
//stack can store at most n elements and we can pop out n element during whole
//iteration so inner while loop take overall n time

vector<int> nextGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i]){
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
    return 0;
}