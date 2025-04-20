#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//GFG
//Number of greater elements to the right

//see notes

//brute force
//time = O(queries * n) 
//space = O(1)
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    vector<int> ans;
    for(auto index:indices){
        int element = arr[index];
        int count = 0;
        for(int i=index+1; i<n; i++){
            if(arr[i] > element){
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

// optimal appraoch
// time = O(3n + queries) 
// space = O(2n)
// dryrun on it arr = {4, 5, 2, 10, 8} indices = {0, 1, 2, 3, 4} to understand

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    //write your code here
    stack<int>asc;
    stack<int>desc;
    vector<int>v(n, 0);

    for(int i=n-1; i>=0; i--){
        int ele=arr[i];
        while(!asc.empty() && ele>=asc.top()){
            desc.push(asc.top());
            asc.pop();
        }

        desc.push(ele);
        v[i]=asc.size();

        while(!desc.empty()){
            asc.push(desc.top());
            desc.pop();
        }        
    }

    vector<int>ans;
    for(int i=0;i<queries;i++){
        ans.push_back(v[indices[i]]);
    }
    return ans;
}

int main(){
    return 0;
}