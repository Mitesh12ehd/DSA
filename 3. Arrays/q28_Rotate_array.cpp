#include<iostream>
#include<vector>
using namespace std;

//method 1 create new array time = O(n) space = O(n)
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    if(k == 0){
        return;
    }
    
    int j = nums.size()-1;
    int freq = k-1;
    while(freq--){
        j--;
    }

    vector<int> ans;
    freq = k;
    while(freq--){
        ans.push_back(nums[j]);
        j++;
    }

    int i=0;
    freq = nums.size() - k;
    while(freq--){
        ans.push_back(nums[i]);
        i++;
    }

    nums.clear();
    for(auto it:ans){
        nums.push_back(it);
    }
}

//method 2 - time = O(n) space O(1)
void reverseArray(vector<int>& arr,int start,int end){
    while(start <= end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
    
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverseArray(nums,0,nums.size()-1);
    reverseArray(nums,0,k-1);
    reverseArray(nums,k,nums.size()-1);
}

int main(){
    

    return 0;
}