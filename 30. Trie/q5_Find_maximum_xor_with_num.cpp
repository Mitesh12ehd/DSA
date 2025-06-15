#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
 Given a array of integers and number x.
 Find maximum value of arr[i] ^ x
*/
// see notes 

// approach 1
// time = O(n * 32)
// space = O(1)
int findMaximumXOR(vector<int>& arr,int num){
    int ans = INT_MIN;
    for(auto it:arr){
        ans = max(ans,num^it);
    }
    return ans;
}
 
// approach 2, not reduce time complexity, but this approach helps in future
// time = O(n * 32)
// space = not able to predict
class Node {
    public:
    Node* links[2]; 
    bool containsKey(int bit) {
        return (links[bit] != NULL); 
    }
    Node* get(int bit) {
        return links[bit]; 
    }
    void put(int bit, Node* node) {
        links[bit] = node; 
    }
};
class Trie {
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        // we insert from left to right in binary format
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // get ith bit
            if (!node->containsKey(bit)) {
                node->put(bit, new Node()); 
            }
            node = node->get(bit); 
        }
    }

    int getMax(int num) {
        Node* node = root; 

        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1; //ith bit of num
            // check if node contain opposite of bit 1
            if(bit == 1 && node->containsKey(0)){
                // mark ith bit of ans as 1
                maxNum = maxNum | (1 << i);

                // move
                node = node->get(0);
            }
            // check if node contain opposite of bit 0
            else if(bit == 0 && node->containsKey(1)){
                // mark ith bit of ans as 1
                maxNum = maxNum | (1 << i);

                // move
                node = node->get(1);
            }
            else{
                // go with same bit as not able to find opposite
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
int findMaximumXOR(vector<int>& arr,int num){
    Trie trie;
    for(auto it:arr){
        trie.insert(it);
    }
    return trie.getMax(num);
}

int main(){
    return 0;
}