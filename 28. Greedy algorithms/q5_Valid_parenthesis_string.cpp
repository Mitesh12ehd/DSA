#include<iostream>
using namespace std;

//Leetcode 678
//Valid parenthisis string

//see notes

//brute force
bool helper(int index,string& s,int count){
    if(index >= s.length()){
        return count == 0;
    }
    if(count < 0){
        return false;
    }

    if(s[index] == '('){
        if(helper(index+1,s,count+1)){
            return true;
        }
    }
    else if(s[index] == ')'){
        if(helper(index+1,s,count-1)){
            return true;
        }
    }
    else{
        if(helper(index+1,s,count+1)){
            //* replace with (
            return true;
        }
        if(helper(index+1,s,count-1)){
            //* replace with ) 
            return true;
        }
        if(helper(index+1,s,count)){
            //* replace with empty char
            return true;
        }
    }
    return false;
}
bool checkValidString(string s) {
    return helper(0,s,0);
}

//better approach using dp
//time = O(n^2) see later

//optimal solution using greedy
bool checkValidString(string s) {
    int n = s.length();
    int min=0;
    int max=0;

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            min++;
            max++;
        }
        else if(s[i] == ')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }

        if(min < 0){
            min = 0;
        }
        if(max < 0){
            return false;
        }
    }

    return min == 0;
}

int main(){
    return 0;
}