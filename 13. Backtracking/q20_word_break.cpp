#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Leetcode 139
//Word break

//time = m^n
//space = O(n)
bool helper(string str,string& s,vector<string>& wordDist){
    for(int i=0; i<wordDist.size(); i++){
        if(str+wordDist[i] == s){
            return true;
        }
        
        if(str.length() < s.length()){
            if(helper(str+wordDist[i],s,wordDist)){
                return true;
            }
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    string str = "";
    return helper(str,s,wordDict);
}


bool wordBreak(string s, vector<string>& wordDict) {
    set<string> st;
    for(auto it:wordDict){
        st.insert(it);
    }

    int startIndex = 0;
    for(int i=0; i<s.length(); i++){
        if(st.find(s.substr(startIndex,i-startIndex+1)) != st.end()){
            startIndex = i+1;
        }
    }

    if(st.find(s.substr(startIndex,s.length()-startIndex)) != st.end()){
        return true;
    }
    return false;
}

int main(){
    return 0;
}