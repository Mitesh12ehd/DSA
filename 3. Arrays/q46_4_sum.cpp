#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//leetcode 18
//4 Sum

//naive, time=O(N^4) , space=O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    long long sum = nums[i] + nums[j];
                    sum = sum + nums[k];
                    sum = sum + nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//better approach 
//apply hashing to find fourth element
//time = n^3
//space = n
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<long long> hashSet;
            for(int k=j+1; k<n; k++){
                long long sum = nums[i] + nums[j];
                sum = sum + nums[k];
                long long fourth = target - sum;

                if(hashSet.find(fourth) != hashSet.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


//optimal approach
//two pointer and sorting
//time = O(n^3)
//space = O(1) no space to find answer
//this approach similar to optimal approach of 3sum
//here we fix two pointer i and j and apply two pointer on k and l
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        if(i != 0 && nums[i] == nums[i-1]){
            continue;
        } 
        for(int j=i+1; j<n; j++){
            if(j != i+1 && nums[j] == nums[j-1]){
                continue;
            }
            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = nums[i] + nums[j];
                sum = sum + nums[k];
                sum = sum + nums[l];

                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++,l--;
                    
                    while(k<l && nums[k] == nums[k-1]){
                        k++;
                    }
                    while(k<l && nums[l] == nums[l+1]){
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}