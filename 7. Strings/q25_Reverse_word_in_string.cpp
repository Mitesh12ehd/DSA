#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode 151
//Reverse the words in strings

//brute force time = O(2n) space = O(n)
//here we can store words in stack also 
string reverseWords(string s) {
    vector<string> words;
    int n = s.length();
    string temp = "";

    for(int i=0; i<n; i++){
        if(s[i] == ' ' and temp != ""){
            words.push_back(temp);
            temp = "";
        }
        else if(s[i] != ' '){
            temp.push_back(s[i]);
        }
    }
    if(temp != ""){
        words.push_back(temp);
    }

    string ans = "";
    for(int i=words.size()-1; i>=0; i--){
        ans = ans + words[i];
        if(i != 0){
            ans.push_back(' ');
        }
    }
    return ans;
}

//optimized time = O(n) space = O(1)
string reverseWords(string s) {
    int n = s.length();
    reverse(s.begin(),s.end());

    int i=0;
    int left = 0;
    int right = 0;

    while(i < n){
        while(i < n and s[i] == ' '){
            i++;
        }
        if(i == n){
            break;
        }
        while(i < n and s[i] != ' '){
            s[right] = s[i];
            right++,i++;
        }
        reverse(s.begin()+left,s.begin()+right);
        s[right] = ' ';
        right++;
        left = right;
        i++;
    }
    s.resize(right-1);
    return s;
}

int main(){
    return 0;
}