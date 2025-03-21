#include<iostream>
#include<unordered_map>
using namespace std;

//Leetcode 138
//Copy list with random pointer

class Node{
    public:
    int val;
    Node* next;
    Node* random;

    Node(){
        this->val = 0;
        this->next = NULL;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
    ~Node(){
        //here we have to destructor
        int value = this->val;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};
Node* helper(Node* head,unordered_map<Node*,Node*>&mp){
    if(head == NULL){
        return NULL;
    }
    Node* newHead = new Node(head->val);
    mp[head] = newHead;
    newHead->next = helper(head->next,mp);
    if(head->random != NULL){
        //it has random node
        newHead->random = mp[head->random];
    }
    return newHead;
}

//method 1
// Node* copyRandomList(Node* head) {
//     //this map stores old node to new Node mapping
//     unordered_map<Node*,Node*> mp;
//     return helper(head,mp);
// }

//method 2
Node* copyRandomList(Node* head) {
    if(head == NULL){
        return NULL;
    }

    //1.create a new list with oldNode and newnode
    Node* temp = head;
    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    //2.assign random links on newNode with the help of oldNode
    temp = head;
    while(temp != NULL){
        if(temp->random != NULL){
            temp->next->random = temp->random->next;
        }
        else{
            temp->next->random = NULL;
        }
        temp = temp->next->next;
    }

    //3.Deattcach new list and old list
    temp = head;
    Node* newHead = temp->next;
    while(temp != NULL){
        Node* newTemp = temp->next;
        Node* dummy = temp;
        temp = temp->next->next;
        dummy->next = NULL;
        delete dummy;
    }

    temp = head;
    Node* clonedHead = temp->next;
    while(temp != NULL){
        Node* newNode = temp->next;
        temp->next = temp->next->next;
        if(newNode->next != NULL){
            newNode->next = newNode->next->next;
        }
        temp = temp->next;
    }
    return clonedHead;
}

int main(){
    return 0;
}