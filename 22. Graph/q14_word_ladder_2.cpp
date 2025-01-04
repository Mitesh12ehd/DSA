#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

//this approach give memory limit exceedded
//but it is valid for interview
// vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//     unordered_set<string> st(wordList.begin(),wordList.end());
//     queue<vector<string>> q;
//     q.push({beginWord});
//     vector<vector<string>> ans;

//     //reason: it keep track of word that are used on level 
//     //and we remove it in next iteration
//     vector<string> usedOnLevel; 
//     usedOnLevel.push_back(beginWord);
//     int level = 0;

//     while(!q.empty()){
//         vector<string> vec = q.front();
//         q.pop();

//         //erase word from set that are on previous level
//         //ex. initialy level= 1, so erase the beginWord from set
//         if(vec.size() > level){
//             level++;
//             for(auto it:usedOnLevel){
//                 st.erase(it);
//             }
//         }
        
//         string word = vec.back();
//         
//         //save ans, and if new answer it must be shorted
//         if(word == endWord){
//             if(ans.size() == 0){
//                 ans.push_back(vec);
//             }
//             //reason because we need shortest path
//             else if(ans.size() > 0 && ans[0].size() == vec.size()){
//                 ans.push_back(vec);
//             }
//         }

//         for(int i=0; i<word.size(); i++){
//             char original = word[i];
//             for(char ch='a'; ch<='z'; ch++){
//                 word[i] = ch;
//                 if(st.find(word) != st.end()){
//                     vec.push_back(word);
//                     q.push(vec);
//                     usedOnLevel.push_back(word);
//                     vec.pop_back();
//                 }
//             }
//             word[i] = original;
//         }
//     }
//     return ans;
// }


//optimized 2 step method
unordered_map<string,int> mp;
vector<vector<string>> ans;
string begin_Word;
int wordLength;
void dfs(string word,vector<string>& seq){
    if(word == begin_Word){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    
    int level = mp[word];
    for(int i=0; i<wordLength; i++){
        char orginal = word[i];
        for(char ch='a'; ch<='z'; ch++){
            word[i] = ch;
            if(mp.find(word) != mp.end() && mp[word]+1 == level){
                seq.push_back(word);
                dfs(word,seq);
                seq.pop_back();
            }
        }
        word[i] = orginal;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //step 1. store map
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<string> q;
    q.push(beginWord);
    st.erase(beginWord);
    mp[beginWord] = 1;
    int n = beginWord.size();

    //intialize  global variable
    begin_Word = beginWord;
    wordLength = n;

    while(!q.empty()){
        string word = q.front();
        int level = mp[word];
        q.pop();

        for(int i=0; i<n; i++){
            char orginal = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    q.push(word);
                    st.erase(word);
                    mp[word] = level+1;
                }
            }
            word[i] = orginal;
        }
    }

    //step 2 backtracking from endword to beginword
    if(mp.find(endWord) != mp.end()){
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord,seq);
    }
    return ans;
}

int main(){
    string a="hit";
    string b="cog";
    vector<string> v = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> vec = findLadders(a,b,v);

    for(auto path:vec){
        for(auto it:path){
            cout << it << " -> ";
        }
        cout << endl;
    }
    return 0;
}