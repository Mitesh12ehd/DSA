#include<iostream>
using namespace std;

bool checkkey(string str,int n,int i,int key){
    //base condition
    if(i >= n){
        return false;
    }
    //processing
    if(str[i] == key){
        return true;
    }
    //recursive approach
    return checkkey(str,n,i+1,key);
}

int main(){
    string str = "mitesh";
    int n = str.length();

    char key = 'z';
    int i = 0;

    bool ans = checkkey(str,n,i,key);
    cout << ans;

    return 0;
}