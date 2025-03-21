#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//GFG
//Find pair with given sum in doubly linked list

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        cout << "node with data " << this->data << " is deleted\n";
    }
};

//brute force
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<pair<int,int>> ans;
    set<int> st;
    
    Node* temp = head;
    while(temp != NULL){
        if(st.find(target - temp->data) != st.end()){
            ans.push_back({target - temp->data,temp->data});
        }
        temp = temp->next;
        st.insert(temp->data);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

//optimal
//take advantage of sorted data and double linked list
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    Node* start = head;
    Node* end = head;
    while(end->next != NULL){
        end = end->next;
    }

    vector<pair<int, int>> ans;
    while(start->data < end->data){
        int sum = start->data + end->data;
        if(sum == target){
            ans.push_back({start->data,end->data});
            start = start->next;
            end = end->prev;
        }
        else if(sum < target){
            start = start->next;
        }
        else{
            end = end->prev;
        }
    }
    return ans;
}

int main(){
    return 0;
}