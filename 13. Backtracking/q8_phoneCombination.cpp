#include<iostream>
#include<vector>
using namespace std;
void solveProblem(vector<string>& ans,int i,string& output,
            vector<string>& mapping,string& digits)
{
    //base case
    if(i >= digits.length()){
        ans.push_back(output);
        return;
    }

    int digit = digits[i] - '0';
    string value = mapping[digit];
    for(int m=0; m<value.length(); m++){
        char ch = value[m];
        output.push_back(ch);
        //recursive call
        solveProblem(ans,i+1,output,mapping,digits);
        //backtrack
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    int i=0;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    if(digits.size() == 0){
        return ans;
    }

    solveProblem(ans,i,output,mapping,digits);
    return ans;
}
int main(){
    string digit = "23";
    vector<string> ans = letterCombinations(digit);
    for(auto it:ans){
        cout << it << endl;
    }
    return 0;
}