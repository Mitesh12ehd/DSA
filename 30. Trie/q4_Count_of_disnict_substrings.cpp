#include<iostream>
#include<set>
using namespace std;

// GFG
// Count of distinct substrings
// see notes

// brute force
// time = O(n^2 * logm) where m = number of elements in set = n^2 (nearly or less)
// space = O(n^3) number of elements in set is n^2 and size of each is n
int countDistinctSubstring(string s) {
    int n = s.length();
    set<string> st;
    for(int i=0; i<n; i++){
        string str = "";
        for(int j=i; j<n; j++){
            str.push_back(s[j]);
            st.insert(str);
        }
    }
    return st.size()+1;
}

// optimal
// time = O(n^2)
// space = not able to predict because of 26+26+26.....
class Node{
    public:
    Node* link[26];

    // check given char exist in trie or not
    bool isCharExist(char ch){
        return link[ch - 'a'] != NULL;
    }

    // put char in trie, and point it to new trie
    void put(char ch,Node* newNode){
        link[ch-'a'] = newNode;
    }

    // return reference trie of ch, that help trie char to move to its
    // reference trie
    Node* get(char ch){
        return link[ch-'a'];
    }
};
int countDistinctSubstring(string s) {
    int n = s.length();
    
    int ans = 0;
    Node* root = new Node();

    for(int i=0; i<n; i++){
        Node* node = root;
        for(int j=i; j<n; j++){
            char ch = s[j];
            if(!(node->isCharExist(ch))){
                ans++;
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
    }
    return ans+1;
}

int main(){
    return 0;
}