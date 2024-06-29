#include<iostream>
#include<vector>
using namespace std;

void sort0and1(vector<int>& arr){
    int start = 0;
    int end = arr.size() - 1;

    while(start < end){
        if(arr[start] == 0){
            start++;
        }
        else if(arr[end] == 1){
            end--;
        }
        else{
            swap(arr[start],arr[end]);
        }
    }
}

int main(){
    vector<int> arr{0,1,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0};
    sort0and1(arr);
    
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}