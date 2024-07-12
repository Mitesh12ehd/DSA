#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> mp;
    for(int i=0; i<strs.size(); i++){
        string s = strs[i];
        sort(s.begin(),s.end());
        mp[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(auto i=mp.begin(); i!=mp.end(); i++){
        ans.push_back(i -> second);
    }
    return ans;

    //method 2 exist
}
int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}