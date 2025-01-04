#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
using namespace std;

//leetcode 127

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(),wordList.end());
    st.erase(beginWord);
    queue<pair<string,int>> q;
    q.push({beginWord,1});

    while(!q.empty()){
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        if(word == endWord){
            return level;
        }
            
        for(int i=0; i<word.length(); i++){
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                //check if exist in set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word,level+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main(){
    return 0;
}