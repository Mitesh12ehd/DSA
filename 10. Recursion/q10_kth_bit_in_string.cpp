#include<iostream>
using namespace std;

//leetcode 1545
//find kth bit in nth binary string

string invert(string str){
    for(int i=0; i<str.length(); i++){
        if(str[i] == '0'){
            str[i] = '1';
        }
        else{
            str[i] = '0';
        }
    }
    return str;
}
string reverse(string str){
    int start = 0;
    int end = str.length()-1;
    while(start < end){
        swap(str[start],str[end]);
        start++,end--;
    }
    return str;
}
string helper(int n){
    if(n == 1){
        return "0";
    }

    string prev = helper(n-1);
    string Si = prev + "1" + reverse(invert(prev));
    return Si;
}
char findKthBit(int n, int k) {
    string Sn = helper(n);
    return Sn[k-1];
}

int main(){
    return 0;
}