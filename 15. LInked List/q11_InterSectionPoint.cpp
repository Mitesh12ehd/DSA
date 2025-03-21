#include<iostream>
using namespace std;

//Leetcode 160
//Intersection of two linked list

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

//brute force time = O(n^2)
Node *getIntersectionNode(Node *headA, Node *headB) {
    while(headB != NULL){
        Node* temp = headA;
        while(temp != NULL){
            if(temp == headB){
                return temp;
            }
            temp = temp->next;
        }
        headB = headB->next;
    }
    return NULL;
}

// better approach 1
// use hashing
// store one of the of the list in set
// interate on another list and check if node is found in set

//  better approach 2
Node *getIntersectionNode(Node *headA, Node *headB) {
    int len1 = findlength_Of_LinkedList(headA);
    int len2 = findlength_Of_LinkedList(headB);

    Node* tempA = headA;
    Node* tempB = headB;

    if(len1 > len2){
        int n = len1-len2;
        for(int i=1; i<=n; i++){
            tempA = tempA->next;
        }
    }
    else{
        int n = len2-len1;
        for(int i=1; i<=n; i++){
            tempB = tempB->next;
        }
    }

    while(tempA != NULL && tempB != NULL){
        if(tempA == tempB){
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return NULL;
}

//optimal approach
//time = O(max(m,n)) Space = O(1)
//see strive solution to understand and dryrun on it
Node *getIntersectionNode(Node *headA, Node *headB) {
    Node* tempA = headA;
    Node* tempB = headB;

    while(tempA->next != NULL && tempB->next != NULL){
        if(tempA == tempB){
            //when length of both list same
            return tempA;
        }

        tempA = tempA->next;
        tempB = tempB->next;
    }

    //check if list have not intersection
    if(tempA->next == NULL && tempB->next == NULL && tempA != tempB){
        return NULL;
    }

    if(tempA->next == NULL){
        //second list is bigger
        //find how much bigger it is
        int b_length = 0;
        while(tempB->next != NULL){
            b_length++;
            tempB = tempB->next;
        }
        //now move headB to b_length step
        while(b_length != 0){
            headB = headB->next;
            b_length--;
        }
    }
    if(tempB->next == NULL){
        //first list is bigger
        //find how much bigger it is
        int a_length = 0;
        while(tempA->next != NULL){
            a_length++;
            tempA = tempA->next;
        }
        //now move headB to b_length step
        while(a_length != 0){
            headA = headA->next;
            a_length--;
        }
    }

    while(headA != headB){
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main(){
    return 0;
}