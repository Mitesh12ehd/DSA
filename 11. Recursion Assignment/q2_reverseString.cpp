#include<iostream>
using namespace std;


//time O(n), space O(n)
void ReverseString(string& str,int start,int end){
    if(start >= end){
        return;
    }
    swap(str[start],str[end]);
    ReverseString(str,start+1,end-1);
}
int main(){
    string str = "mitesh";
    int start = 0;
    int end = str.length() - 1;
    ReverseString(str,start,end);
    cout << str;
    return 0;
}