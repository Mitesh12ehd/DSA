#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr,int n,int i){
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

void heapSort(vector<int>& arr,int n){
    int size = n;
    while(size > 1){
        //step1 swap
        swap(arr[size],arr[1]);
        size--;

        //step2 heapify
        heapify(arr,size,1); 
    } 
}

vector<int> sortArray(vector<int>& nums) {
    //shift elment to one position to the right
    nums.push_back(-1);
    for(int i=nums.size()-1; i>0; i--){ 
        nums[i] = nums[i-1];
    }
    nums[0] = -1;

    int size = nums.size()-1;
    //create heap
    for(int i=size/2; i>0; i--){
        heapify(nums,size,i);
    }

    //call heap sort
    heapSort(nums,size);
    
    //now remove -1 that we added at index 0
    for(int i=0; i<nums.size()-1; i++){
        nums[i] = nums[i+1];
    }
    nums.pop_back();
    return nums;
}

int main(){
    vector<int> arr = {5,7,78,90,100,5,67,85,4,3,6};
    vector<int> ans = sortArray(arr);

    for(auto it:ans){
        cout << it << " ";
    }
    return 0;

}