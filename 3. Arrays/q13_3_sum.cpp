#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//time = O(n^3 * log(number of unique triplets)) = O(N^3)
//space = O(n/3) = O(n) 
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;

    // we used set to store unique element

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

//read more solution from striver takeuforward

int main(){
    //leetcode 15
    vector<int> arr{0,0,0};

    return 0;
}