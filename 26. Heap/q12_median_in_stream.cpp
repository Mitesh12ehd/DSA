#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//leetcode 295
//find median from data stream

//brute force
class MedianFinder {
    public:

    vector<int> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
    }
    
    double findMedian() {
        sort(v.begin(),v.end());
        int n = v.size();
        if(n == 1){
            return v.back();
        }
        else if(n%2 == 1){
            return v[n/2];
        }
        else{
            double n1 = v[n/2];
            double n2 = v[(n/2)-1];
            return (n1+n2)/2;
        }
    }
};

//insertion sort logic
class MedianFinder {
public:
    vector<int> v;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
        //put last element to its valid position
        int n = v.size();
        int index = n-2;
        while(index >= 0 && v[index] > num){
            v[index+1] = v[index];
            index--;
        }
        v[index+1] = num;
    }
    
    double findMedian() {
        int n = v.size();
        if(n%2 == 1){
            return v[n/2];
        }
        else{
            double n1 = v[n/2];
            double n2 = v[(n/2)-1];
            return (n1+n2)/2;
        }
    }
};

//using heaps
class MedianFinder {
public:
    priority_queue<int> smallHeap;
    priority_queue<int,vector<int>,greater<int>> largeHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        //make sure every element in smallheap is less than every
        //element in largeheap
        if(!smallHeap.empty() && !largeHeap.empty() &&
        smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        //if len diffence is more than 1
        if(smallHeap.size() > largeHeap.size()+1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size()+1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }
        else if(smallHeap.size() < largeHeap.size()){
            return largeHeap.top();
        }
        else{
            //even number of elements
            double num1 = smallHeap.top();
            double num2 = largeHeap.top();
            return (num1+num2)/2;
        }
    }
};


int main(){
    return 0;
}