#include<iostream>
#include<vector>
using namespace std;

//leetcode 1813
//sentence similarity III

vector<string> splitIntoWords(string str){
    vector<string> v;
    string s = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] != ' '){
            s.push_back(str[i]);
        }
        else{
            v.push_back(s);
            s = "";
        }
    }
    v.push_back(s);
    return v;
}

bool areSentencesSimilar(string sentence1, string sentence2) {
    //to ensure sentence1 is always smaller than sentence 2
    if(sentence1.length() > sentence2.length()){
        return areSentencesSimilar(sentence2,sentence1);
    }

    vector<string> smallerWords = splitIntoWords(sentence1);
    vector<string> largerWords = splitIntoWords(sentence2);

    int start = 0;
    int end1 = smallerWords.size()-1;
    int end2 = largerWords.size()-1;
      

    for(auto it: smallerWords){
        cout << it << " ";
    }
    cout << endl;
    for(auto it:largerWords){
        cout << it << " ";
    }

    //find prefix words
    while(start <= end1 && (smallerWords[start] == largerWords[start])){
        start++;
    }

    //find suffix words
    while(start <= end1 && smallerWords[end1] == largerWords[end2]){
        end1--;
        end2--;
    }

    return start > end1;
}

int main(){
    return 0;
}