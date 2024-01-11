#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string s) {
    string newstr;
    for(int i=0; i<s.length(); i++){
        if(newstr.length() > 0){
            if(newstr[newstr.length() - 1] != s[i]){
                newstr.push_back(s[i]);
            }
            else{
                newstr.pop_back();
            }
        }
        else{//this case only for i=0 first character
            newstr.push_back(s[i]);
        }
    }
    return newstr;
}
int main(){
    string s = "abbaca";
    cout << removeDuplicates(s);
    
    return 0;
}