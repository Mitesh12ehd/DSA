#include<iostream>
#include<unordered_map>
using namespace std;

//leetcode 141
//Linked list cycle

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
        //here we have to destructor
        cout << "Node with value = "<< this->data << " is deleted" <<endl;
    }
};

//brute force time = O(n) space = O(n)
bool hasCycle(Node *head) {
    unordered_map<Node*,bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

//optimal approach time = Time = O(n) space = O(1)
bool hasCycle(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast){
            return true;
        }
    }
    return false;
}


int main(){
    return 0;
}