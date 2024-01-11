#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr{0,1,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0};

    int l = 0;
    int h = arr.size() -1;

    while(l<h){
        if(arr[l]==0){
            l++;
        }
        else if(arr[h]==1){
            h--;
        }
        else{
            swap(arr[l],arr[h]);
        }
    }

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}