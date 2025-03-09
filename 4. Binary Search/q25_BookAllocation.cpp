#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//GfG allocate minimum pages

//This is similar problem to below two problems
//1. painter partition (gfg)
//2. split array largest sum (leetcode 410)

/*
------------------Question explaination----------------------

arr[] = [10,20,30,40] k=2

we can divide arr like this 

[10] [20,30,40] maximum subarray sum = 90
[10,20] [30,40] maximum subarray sum = 70
[10,20,30] [40] maximum subarray sum = 60
ans = 60
*/

/*
------------------Approach----------------------
arr = [25,46,28,49,24] k=4

start = maximum of array,  because if start is less than maximum then
                          book with maximum pages can't be allocated to any students

end = sum of all elements of array
    reason : because if we have k=1 for same array
    then answer is sum of all elements

1. first check if ans can be 49
    first student allocate first book  page=25
        first student try to allocate second book with page = 46,
        can't be allocate because totalpages exceed ans=49
    
    second student allocate second book page = 46
        second student try to allocate third book with page = 28,
        can't be allocate because totalpages exceed ans=49

    third student allocate third book page = 28
        third student try to allocate fourth book with page = 49,
        can't be allocate because totalpages exceed ans=49

    fourth student allocate fourth book page = 49
        fourth student try to allocate fifth book with page = 24,
        can't be allocate because totalpages exceed ans=49

    now students is over and fifth book yet to allocate so that
    answer can't be 49

    we try to increase answer = 50 check if it possible or not
*/

bool isPossibleSolution(vector<int>& arr,int answer,int k){
    int pageSum = 0;
    int student = 1;

    for(int i=0; i<arr.size(); i++){
        if(pageSum + arr[i] > answer){
            student++;
            pageSum = 0;
            pageSum = pageSum + arr[i];

            if(student > k){
                return false;
            }
        }
        else{
            pageSum = pageSum + arr[i];
        }
    }
    return true;
}

//brute force
int findPages(vector<int> &arr, int k) {
    if(arr.size() < k){
        return -1;
    }

    int start = INT_MIN;
    int end = 0;
    for(auto it:arr){
        start = max(start,it);
        end = end + it;
    }

    for(int i=start; i<=end; i++){
        if(isPossibleSolution(arr,i,k)){
            return i;
        }
    }
    return -1;
}

//optimal
int findPages(vector<int> &arr, int k) {
    if(arr.size() < k){
        return -1;
    }

    int start = INT_MIN;
    int end = 0;
    for(auto it:arr){
        start = max(start,it);
        end = end + it;
    }

    int ans = -1;
    while(start<=end){
        int mid = (start+end) / 2;
        if(isPossibleSolution(arr,mid,k)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    return 0;
}