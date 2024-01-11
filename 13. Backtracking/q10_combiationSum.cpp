#include<iostream>
#include<vector>
using namespace std;
void combinationSumHelper(vector<int>& candidates,vector<int>& v,int target,
                        vector<vector<int>>& ans,int i)
{
    //base case
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0){
        return;
    }

    for(int m=i; m<candidates.size(); m++){
        v.push_back(candidates[m]);
        combinationSumHelper(candidates,v,target-candidates[m],ans,m);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int i = 0;
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates,v,target,ans,i);
    return ans;
}
int main(){
    vector<int> candidates{2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates,target);
    for(auto it:ans){
        for(auto it1:it){
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}