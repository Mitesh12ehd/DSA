#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode 735
//Asteroid collision

// here we need to collide when there is two astroid comes to each other 
// we use data structure like stack to keep track

// first we push positive element 
// whenevener nagative elements comes we collide with top of stack
// and if nagative is large we pop and collide further

// but in actual we don't need stack 
// we can do same in array list so that in the end we don't need to reverse it

// dryrun on using rules given in question
// ans try to think of condition to push and pop
// [4,7,1,1,2,-3,-7,17,15,-16]
// [4,7,1,1,2,-3,-7,17,15,-18,-19]

// after thinking dryrun on this again to better understand

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> v;

    for(auto it:asteroids){
        if(it > 0){
            v.push_back(it);
        }
        else{
            while(v.size() != 0 && v.back() > 0 && v.back() < abs(it)){
                v.pop_back();
            }

            if(v.size() != 0 && v.back() == abs(it)){
                v.pop_back();
            }
            else if(v.size() == 0 or v.back() < 0){
                v.push_back(it);
            }
        }
    }
    return v;
}

int main(){
    return 0;
}