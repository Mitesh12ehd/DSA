#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode 23
//merge k sorted list

//total element = m
//time = O(m*log(k))
//space = O(k)

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        //here we have to right constructor
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};


class myComp{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};
Node* mergeKLists(vector<Node*>& lists) {
    Node* head = new Node(-1);
    Node* tail = head;

    priority_queue<Node*,vector<Node*>,myComp> minheap; 
    for(int i=0; i<lists.size(); i++){
        minheap.push(lists[i]);
    }

    while(!minheap.empty()){
        Node* temp = minheap.top();
        minheap.pop();

        if(temp->next != NULL){
            minheap.push(temp->next);
        }
        
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }

    //remove intial -1 node
    Node* dummy = head;
    head = head->next;
    dummy->next = NULL;
    delete dummy;
    return head;
}


int main(){
    return 0;
}