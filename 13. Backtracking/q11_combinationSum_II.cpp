#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//method 1 : memory exceeded
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
        combinationSumHelper(candidates,v,target-candidates[m],ans,m+1);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int i = 0;
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates,v,target,ans,i);

    //remove duplicates
    set<vector<int>> st;
    for(auto it:ans){
        sort(it.begin(),it.end());
        st.insert(it);
    }
    ans.clear();
    for(auto it:st){
        ans.push_back(it);
    }
    return ans;
}

//method 2, optimal submitted
//dry run on {2,5,2,1,2} target = 5
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
        if(m > i && candidates[m] == candidates[m-1]){
            //it skip duplicate element
            continue;
        }
        v.push_back(candidates[m]);
        combinationSumHelper(candidates,v,target-candidates[m],ans,m+1);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    int i = 0;
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates,v,target,ans,i);
    return ans;
}
int main(){
    vector<int> candidates{2,5,2,1,2};
    int target = 5;
    vector<vector<int>> ans = combinationSum2(candidates,target);
    for(auto it:ans){
        for(auto it1:it){
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}