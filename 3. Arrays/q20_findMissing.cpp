#include<iostream>
#include<vector>
using namespace std;

void findMissing(vector<int>& arr){
    // method 1 --visiting || Time = o(n)
    for(int i=0; i<arr.size(); i++){
        int index = abs(arr[i]);

        //we take index-1 just to convert 1-indexed array
        if(arr[index - 1] > 0){
            arr[index - 1] = arr[index - 1] * (-1); 
        }
    }
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > 0){
            cout<<i+1<<" ";
        }
    }
 
    //method 2 --sorting and swapping  || Time o(n) , space o(1)
    //intitution : assume 1-indexed array, if we sort element to its position 
    //then we can easily find element
    //check all element and send to its right position

    // int i=0;
    // while(i<arr.size()){
    //     int index = arr[i]-1;
    //     if(arr[i] != arr[index]){
    //         swap(arr[i],arr[index]);
    //     }
    //     else{
    //         i++;
    //     }
    // }
    // for(int i=0; i<arr.size(); i++){
    //     if(arr[i] != i+1){
    //         cout<<i+1<<" ";
    //     }
    // }
}

int main(){
    vector<int> arr{1,3,5,3,4};
    findMissing(arr);

    return 0;
}