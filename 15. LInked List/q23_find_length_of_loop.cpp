#include<iostream>
#include<unordered_map>
using namespace std;

//GFG
//Find length of loop

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

//brute force
int countNodesinLoop(Node *head) {
    unordered_map<Node*,int> mp;
    Node* temp = head;
    int count = 1;

    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return count - mp[temp];
        }

        mp[temp] = count;
        count++;
        temp = temp->next;
    }
    return 0;
}

//optimal approach
int countNodesinLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast){
            break;
        }
    }

    if(fast == NULL){
        return 0;
    }

    int count = 1;
    fast = fast->next;
    while(fast != slow){
        count++;
        fast = fast->next;
    }
    return count;
}

int main(){
    return 0;
}