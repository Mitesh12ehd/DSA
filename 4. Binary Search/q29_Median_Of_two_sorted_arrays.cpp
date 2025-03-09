#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Leetcode 4
//Median of two sorted arrays
//see notes

//brute force
//time = O(m+n)  space = O(m+n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> arr;
    int i=0;
    int j=0;

    while(i<m && j<n){
        if(nums1[i] < nums2[j]){
            arr.push_back(nums1[i]);
            i++;
        }
        else{
            arr.push_back(nums2[j]);
            j++;
        }
    }
    while(i<m){
        arr.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        arr.push_back(nums2[j]);
        j++;
    }

    int total = m+n;
    if(total % 2 == 1){
        return (double)arr[total/2];
    }
    double ans = ((double)(arr[total/2] + arr[(total/2) -1])) / 2;
    return ans;
} 

//better approach
//time = O(m+n)  space = O(1)

//ex. arr1 = {1,3,4,7,10,12} arr2 = {2,3,6,15}
// {1,2,3,3,4,6,7,10,12,15}
//we actually don't need to store all element
//we only need 4 and 6

//dryrun to understand
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int total = m+n;

    int i=0;
    int j=0;
    int index1 = total/2;
    int index2 = (total/2) - 1;

    //keep track of index by considering whole array
    int count = 0;
    //both index to store index, using this we find answer
    int ele1 = -1;
    int ele2 = -1;

    while(i<m && j<n){
        if(nums1[i] < nums2[j]){
            if(count == index1) ele1 = nums1[i];
            if(count == index2) ele2 = nums1[i];
            count++;
            i++;
        }
        else{
            if(count == index1) ele1 = nums2[j];
            if(count == index2) ele2 = nums2[j];
            count++;
            j++;
        }
    }
    while(i<m){
        if(count == index1) ele1 = nums1[i];
        if(count == index2) ele2 = nums1[i];
        count++;
        i++;
    }
    while(j<n){
        if(count == index1) ele1 = nums2[j];
        if(count == index2) ele2 = nums2[j];
        count++;
        j++;
    }

    if(total % 2 == 1){
        return ele1;
    }
    return ((double)(ele1+ele2)) / 2.0;
} 

//optimal approach time = log(min(m,n))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    //this condition ensure we have nums1 as first array
    if(m > n){
        return findMedianSortedArrays(nums2,nums1);
    }

    int start = 0;
    int end = m;

    int leftSize = (m+n+1) / 2; 
                    // we have added +1 because it handle in total odd elements

    while(start <= end){
        int mid1 = (start + end) / 2;
        int mid2 = leftSize - mid1;

        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;

        if(mid1 - 1 >= 0){
            l1 = nums1[mid1 - 1];
        }
        if(mid2 - 1 >= 0){
            l2 = nums2[mid2 - 1];
        }
        if(mid1 < m){
            r1 = nums1[mid1];
        }
        if(mid2 < n){
            r2 = nums2[mid2];
        }

        //binary search conditions
        if(l1 <= r2 && l2 <= r1){
            //answer condition
            if((m+n) % 2 == 1){
                return max(l1,l2);
            }
            return (double)(max(l1,l2) + min(r1,r2))/2.0;
        }
        else if(l1 > r2){
            end = mid1 - 1;
        }
        else{
            start = mid1 + 1;
        }
    }

    return -1;
}

int main(){
    return 0;
}