#include<iostream>
#include<unordered_map>
using namespace std;

//Leetcode 146
//LRU cache

//see notes

class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key,int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
    public:
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);
        int capacity;
        unordered_map<int,Node*> mp;

        LRUCache(int capacity) {
            this->capacity = capacity;
            head->next = tail;
            tail->prev = head;
        }

        void deleteNode(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = NULL;
            node->prev = NULL;
        }

        void insertAfterHead(Node* node){
            node->next = head->next;
            node->prev = head;
            head->next = node;
            node->next->prev = node;            
        }
        
        int get(int key) {
            if(mp.find(key) == mp.end()){
                return -1;
            }

            Node* resultNode = mp[key];
            deleteNode(resultNode);
            insertAfterHead(resultNode);
            return resultNode->val;
        }
        
        void put(int key, int value) {
            if(mp.find(key) != mp.end()){
                //key already exist
                Node* existingNode = mp[key];
                deleteNode(existingNode);
                insertAfterHead(existingNode);
                existingNode->val = value;
            }
            else if(mp.size() < capacity){
                Node* newNode = new Node(key,value);
                insertAfterHead(newNode);
                mp[key] = newNode;
            }
            else{
                //capacity full
                //delete the lru node
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                Node* newNode = new Node(key,value);
                insertAfterHead(newNode);
                mp[key] = newNode;
            }
        }
    };

int main(){
    return 0;
}