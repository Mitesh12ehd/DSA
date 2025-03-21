#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Leetcode 14 
//Longest common prefix

string longestCommonPrefix(vector<string>& strs) {
    //outer while loop is itarate charater.
    //for loop iterate strs

    string ans;
    int i=0;
    while(true){
        char curr_ch = 0;
        for(int j=0; j<strs.size(); j++){
            //out of bound
            if( i >= strs[j].size()){
                curr_ch =0;
                break;
            }
            //just started checking
            if(curr_ch == 0){
                curr_ch = strs[j][i];
            }
            //if not match
            else if(strs[j][i] != curr_ch){
                curr_ch = 0;
                break;
            }
        }
        if(curr_ch == 0){
            break;
        }
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}

int main(){
    vector<string> arr{"flower","flow","flight"};
    cout << "Ans = " << longestCommonPrefix(arr);

    return 0;
}