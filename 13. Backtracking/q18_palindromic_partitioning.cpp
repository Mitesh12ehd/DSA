#include<iostream>
#include<vector>
using namespace std;

//Leetcode 131
//palindromic partitioning

//read book

//ex. "aabb" 
// ans = [[a,a,b,b],[aa,bb],[a,a,bb],[aa,b,b]]

bool isPalindrome(string& s,int start,int end){
    while(start<=end){
        if(s[start] != s[end]){
            return false;
        }
        start++,end--;
    }
    return false;
}
void helper(int index,vector<string>& path,vector<vector<string>>& ans,string& s){
    if(index == s.length()){
        ans.push_back(path);
        return;
    }

    for(int i=index; i<s.length(); i++){
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i+1));
            helper(i+1,path,ans,s);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    int index = 0;
    helper(index,path,ans,s);
    return ans;
}

int main(){
    return 0;
}