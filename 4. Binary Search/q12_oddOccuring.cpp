#include<iostream>
#include<vector>
using namespace std;

// similar question leetcode 540 single element in array

int findOddOccure(vector<int> arr){
    int start = 0; 
    int end = arr.size() - 1;
    int mid = start + (end-start)/2;
    
    while(start <= end){
        if( start == end){
            return start;
        }
        if(mid % 2 == 0) {
            if(arr[mid] == arr[mid+1]){
                //we are stading in left part,ans is in right part so, search right
                start = mid + 2;
            }
            else{
                //we are stading in right ,search left
                end = mid;
            }
        }
        else{
            if(arr[mid] == arr[mid-1]){
                //we are stading in left part,ans is in right part so, search right
                start = mid + 1;
            }
            else{
                //we are stading in right ,search left
                end = mid - 1;
            }
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){

    vector<int> arr{1,1,2,2,3,3,4,4,3,600,600,4,4};
    int ans = findOddOccure(arr);
    cout<<arr[ans];
    return 0;
}