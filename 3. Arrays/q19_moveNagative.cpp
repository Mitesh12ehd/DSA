#include<iostream>
#include<vector>
using namespace std;

void moveNagative(vector<int>& arr){

    //Time complexity = o(n)
    //space complexity = o(1)

    int l = 0;
    int h = arr.size() -1;

    while(l<h){
        if(arr[l]<0){
            l++;
        }
        else if(arr[h]>0){
            h--;
        }
        else{
            swap(arr[l],arr[h]);
        }
    }

    //this also works - one pointer approach
    // int start = 0;
    // for(int i=0; i<arr.size(); i++){
    //     if(arr[i] < 0){
    //         swap(arr[start],arr[i]);
    //         start++;
    //     }
    // }
}

int main(){
    vector<int> arr{1,2,-3,4,-5,6};
    moveNagative(arr);
    for(int i=0 ; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}