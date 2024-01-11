#include<iostream>
using namespace std;

void findChar(string s,char ch,int i,int n,int& count){
    //base case
    if(i >= n){
        return;
    }
    //processing
    if(s[i] == ch){
        count++;
    }
    //recursive approach
    findChar(s,ch,i+1,n,count);
}

int main(){
    string s = "to chaliye suru krte h";
    char ch = ' ';
    int i=0;
    int n = s.length();

    int count = 0;
    findChar(s,ch,i,n,count);
    cout << count;

    return 0;
}