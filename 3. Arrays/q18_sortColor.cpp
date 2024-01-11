#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sortColors(vector<int>& nums) {

    //method 1 --using sort function
    // sort(nums.begin(),nums.end());

    //method 2 --by counting and override
    // int zeros = 0;
    // int ones = 0;
    // int twos = 0;
    // for(int i=0; i<nums.size(); i++){
    //     if(nums[i] == 0){
    //         zeros++;
    //     }
    //     else if(nums[i] == 1){
    //         ones++;
    //     }
    //     else{
    //         twos++;
    //     }
    // }
    // int i=0;
    // while(zeros--){
    //     nums[i] =0;
    //     i++;
    // }
    // while(ones--){
    //     nums[i] =1;
    //     i++;
    // }
    // while(twos--){
    //     nums[i] =2;
    //     i++;
    // }

    //method 3 --in place,3 pointer approach
    int l=0,m=0,h=nums.size()-1;
    while(m<=h){
        if(nums[m] == 0){
            swap(nums[l],nums[m]);
            l++;
            m++;
        }
        else if(nums[m] == 1){
            m++;
        }
        else{
            swap(nums[m],nums[h]);
            h--;
        }
    }
}

int main(){
    vector<int> arr{0,1,2,0,1,2,2,0,0,0,0,0,0,1,1,1,1,1,2,2,0,0};
    sortColors(arr);
    for(int i=0 ; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}