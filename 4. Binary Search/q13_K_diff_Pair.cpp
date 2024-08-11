#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int binarySearch(vector<int> &nums,int start,int key){
    int end = nums.size()-1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(nums[mid] == key){
            return mid;
        }
        else if(key>nums[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int findPairs(vector<int>& nums, int k) {
    //solution 1 --two pointer approach
    // sort(nums.begin(),nums.end());

    // int i=0;
    // int j=1;
    // set<pair<int,int>> ans; //pair data structure store pair.
    //                         //set data structure is used to avoid duplicate.

    // while(j < nums.size()){
    //     int diffrence = nums[j] - nums[i];
    //     if(diffrence == k ){
    //         ans.insert({nums[i],nums[j]});
    //         i++,j++;
    //     }
    //     else if(diffrence > k){
    //         i++;
    //     }
    //     else{
    //         j++;
    //     }

    //     if(i == j){ //same index element are avoided
    //         j++;
    //     }
    // }
    // return ans.size();

    //solution 2 -- bianry search approach
    sort(nums.begin(),nums.end());
    set<pair<int,int>> ans; //pair data structure store pair.
                            //set data structure is used to avoid duplicate.

    for(int i=0; i<nums.size(); i++){
        if(binarySearch(nums, i+1, nums[i]+k) != -1){
            ans.insert( {nums[i] , nums[i]+k} );
        }
    }
    return ans.size();
}

//brute force method using two for loop and set to store ans
//time = O(n^2 * logn)

int main(){
    vector<int> nums{3,1,4,1,5};
    int k = 2;
    int count = findPairs(nums,k);
    cout<<count;

    return 0;
}