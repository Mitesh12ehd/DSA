#include<iostream>
#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    //total n-1 round
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j] > temp){
                //shift
                arr[j+1] = arr[j];
            }
            else{
                //stop
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        //here j+1 because when we exit the loop j decremented.
    }
}

int main(){
    vector<int> arr{6 ,2, 8 ,4 ,10};
    insertionSort(arr.size(),arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}