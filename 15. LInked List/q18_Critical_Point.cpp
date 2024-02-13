#include<iostream>
#include<vector>
#include<limits.h>
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
vector<int> nodesBetweenCriticalPoints(Node* head) {
    vector<int> ans = {-1,-1};//minDist,maxDist
    Node* prevNode = head;
    if(prevNode == NULL){
        return ans;
    }
    Node* currNode = head->next;
    if(currNode == NULL){
        return ans;
    }
    Node* nextNode = head->next->next;
    if(nextNode == NULL){
        return ans;
    }

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i=1;
    while(nextNode != NULL){
        bool isCP = ((currNode->data > prevNode->data && currNode->data > prevNode->data)  ||
                     (currNode->data < prevNode->data && currNode->data < prevNode->data)) 
                     ? true : false;
        if(isCP && firstCP == -1){
            firstCP = i;
            lastCP = i;
        }
        else if(isCP){
            minDist = min(minDist, i-lastCP);
            lastCP = i;
        }
        i++;
        prevNode = prevNode->next;
        currNode = currNode->next;
        nextNode = nextNode->next;
    }

    if(firstCP == lastCP){
        //only one cp found
        return ans;
    }
    else{
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}

int main(){
    return 0;
}