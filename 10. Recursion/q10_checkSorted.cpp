#include<iostream>
using namespace std;

//iterative
// bool checkSorted(int arr[],int n){
//     for(int i=0; i<n-1; i++){
//         if(arr[i]>arr[i+1]){
//             return false;
//         }
//     }
//     return true;
// }

//recursive
bool checkSorted(int arr[],int n,int i){
    //base case
    if(i >= n-1){
        return true;
    }
    //processing
    if(arr[i]>arr[i+1]){
        return false;
    }
    //recursive approach
    checkSorted(arr,n,i+1);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 7;
    int i=0;
    cout << checkSorted(arr,n,i);

    return 0;
}