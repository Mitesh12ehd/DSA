#include<iostream>
using namespace std;

//given a array of elements, convert it into maxheap
//i.e. put all elements to correct postition

void heapify(int arr[],int n,int i){
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i+1;

    if(leftChild <= n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild <= n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    //check if largest is updated or not
    if(largest != i){
        swap(arr[largest],arr[i]);
        //put largest to its correct posistion again
        heapify(arr,n,largest);
    }
} 

int main(){
    
    int arr[6] = {-1,54,53,55,52,60};
    int n = 5;
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }

    for(int i=1; i<6; i++){
        cout << arr[i] << " ";
    }
    return 0;
}