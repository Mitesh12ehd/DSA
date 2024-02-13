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

//method 1 Time = O(n), Space O(1)
// int solve(Node* head, int position){
//     int len = findlength_Of_LinkedList(head);
//     if(position > len-1){
//         cout << "enter valid position";
//         return -1;
//     }
//     Node* temp = head;
//     for(int i=1; i<len-position; i++){
//         temp = temp->next;
//     }
//     return temp->data;
// }

void fun(Node* head, int& position,int& ans){
    if(head == NULL){
        return;
    }

    fun(head->next, position , ans);
    if(position == 0){
        ans = head->data;
    }
    position--;
}

//method 2 Time = O(n), Space O(n)
int getNode(Node* llist, int positionFromTail) {
    int ans = -1;
    fun(llist,positionFromTail,ans);
    return ans;
}

int main(){
    Node* head = new Node(3);
    Node* second = new Node(2);
    Node* third = new Node(1);
    head->next = second;
    second->next = third;

    int position = 2;
    cout << getNode(head,position);
    return 0;
}