#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    vector<int> arr1{1,3,5,7};
    vector<int> arr2{2,4,6,3};
    vector<int> ans;

    //to avoid duplicate element
    for(int i=0; i<arr1.size(); i++){
        int element = arr1[i];
        for(int j=0; j<arr2.size(); j++){
            if (element == arr2[j]){
                arr2[j] = -1;
            }
            
        }
    }

    
    for(int i=0; i<arr1.size(); i++){
        ans.push_back(arr1[i]);
    }
    for(int i=0; i<arr2.size(); i++){
        if(arr2[i] != -1){
            ans.push_back(arr2[i]);
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}