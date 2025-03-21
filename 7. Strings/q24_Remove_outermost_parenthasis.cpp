#include<iostream>
using namespace std;

//Leetcode 1021
//remove outermost parenthasis

//dryrun on given example to understand

//time = O(2n) inner loop execute overall n time during whole execution
//space = O(n) to store temp, in worst case it goes upto n
string removeOuterParentheses(string s) {
    int n = s.length();
    string ans = "";
    string temp = "";

    int open = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            open++;
            temp.push_back(s[i]);
        }
        else{
            open--;
            temp.push_back(s[i]);

            if(open == 0){
                int m = temp.length();
                for(int i=1; i<=m-2; i++){
                    ans.push_back(temp[i]);
                }
                temp = "";
            }
        }
    }
    return ans;
}

//time = O(n) space= O(1)
string removeOuterParentheses(string s) {
    int n = s.length();
    string ans = "";

    int open = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            if(open > 0){
                ans.push_back(s[i]);
            }
            open++;
        }
        else{
            open--;
            if(open > 0){
                ans.push_back(s[i]);
            }
        }

    }
    return ans;
}

int main(){
    return 0;
}