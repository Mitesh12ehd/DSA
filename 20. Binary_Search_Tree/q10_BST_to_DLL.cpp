#include<iostream>
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

Node* build_BST(int inorder[],int start,int end){
    if(start > end){
        return NULL;
    }

    int mid = (start+end) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = build_BST(inorder,start,mid-1);
    root->right = build_BST(inorder,mid+1,end);
    return root;
}

void convert_into_DLL(Node* root,Node*& head){
    if(root == NULL){
        return;
    }

    //right sub tree
    convert_into_DLL(root->right,head);

    //attach root node
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    //update head
    head = root;

    //left sub tree
    convert_into_DLL(root->left,head);
}

void print_LL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout <<  temp->data << " ";
        temp = temp->right;
    }
}

int main(){
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = 8;

    cout << "printing tree" << endl;
    Node* root = build_BST(inorder,start,end);
    levelOrderTraversal(root);

    cout << endl;
    cout << "printing linked list" << endl;
    Node* head = NULL;
    convert_into_DLL(root,head);
    print_LL(head);

    return 0;
}