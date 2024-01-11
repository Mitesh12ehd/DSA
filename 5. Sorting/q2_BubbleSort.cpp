#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bubbleSort(vector<int>& arr, int n){   
    //for n-1 round
    for(int i=1; i<n; i++){
        bool swapped = false;
        
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            //already sorted
            break;
        }
    }
}

int main(){
    vector<int> arr{6 ,2, 8 ,4 ,10};
    bubbleSort(arr,arr.size());
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}