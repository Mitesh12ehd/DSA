#include<iostream>
using namespace std;

int minMaxDifference(int num) {
    string str = to_string(num);
    int n = str.length();

    string maximum = str;
    string minimum = str;
    char ch1;
    char ch2;
    bool char1Found = false;
    bool char2Found = false;
    for(int i=0; i<n; i++){
        if(!char1Found && str[i] != '9'){
            char1Found = true;
            ch1 = str[i];
            maximum[i] = '9';
        }
        else if(char1Found && str[i] == ch1){
            maximum[i] = '9';
        }

        if(!char2Found && str[i] != '0'){
            char2Found = true;
            ch2 = str[i];
            minimum[i] = '0';
        }
        else if(char2Found && str[i] == ch2){
            minimum[i] = '0';
        }
    }

    return stoi(maximum) - stoi(minimum);
}

int main(){
    return 0;
}