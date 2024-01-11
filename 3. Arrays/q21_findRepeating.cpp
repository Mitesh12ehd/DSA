#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int firstRepeated(vector<int> arr, int n) {
    // method 1 --nested for loop -- Time O(n^2) -- space o(n)
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(arr[i] == arr[j+1]){
    //             return i+1;
    //         }
    //     }
    // }
    // return -1;

    //method 2 --optimized
    // unordered_map<int,int> hash;
    // for(int i=0; i<n; i++){
    //     hash[arr[i]]++;
    // }
    // for(int i=0; i<n; i++){
    //     if(hash[arr[i]] > 1){
    //         return i+1;
    //     }
    // }
    // return -1;
}
int main(){
    vector<int> arr{1, 5, 3, 4, 3, 5, 6};
    int n = arr.size();
    int index = firstRepeated(arr,n);
    cout<<"fist repeated at index = "<<index;

    return 0;
}