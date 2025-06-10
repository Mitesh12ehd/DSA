#include<iostream>
using namespace std;

// Leetcode 208
// Implement Trie (Prefix Tree)
// see notes

class Node{
    public:
    Node* link[26];
    bool flag = false;

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

class Trie {
private:
    Node* root;


public:
    Trie() {
        root =  new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!(node->isCharExist(ch))){
                // if char not exist in current trie put it and 
                // make link to new trie
                node->put(word[i],new Node());
            }
            //move to node where it char in current trie points
            node = node->get(ch);
        }   

        //set flag true in last trie
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!(node->isCharExist(ch))){
                return false;
            }
            node = node->get(ch);
        }
        return node->flag == true;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            char ch = prefix[i];
            if(!(node->isCharExist(ch))){
                return false;
            }
            node = node->get(ch);
        }
        return node != NULL; // or return true because if null then 
                             // we return false already
    }
};

int main(){
    return 0;
}