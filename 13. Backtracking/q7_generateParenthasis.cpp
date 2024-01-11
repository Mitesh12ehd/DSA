#include<iostream>
#include<vector>
using namespace std;

void solveProblem(vector<string>& ans,int open,int close,string& output){
    //base case
    if(open==0 && close==0){
        ans.push_back(output);
        return;
    }

    //include open bracket
    if(open > 0){
        output.push_back('(');
        solveProblem(ans,open-1,close,output);
        //backtrack
        output.pop_back();
    }

    //include close bracket
    if(close > open){
        output.push_back(')');
        solveProblem(ans,open,close-1,output);
        //backtrack
        output.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int open = n;
    int close = n;
    string output = "";
    solveProblem(ans,open,close,output);
    return ans;
}
int main(){
    int n = 2;
    vector<string> ans = generateParenthesis(n);
    for(auto it:ans){
        cout << it << endl;
    }
    return 0;
}