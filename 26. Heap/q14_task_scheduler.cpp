#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//leetcode 621 
//Task Scheduler

//1.First count the number of occurrences of each task and store that in a map/vector.
//2.Then push the count into a priority queue, so that the maximum frequency task can be accessed and completed first.
//3.Then until all tasks are completed (i.e the priority queue is not empty):

// intialise the cycle length as n+1. 
// n is the cooldown period so the cycle will be of n+1 length.
// Example: for ['A','A','A','B','B'] and n=2,
// the tasks can occur in the following manner:
// [A B idle]->[A B idle]->[A]. 
// See here each cycle is n+1 length long, only then A can repeat itself.

// for all elements in the priority queue, until the cycle length is exhausted, pop the elements out of the queue and if the task is occurring more than once then add it to the remaining array (which stores the remaining tasks).
// This means that we are completing that task once in this cycle.So keep counting the time.

// Then, add the occurrence of tasks back to the priority queue
// Add the idle time into the time count.

// Idle time is the time that was needed in the cycle because no task was available. It is the remaining cycle length in our algorithm. Idle time should be only added if the priority queue is empty (i.e all tasks are completed).

int leastInterval(vector<char>& tasks, int n) {
    vector<int> mp(26,0);
    for(int i=0; i<tasks.size(); i++){
        mp[tasks[i]-'A']++;
    }

    priority_queue<int> pq;
    for(int i=0; i<26; i++){
        if(mp[i] != 0){
            pq.push(mp[i]);
        }
    }

    int time = 0;
    while(!pq.empty()){
        // n+1 is the CPU cycle length, if n is the cooldown period then 
        // after a task A there will be n more tasks. Hence n+1
        int cycle = n+1;
        vector<int> remain;

    while(cycle != 0 && !pq.empty()){
        int max_freq = pq.top();
        pq.pop();

            if(max_freq > 1){
                remain.push_back(max_freq - 1);
            }

            time++;
            cycle--; 
        }

        for(auto it:remain){
            pq.push(it);
        }

        //if queue become empty no need to add ideal time
        if(pq.empty()){
            break;
        }

        //add a ideal time by remaining cycle length
        time = time + cycle;
    }

    return time;
}

int main(){
    return 0;
}