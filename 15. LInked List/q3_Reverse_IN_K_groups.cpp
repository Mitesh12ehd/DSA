#include<iostream>
using namespace std;

//Leetcode 25
//Reverse node in k groups

//drurun on both approach to understand

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
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};
int findlength_Of_LinkedList(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//itertive approach
Node* reverseLL(Node*& head){
    Node* prevNode = NULL;
    Node* currNode = head;
    while(currNode != NULL){
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;//increament
        currNode = nextNode;//increament
    }
    return prevNode;
}
Node* getKthNode(Node* temp,int k){
    //decreament k by 1 because we are at first nodes
    k--;
    while(temp != NULL && k--){
        temp = temp->next;
    }
    return temp;
}
Node* reverseKGroup(Node*& head,int k){
    Node* temp = head;
    Node* prevLast = NULL; // store last node of the previous group

    while(temp){
        Node* kthNode = getKthNode(temp,k);

        //if kth node is null we don't need to revrese that part
        if(kthNode == NULL){
            if(prevLast){
                prevLast->next = temp;
            }
            break;
        }

        //store the next node after kth node
        Node* nextNode = kthNode->next;

        //disconnect
        kthNode->next = NULL;

        //reverse k nodes
        reverseLL(temp);

        //head of answer bill become last node of first k nodes
        if(temp == head){
            head = kthNode;
        }
        else{
            //now this is second group so that we need to link to previous group
            prevLast->next = kthNode;
        }

        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

//recursive approach
// time = O(n) Space = O(n/k)
Node* reverseKGroup(Node*& head,int k){
    if(head == NULL){
        cout << "linked list is empty";
        return head;
    };
    int len = findlength_Of_LinkedList(head);
    if(k > len){
        cout << "k must be smaller than length";
        return head;
    }

    //step 1. reverese k node
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode;
    int i=1;
    while(i<=k){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;//increament
        currNode = nextNode;//increament
        i++;
    }

    //step 2. reverese a remain node by rescursion
    //here we have written head->next beacuse when k node reveresed,
    //head is shifted at the end
    head->next = reverseKGroup(nextNode,k);

    //step 3. return prevNode
    return prevNode;
}

int main(){
    return 0;
}