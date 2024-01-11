#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool checkPalindrome(string &s,int start ,int end){
    while(start<=end){
        if(s[start] != s[end]){
            return false;
        }
        else{
            start++,end--;
        }
    }
    return true;
}
int expand_Around_Index(string s,int left,int right){
    int count = 0;
    while( left>=0  &&  right<s.length()  &&  s[left] == s[right]){
        count++;
        left--;
        right++;
    }
    return count;
}
int countSubstrings(string s){
    //method 1  Time=O(n^3) Space=O(n)
    int count = 0;
    for(int i=0; i<s.length(); i++){
        for(int j=i; j<s.length(); j++){
            if(checkPalindrome(s,i,j)){
                count++;
            }
        }
    }
    return count;


    //method 2  odd and even  Time=O(n^2)
    // int totalCount = 0;
    // int n = s.length();

    // for(int center=0; center<n; center++){
    //     //odd
    //     int oddKaAns = expand_Around_Index(s,center,center);
    //     totalCount = totalCount + oddKaAns;
    //     //even
    //     int evenKaAns = expand_Around_Index(s,center,center+1);
    //     totalCount = totalCount + evenKaAns;
    // }
    // return totalCount;
}

int main(){
    string s = "abc";
    int ans = countSubstrings(s);
    cout<<ans;
    return 0;
}