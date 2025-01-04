#include<iostream>
#include<vector>
using namespace std;

//leetcode 1455
//check if word occurs as a prefix of any word in a sentence

//brute force space = O(sentence.length)
int isPrefixOfWord(string sentence, string searchWord) {
    int n = searchWord.length();

    vector<string> words;
    string str = "";
    for(int i=0; i<sentence.length(); i++){
        if(sentence[i] == ' '){
            words.push_back(str);
            str = "";
        }
        else{
            str.push_back(sentence[i]);
        }
    }
    words.push_back(str);

    for(int i=0; i<words.size(); i++){
        string word = words[i];
        cout << word << endl;

        int index = 0;
        int m = word.length();
        while(index < n){
            if(searchWord[index] != word[index]){
                break;
            }
            index++;
        }
        if(index == n){
            return i+1;
        }
    }
    return -1;
}

//space optimized
int isPrefixOfWord(string sentence, string searchWord) {
    int n = searchWord.length();
    int m = sentence.length();

    int left = 0;
    int right = 0;
    int wordCount=0;

    while(left<m && right<m){
        //cover a one word
        while(sentence[right] != ' ' && right < m){
            right++;
        }
        wordCount++;

        //string matching
        int index = 0;
        while(index<n){
            if(sentence[left] != searchWord[index]){
                break;
            }
            index++;
            left++;
        }
        if(index == n){
            return wordCount;
        }

        right++;
        left = right;
    }    
    return -1;
}


int main(){
    

    return 0;
}