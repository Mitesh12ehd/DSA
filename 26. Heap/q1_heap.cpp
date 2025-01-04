#include<iostream>
using namespace std;

//implementation of maxheap using array

//why we start from index = 1 not index = 0
//because formula for finding parent child not followed if take starting index = 0

class heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size++;
        int index = size;
        //1. put value at the end
        arr[index] = val;
        //2. shift to correct position
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            cout << "heap is empty" << endl;
            return;
        }
        
        //1. put last node to root node
        arr[1] = arr[size];
        size--;

        //2. move root node to correct position
        int i=1;
        while(i*2 <= size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            
            //find index of larger child
            int largeIndex;
            if(rightIndex <= size && arr[leftIndex] < arr[rightIndex]){
                largeIndex = rightIndex;
            }
            else{
                largeIndex = leftIndex;
            }

            //compare the parent with larger child
            if(arr[i] < arr[largeIndex]){
                swap(arr[i],arr[largeIndex]);
                i = largeIndex;
            }
            else{
                return;
            }
        }
    }

    void printHeap(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main(){
    heap h;
    h.insert(5);
    h.insert(10);
    h.printHeap();
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.printHeap();
    h.insert(60);
    h.printHeap();

    h.deleteFromHeap();
    h.printHeap();
    h.deleteFromHeap();
    h.printHeap();

    return 0;
}