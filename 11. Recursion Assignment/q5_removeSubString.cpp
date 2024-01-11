#include<iostream>
using namespace std;

//time O(n^2), space O(n/m)
void removeOccurence(string &s, string& part){
    int found = s.find(part);
    
    if(found != string::npos){
        //part found, so remove it
        string leftpart = s.substr(0,found);
        string rightpart = s.substr(found + part.length() , s.length());
        s = leftpart + rightpart;

        removeOccurence(s,part);
    }
    else{
        //base case
        return;
    }
}
string removeOccurrences(string s, string part) {
    removeOccurence(s,part);
    return s;
}
int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s,part);

    return 0;
}