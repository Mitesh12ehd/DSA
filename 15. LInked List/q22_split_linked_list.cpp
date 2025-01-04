#include<iostream>
#include<vector>
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

int findlength_Of_LinkedList(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
    
vector<Node*> splitListToParts(Node* head, int k) {
    //first lets calclulate length of each list
    vector<int> v(k);
    int n = findlength_Of_LinkedList(head);
    for(int i=0; i<k; i++){
        v[i] = n/k;
    }
    int remainingNodes = n % k;
    int index = 0;
    while(remainingNodes--){
        v[index] = v[index] + 1;
        index++;
    }

    //now perform task
    vector<Node*> ans;
    Node* temp = head;
    for(auto it:v){
        Node* oneHead = temp;
        Node* prevNode = NULL;
        while(it--){
            prevNode = temp;
            temp = temp->next;
        }
        if(prevNode){
            prevNode->next = NULL;
        }
                
        ans.push_back(oneHead);
    }
    return ans;
}

int main(){
    return 0;
}