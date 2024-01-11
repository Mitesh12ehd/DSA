#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int>&arr , int x){
    int start = 0;
    int end = arr.size()-1;
    int ans = end;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] >= x){
            ans = mid;
            end = mid-1;
        }
        else if(x > arr[mid]){
            start = mid+1;
        }
    }
    return ans;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    //solution 1:two pointer approach Time=O(n-k) space=O(k)
    // int l=0;
    // int h=arr.size()-1;
    // while(h-l >= k){
    //     if(x-arr[l] > arr[h]-x){
    //         l++;
    //     }
    //     else{
    //         h--;
    //     }
    // }
    // vector<int> ans;
    // for(int i=l; i<=h; i++){
    //     ans.push_back(arr[i]);
    // }
    // return ans;

    //solution 2 Time=O(k) space=O(k)
    int h = lowerBound(arr,x);
    int l = h-1;
    while(k--){
        if(l<0){
            h++;
        }
        else if(h>=arr.size()){
            l--; 
        }
        else if( x-arr[l] > arr[h]-x){
            h++;
        }
        else{
            l--;
        }
    }
    vector<int> ans;
    for(int i=l+1; i<=h-1; i++){
        ans.push_back(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr{12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4;
    int x =35;
    vector<int> ans = findClosestElements(arr,k,x);
    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<" "; 
    }

    return 0;
}