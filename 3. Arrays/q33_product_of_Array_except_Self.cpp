#include<iostream>
#include<vector>
using namespace std;

//method 1 : brute force time = O(n^2) space = O(1)
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(),0);

    for(int i=0; i<nums.size(); i++){
        int product = 1;
        for(int j=0; j<nums.size(); j++){
            if(i == j){
                continue;
            }

            product = product * nums[j];
        }

        ans[i] = product;
    }

    return ans;
}

//method 2 : prefix-postfix time = O(n) space = O(n)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> prefix(n,0);
    prefix[0] = 1;
    int prefixVar = nums[0];
    for(int i=1; i<n; i++){
        prefix[i] = prefixVar;
        prefixVar = prefixVar * nums[i];
    }

    vector<int> postfix(n,0);
    postfix[n-1] = 1;
    int postfixVar = nums[n-1];
    for(int i=n-2; i>=0; i--){
        postfix[i] = postfixVar;
        postfixVar = postfixVar* nums[i];
    }

    vector<int> ans(n,0);
    for(int i=0; i<n; i++){
        ans[i] = prefix[i] * postfix[i];
    }
    return ans;
}

//method 3 by calculate prefix and suffix directly in ans array 
//time=O(n) space=O(1)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n,1);

    int curr = 1;
    for(int i=0; i<n; i++){
        ans[i] = ans[i] * curr;
        curr = curr * nums[i];
    }

    curr = 1;
    for(int i=n-1; i>=0; i--){
        ans[i] = ans[i] * curr;
        curr = curr * nums[i];
    }
    
    return ans;
}

int main(){
    

    return 0;
}