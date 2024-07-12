#include<iostream>
#include<string>
using namespace std;

string removeOccurrences(string s, string part) {
    int index = s.find(part);
    while(index != string::npos){
        s.erase(index , part.length());
        index = s.find(part);
    }
    return s;
}

//second method is done in recursion

int main(){
    string s="daabcbaabcbc";
    string part="abc";
    cout << removeOccurrences(s,part);

    return 0;
}