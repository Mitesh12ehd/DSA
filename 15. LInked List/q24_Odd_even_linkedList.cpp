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

//dryrun to understand
// 1 -> 2 -> 3 -> 4 -> 5
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
Node* oddEvenList(Node* head) {
    if(!head || !head->next){
        return head;
    }

    Node* oddHead = head;
    Node* evenHead = head->next;

    Node* odd = head;
    Node* even = head->next;
    Node* lastOdd = NULL;
    while(odd != NULL && even != NULL){
        odd->next = even->next;

        if(even->next && even->next->next){
            even->next = even->next->next;
        }
        else{
            even->next = NULL;
        }
        lastOdd = odd;
        odd = odd->next;
        even = even->next;
    }
    
    if(odd == NULL){
        lastOdd->next = evenHead;
    }
    else{
        odd->next = evenHead;
    }
    
    return oddHead;
}
int main(){
    return 0;
}