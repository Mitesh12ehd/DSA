#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr1{1,3,3,5,7};
    vector<int> arr2{2,4,6,1,7,3,3};
    vector<int> ans;

    for(int i=0; i<arr1.size(); i++){
        int element = arr1[i];
        for(int j=0; j<arr2.size(); j++){
            if (element == arr2[j])
            {
                //mark element as visited, to avoide print 3 four timess
                arr2[j] = -1;

                ans.push_back(element);
            }
            
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}