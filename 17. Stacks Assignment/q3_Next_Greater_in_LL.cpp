#include<iostream>
#include<vector>
#include<stack>
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

// time = O(n) , space = O(3n) = O(n)
vector<int> nextLargerNodes(Node* head) {
    vector<int> list;
    Node* temp = head;
    while(temp != NULL){
        list.push_back(temp->data);
        temp = temp->next;
    }

    vector<int> ans(list.size());
    stack<int> st;
    st.push(0);
    for(int i=list.size()-1; i>=0; i--){
        int curr = list[i];
        //pop element until we got larger element than curr at top
        while(st.top() <= curr && st.top() != 0){
            st.pop();
        }
        //we got larger element than curr at st.top
        ans[i] = st.top();
        st.push(curr);
    }
    return ans; 
}
int main(){
    //create a list
    Node* head = new Node(2);
    Node* second = new Node(7);
    Node* third = new Node(4);
    Node* fourth = new Node(3);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    vector<int> ans = nextLargerNodes(head);
    for(auto it:ans){
        cout << it << " ";
    };

    return 0;
}