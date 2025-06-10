#include<iostream>
#include<vector>
using namespace std;

// Naukri
// Complete string
// see notes

// time = O(n* length)
// space = not able to predict because there can be 26+26+26....
//         but optimized because we not store same char twice

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
    public:
    Node* root;

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

    bool checkIfPrefixExist(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!(node->isCharExist(ch))){
                return false;
            }

            node = node->get(ch);
            if(node->flag == false){
                return false;
            }
        }
        
        return node->flag; // or return true both work same
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;

    //insert each word
    for(auto it:a){
        trie.insert(it);
    }

    //find complete string
    string longest = "";
    for(auto word:a){
        if(trie.checkIfPrefixExist(word)){
            if(word.length() > longest.length()){
                longest = word;
            }
            else if(word.length() == longest.length() && word < longest){
                //take laxographical smallest string
                longest = word;
            }
        }
    }
    return (longest == "") ? "None" : longest;
}

int main(){
    return 0;
}