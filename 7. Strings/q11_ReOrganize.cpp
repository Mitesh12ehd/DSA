#include<iostream>
#include<limits.h>
using namespace std;

string reorganizeString(string s) {
    int hash[26] = {0};
    //count frequency of each character
    for(int i=0; i<s.length(); i++){
        hash[s[i] - 'a']++;
    }
    //find the most frequent character
    char max_freq_char;
    int max_freq = INT_MIN;
    for(int i=0; i<26; i++){
        if(hash[i] > max_freq){
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }
    //place the most frequent character non adjacently
    int index = 0;
    while(index < s.length()  &&  max_freq>0){
        s[index] = max_freq_char;
        max_freq--;
        index = index + 2;
    }
    //if most frequent character not placed it's not possible
    if(max_freq > 0){
        return "";
    }
    //most frequent character placed so make frequency 0
    hash[max_freq_char - 'a'] = 0;
    //place the rest of character
    for(int i=0; i<26; i++){
        while(hash[i] > 0){
            index = (index >=s.length()) ? 1 :index;
            s[index] = i + 'a';
            hash[i]--;
            index = index +2;
        }
    }
    return s;
}
int main(){
    string s="aab";
    cout << reorganizeString(s);

    return 0;
}