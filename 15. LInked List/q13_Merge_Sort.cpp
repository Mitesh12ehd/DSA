#include<iostream>
using namespace std;

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
void printLinkedList(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int findlength_Of_LinkedList(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//brute force approach to sort list will be
//store all the value in array
//sort array
//override linked list with array value

//optimal approach
Node* getMiddle(Node*& head){
    if(head == NULL){
        cout << "linked list empty";
        return head;
    }
    if(head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;
    while(fast!= NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
Node* mergeTwoLists(Node* left, Node* right) {
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node* ansHead = new Node(-1);
    Node* temp = ansHead;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if(left != NULL){
        temp->next = left;
    }
    if(right != NULL){
        temp->next = right;
    }

    //free the -1 node
    Node* varNode = ansHead;
    ansHead = ansHead->next;
    varNode->next = NULL;
    delete varNode;

    return ansHead;
}

//time = O(nlogn) Space = O(logn)
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    //break list into two part
    Node* mid = getMiddle(head);
    Node* leftHead = head;
    Node* rightHead = mid->next;
    mid->next = NULL;

    //sort both half
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    //merge
    Node* ansHead = mergeTwoLists(leftHead,rightHead);
    return ansHead;
}
int main(){
    Node* head = new Node(6);
    Node* second = new Node(2);
    Node* third = new Node(1);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(3);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    head = mergeSort(head);
    printLinkedList(head);

    return 0;
}