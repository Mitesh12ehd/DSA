#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//watch striver video to understand

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
// time = O(2^n * k) k = average lenegth of combination
// why? because we apply exclusion inclusion pattern
//                    so that we make 2 calls overall for one element

//why it is not n^n
//1. here when we make call we pass m+1 
//      if we pass m,then it become n^n
 
//And remember one point : 
//when array is distinict : number of subsequence generate is 2^n
//subsequence doesn't contain same element twice.


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
        //those two condition are optimization
        if(m > i && candidates[m] == candidates[m-1]){
            //it skip duplicate element,

            //explaination : in loops if we can't reach target for one element
            //then for same element at next index in array we also can't reach
            //so that skiping next element optimize little bit
            
            //why next element not skipped overall?
            //because if consider current element then make recursive call
            //then it consider next element
            //but it doesn't call again for same element
            
            //point:
            //here we apply exclusion - inclustion using loop
            //if we incluse then we make recursive call
            //      then it consider next element even if it is duplicate
            //if we exclude one element then we move to m++
            //next element 
            //now again exclusion and inclusion apply for next element also

            //and using this condition we ensure no duplicates in answer
            //so we don't need to use set that takes also extra time and space

            continue;
        }
        if(candidates[i] > target){
            break;
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