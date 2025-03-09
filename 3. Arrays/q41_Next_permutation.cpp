#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//permutation : rearragenment of all elements in any way
//total permutation : n!

//ex arr = [3,1,2]
//all permutation of given array is
// [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
// all are sorted in as per dictionary order
//here next permutation of [3,1,2] is [3,2,1]

//edge case : if given arr = [3,2,1]  ans is [1,2,3]

//brute force time = (n*n!) space = n!
//1.generate all permutation
//2.sort them
//3.ans is next permutation of given array

//stl
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
}

//optimal time = O(n)
//edge case: when we can't find element such that arr[i] < arr[i+1] 
//while iterating from last, then reverse the given array will be answer
void reverseArray(vector<int>& nums,int start,int end){
    while(start<end){
        swap(nums[start],nums[end]);
        start++,end--;
    }
}
void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    //find the break point
    int index = -1;
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }

    //if can't find breakpoint,given array is last permutaion
    if(index == -1){
        reverseArray(nums,0,n-1);
        return;
    }

    //find next greater elment than nums[index] ans swap it
    for(int i=n-1; i>index; i--){
        if(nums[i] > nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
    }

    //sort the remaining array
    reverseArray(nums,index+1,n-1);
}

int main(){
    

    return 0;
}