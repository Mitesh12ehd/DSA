#include<iostream>
#include<set>
using namespace std;

//split a string into max number of unique substring

void helper(string& s,set<string>& st,int& ans,int i){
    //base case
    if(i >= s.length()){
        int size = st.size();
        ans = max(ans,size);
        return;
    }

    for(int m=1; m<=s.length()-i; m++){
        string temp = s.substr(i,m);
        if(st.find(temp) == st.end()){
            //value not found in set
            st.insert(temp);
            helper(s,st,ans,m+i);
            st.erase(temp);
        }
    }
}
int maxUniqueSplit(string s) {
    int ans = 0;
    set<string> st;
    helper(s,st,ans,0);
    return ans;
}

int main(){
    return 0;
}