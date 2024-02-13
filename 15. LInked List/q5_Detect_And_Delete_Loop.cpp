#include<iostream>
#include<map>
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
        //here we have to destructor
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
//method 1
// bool detectLoop(Node*& head){
//     if(head == NULL){
//         cout << "LL is empty";
//         return false;
//     }

//     map<Node*,bool> visited;
//     Node* temp = head;
//     while(temp != NULL){
//         if(visited[temp] == true){
//             return true;
//         }
//         visited[temp] = true;
//         temp = temp->next;
//     }
//     return false;
// }

//method 2 Time = O(A+kC)
bool detectLoop(Node*& head){
    if(head == NULL){
        cout << "LL is empty";
        return false;
    }

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

// time O(A+kC)
Node* findStartingPoint(Node*& head){
    if(head == NULL){
        cout << "LL is empty";
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast){
            slow = head;
            break;
        }
    }

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// time O(A+kC)
void removeLoop(Node*& head){
    if(head == NULL){
        cout << "LL is empty";
        return;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast){
            slow = head;
            break;
        }
    }

    Node* prevNode = fast;
    while(slow != fast){
        prevNode = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prevNode->next = NULL;
}

int main(){
    //create a list
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = head;

    cout << detectLoop(head) <<endl;
    cout << findStartingPoint(head)->data <<endl ;
    removeLoop(head);
    printLinkedList(head);
    
    // cout << "\n" <<detectLoop(head) <<endl;

    return 0;
}