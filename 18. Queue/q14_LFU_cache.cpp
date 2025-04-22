#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

//Leetcode 460
//LFU cache

//see notes

//here we require below things

//map<freq,list> : store node for given freq, a node at head is most recently used
//                                            a node at back is LRU

//map<key,node> : store address of node for particaluar key

//least freq : store least frequency, so that we access least freq node from 
//             <freq,list>


class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    int count;

    Node(int key,int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
        this->count = 1;
    }
};

class List{
    public:

    int size;
    Node* head;
    Node* tail;
    
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addAtBeginning(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        size++;
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        size--;
    }
};

class LFUCache {
    public:
        unordered_map<int,List*> freqList;
        unordered_map<int,Node*> keyNode;
        int maximumSize;
        int leastFreq;
        int currSize;

        LFUCache(int capacity) {
            this->maximumSize = capacity;
            leastFreq = 0;
            currSize = 0;
        }

        void updateFreqListMap(Node* node){
            freqList[node->count]->removeNode(node);

            //check if minfreq can be updated
            if(leastFreq == node->count && freqList[node->count]->size == 0){
                leastFreq++;
            }

            //add node in freqList[count+1]
            List* nextHigherFreqList = new List();
            if(freqList.find(node->count + 1) != freqList.end()){
                nextHigherFreqList = freqList[node->count + 1];
            }

            node->count = node->count + 1;
            nextHigherFreqList->addAtBeginning(node);
            freqList[node->count] = nextHigherFreqList;
        }
        
        int get(int key) {
            if(keyNode.find(key) == keyNode.end()){
                return -1;
            }

            Node* node = keyNode[key];
            updateFreqListMap(node);
            return node->val;
        }
        
        void put(int key, int value) {
            if(keyNode.find(key) != keyNode.end()){
                Node* node = keyNode[key];
                node->val = value;
                updateFreqListMap(node);
            }
            else{
                if(currSize == maximumSize){
                    List* list = freqList[leastFreq];
                    keyNode.erase(list->tail->prev->key);
                    freqList[leastFreq]->removeNode(list->tail->prev);
                    currSize--;
                }

                currSize++;
                leastFreq = 1;
                List* list = new List();
                if(freqList.find(leastFreq) != freqList.end()){
                    list = freqList[leastFreq];
                }
                
                Node* newNode = new Node(key,value);
                list->addAtBeginning(newNode);
                keyNode[key] = newNode;
                freqList[leastFreq] = list;
            }
        }
};

int main(){
    return 0;
}