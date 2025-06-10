#include<iostream>
using namespace std;

// Naukri
// Implement Trie II
// see notes

class Node{
    public:
    Node* link[26];
    int wordCount = 0;
    int prefixCount = 0;

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

class Trie{
    private:
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!(node->isCharExist(ch))){
                node->put(word[i],new Node());
            }
            node = node->get(ch);
            node->prefixCount++;
        }
        node->wordCount++;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!(node->isCharExist(ch))){
                return 0;
            }
            node = node->get(ch);
        }
        return node->wordCount;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!(node->isCharExist(ch))){
                return 0;
            }
            node = node->get(ch);
        }
        return node->prefixCount;
    }

    void erase(string &word){
        // note : here is given that word is guaranteed exist in trie
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            node = node->get(ch);
            node->prefixCount--;
        }
        node->wordCount--;
    }
};

int main(){
    return 0;
}