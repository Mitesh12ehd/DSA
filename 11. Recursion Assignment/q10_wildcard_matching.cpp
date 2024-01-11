#include<iostream>
using namespace std;

//time O(2^n) , space O(n)
bool solveProblem(string& s,int si,string& p,int pi){
    //base case
    if(si == s.size() && pi == p.size()){
        return true;
    }

    //special base case when pi left *** return true, **f it return false
    if(si == s.size() && pi < p.size()){
        while(pi < p.size()){
            if(p[pi] != '*'){
                return false;
            }
            pi++;
        }
        return true;
    }

    //single charater matching
    if(s[si] == p[pi] || p[pi] == '?'){
        return solveProblem(s, si+1, p, pi+1);
    }
    if(p[pi] == '*'){
        //treat * has null or empty
        bool caseA = solveProblem(s, si, p, pi+1);

        //let * consume 1 letter
        bool caseB = solveProblem(s, si+1, p, pi);

        return caseA || caseB;
    }

    //char does not match
    return false;
}
bool isMatch(string s, string p) {
    int si = 0;
    int pi = 0;
    return solveProblem(s,si,p,pi);
}
int main(){
    //leetcode 44
    string s = "abcdefg";
    string p = "ab*fg";
    cout << isMatch(s,p);
    return 0;
}