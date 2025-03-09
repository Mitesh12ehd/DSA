#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//GFG
//Kth element of two arrays

//brute time = O(m+n) , space = O(m+n)
int kthElement(vector<int>& a, vector<int>& b, int k) {
    int m = a.size();
    int n = b.size();
    vector<int> arr;
    int i=0;
    int j=0;

    while(i<m && j<n){
        if(a[i] < b[j]){
            arr.push_back(a[i]);
            i++;
        }
        else{
            arr.push_back(b[j]);
            j++;
        }
    }
    while(i<m){
        arr.push_back(a[i]);
        i++;
    }
    while(j<n){
        arr.push_back(b[j]);
        j++;
    }
    return arr[k-1];
}

//better time = O(m+n) , space = O(1)
int kthElement(vector<int>& a, vector<int>& b, int k) {
    int m = a.size();
    int n = b.size();
    int i=0;
    int j=0;
    int count = 0;
    int element = -1;

    while(i<m && j<n){
        
        if(a[i] < b[j]){
            if(count == k-1) element = a[i];
            i++;
            count++;
        }
        else{
            if(count == k-1) element = b[j];
            j++;
            count++;
        }
    }
    while(i<m){
        if(count == k-1) element = a[i];
        i++;
        count++;
    }
    while(j<n){
        if(count == k-1) element = b[j];
        j++;
        count++;
    }
    return element;
}

//optimal 

//this approach will be same as optimal of median of two sorted arrays

//ex. a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 4

//left half size = k,  right size = total - k
//   [2,3]L1 | R1[6,7,9]
//   [1,4]L2 | R2[8,10]
//answer will be max(L1,L2)

//edge case
// ex. arr1 = [1,2,3,4,5,6] k=2
// so it not make sense to pick 6 elemens from array1
// so that end = min(k,m)

// ex. arr1 = 6 element
//     arr2 = 5 element k=7
//so we can't pick 0 element from array 1 and rest from array2
//so that start = max(0,k-n)

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int m = a.size();
    int n = b.size();
    
    //this condition ensure we have nums1 as first array
    if(m > n){
        return kthElement(b,a,k);
    }

    int start = max(0,k-n);
    int end = min(k,m);

    int leftSize = k;

    while(start <= end){
        int mid1 = (start + end) / 2;
        int mid2 = leftSize - mid1;

        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;

        if(mid1 - 1 >= 0){
            l1 = a[mid1 - 1];
        }
        if(mid2 - 1 >= 0){
            l2 = b[mid2 - 1];
        }
        if(mid1 < m){
            r1 = a[mid1];
        }
        if(mid2 < n){
            r2 = b[mid2];
        }

        //binary search conditions
        if(l1 <= r2 && l2 <= r1){
            //answer condition
            return max(l1,l2);
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