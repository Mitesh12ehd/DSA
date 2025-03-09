#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;

//read notes
//leetcode 15
//3Sum

//brute force
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    for(int i=0; i<nums.size(); i++){
        for(int j= i+1; j<nums.size(); j++){
            for(int k= j+1; k<nums.size(); k++){
                if(nums[i] + nums[j] +nums[k] == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    //take all element from set
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//better approach time = n^2 log m,  
//space = O(n) for hashSet
//here we apply hashing to find third element
//we don't calculate space that used to store answer
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;
    
    for(int i=0; i<n; i++){
        set<int> hashSet;
        for(int j=i+1; j<n; j++){
            int third = -(nums[i] + nums[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


//optimal space approach,  sorting and pointers approach
//[-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2]
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i=0; i<n; i++){
        if(i != 0 && nums[i] == nums[i-1]){
            //if new element at index i is same as previous avoid it
            continue;
        }

        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]){
                    j++;
                }
                while(j<k && nums[k] == nums[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
}

int main(){
    //leetcode 15
    vector<int> arr{0,0,0};

    return 0;
}