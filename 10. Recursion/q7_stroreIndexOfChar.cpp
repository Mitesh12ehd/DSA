#include<iostream>
#include<vector>
using namespace std;

void checkkey(string str,int n,int i,int key, vector<int>& ans){
    //base condition
    if(i >= n){
        return;
    }
    //processing
    if(str[i] == key){
        ans.push_back(i);
    }
    //base condition
    checkkey(str,n,i+1,key,ans);
}

int main(){
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';
    int i = 0;
    vector<int> ans;

    checkkey(str,n,i,key,ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}