#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Nodedata{
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    Nodedata(){
        
    }

    Nodedata(int size,int minVal,int maxVal,bool validBST){
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->validBST = validBST;

    }
};

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
	}
}

Nodedata largestBst(Node *root,int& ans){
    //base case
    if(root == NULL){
        Nodedata temp(0,INT_MAX,INT_MIN,true);
        return temp;
    }

    Nodedata leftKaAns = largestBst(root->left,ans);
    Nodedata rightKaAns = largestBst(root->right,ans);

    Nodedata current;
    current.size = leftKaAns.size + rightKaAns.size + 1;
    current.minVal = min(root->data,leftKaAns.minVal);
    current.maxVal = max(root->data,rightKaAns.maxVal);

    if(leftKaAns.validBST &&
        rightKaAns.validBST &&
        (root->data > leftKaAns.maxVal) &&
        (root->data < rightKaAns.minVal) )
    {
        current.validBST = true;
    }
    else{
        current.validBST = false;
    }

    if(current.validBST){
        ans = max(ans,current.size);
    }
    return current;
}



int main(){

    Node* root = new Node(1);
    Node* first = new Node(4);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;

    cout << "printing tree" << endl;
    levelOrderTraversal(root);

    //driver code for question
    int ans = 0;
    largestBst(root,ans);
    cout << ans;

    return 0;
}