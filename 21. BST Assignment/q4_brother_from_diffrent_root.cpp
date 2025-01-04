#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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

//method 1 time = O(n) space = O(n)
// void storeInorder(Node* root1,vector<int>& bst1){
//     if(root1 == NULL){
//         return;
//     }

//     storeInorder(root1->left,bst1);
//     bst1.push_back(root1->data);
//     storeInorder(root1->right,bst1);
// }
// void storeReverseInorder(Node* root2,vector<int>& bst2){
//     if(root2 == NULL){
//         return;
//     }

//     storeReverseInorder(root2->right,bst2);
//     bst2.push_back(root2->data);
//     storeReverseInorder(root2->left,bst2);
// }
// int countPairs(Node* root1, Node* root2, int x){
//     int ans = 0;
//     vector<int> bst1;
//     vector<int> bst2;
//     storeInorder(root1,bst1);
//     storeReverseInorder(root2,bst2);

//     int ptr1 = 0;
//     int ptr2 = 0;
//     while(ptr1 < bst1.size() && ptr2 < bst2.size()){
//         int sum = bst1[ptr1] + bst2[ptr2];
        
//         if(sum == x){
//             ans++;
//             ptr1++;
//             ptr2++;
//         }
//         else if(sum < x){
//             ptr1++;
//         }
//         else{
//             ptr2++;
//         }
//     }
//     return ans;
// }

//method 2
int countPairs(Node* root1, Node* root2, int x){
    int ans = 0;
    stack<Node*> s1,s2;
    Node* a = root1;
    Node* b = root2;

    while(true){
        while(a != NULL){
            //inorder
            s1.push(a);
            a = a->left;
        }

        while(b != NULL){
            //reverse inorder
            s2.push(b);
            b = b->right;
        }

        if(s1.empty() || s2.empty()){
            break;
        }

        Node* atop = s1.top();
        Node* btop = s2.top();

        int sum = atop->data + btop->data;
        if(sum == x){
            ans++;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if(sum  < x){
            s1.pop();
            a = atop->right;
        }
        else{
            s2.pop();
            b = btop->left;
        }
    }
    return ans;
}

int main(){
    return 0;
}