#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//leetcode 88
//merge two sorted array
//read notes

//brute force time = O(m+n) space = O(m+n)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<m && j<n){
        if(nums1[i] < nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else{
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i < m){
        ans.push_back(nums1[i]);
        i++;
    }
    while(j < n){
        ans.push_back(nums2[j]);
        j++;
    }
    nums1.clear();
    for(int i=0; i<ans.size(); i++){
        nums1.push_back(ans[i]);
    }
}

//optimal 1
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = 0;

    while(i>=0 && j<n){
        if(nums1[i] > nums2[j]){
            swap(nums1[i],nums2[j]);
            i--,j++;
        }
        else{
            break;
        }
    }
    sort(nums1.begin(),nums1.begin()+m);
    sort(nums2.begin(),nums2.end());
    int index = m;
    for(int x=0; x<n; x++){
        nums1[index] = nums2[x];
        index++;
    }
}

//optimal 2 will be gap method
//here intiution comes from shell short

int main(){
    return 0;
}