#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool mycomparator(string a,string b){
    string t1 = a+b;
    string t2 = b+a;
    return t1>t2;
}
string largestNumber(vector<int>&nums){
    vector<string> snums;
    for(int i=0; i<nums.size(); i++){
        snums.push_back(to_string(nums[i]));
    }

    sort(snums.begin(),snums.end() , mycomparator);
    if(snums[0] == "0"){ 
        return "0";
    }

    string ans="";
    for(int i=0; i<snums.size(); i++){
        ans = ans + snums[i];
    }
    return ans;
}
int main(){
    //leetcode 179
    vector<int> nums{3,30,34,5,9};
    cout << largestNumber(nums);
    return 0;
}