#include<iostream>
#include<string>
using namespace std;

//time = O(n) space = O(n)
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
        else{
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