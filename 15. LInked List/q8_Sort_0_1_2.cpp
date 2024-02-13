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

//method 1 Time = O(n) Space = O(1)
// void sort_0_1_2(Node*& head){
//     if(head == NULL){
//         return;
//     }
//     if(head->next == NULL){
//         return;
//     }

//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;
//     Node* temp = head;
//     while(temp!= NULL){
//         if(temp->data == 0){
//             zeroCount++;
//         }
//         else if(temp->data == 1){
//             oneCount++;
//         }
//         else{
//             twoCount++;
//         }
//         temp = temp->next;
//     }

//     temp = head;
//     while(zeroCount != 0){
//         temp->data = 0;
//         temp = temp->next;
//         zeroCount--;
//     }
//     while(oneCount != 0){
//         temp->data = 1;
//         temp = temp->next;
//         oneCount--;
//     }
//     while(twoCount != 0){
//         temp->data = 2;
//         temp = temp->next;
//         twoCount--;
//     }
// }

// Time = O(n) Space = O(1)
Node* sort_0_1_2(Node*& head){
    //1.create three node
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //2.travese original LL and append into coressponding node
    Node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            //isolate node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //append into zero node in zeroHead
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr->data == 1){
            //isolate node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //append into one node in oneHead
            oneTail->next = temp;
            oneTail = temp;
        }
        else if(curr->data == 2){
            //isolate node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //append into two node in twoHead
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    //now we have three diffrent list
    //3.merge
    
    //modify 1's list i.e. remove -1 vala node
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;
    //modify 2's list i.e. remove -1 vala node
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    //now join list
    if(oneHead != NULL){
        zeroTail->next = oneHead;
        if(twoHead != NULL){
            oneTail->next = twoHead;
        }
    }
    else{
        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }

    //remove zeroHead dummy Node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}

int main(){
    Node* head = new Node(0);
    Node* second = new Node(1);
    Node* third = new Node(1);
    Node* fourth = new Node(1);
    Node* fifth = new Node(1);
    Node* sixth = new Node(2);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    head = sort_0_1_2(head);

    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}