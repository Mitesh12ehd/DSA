#include<iostream>
using namespace std;

// Leetcode 2311
// Longest Binary Subsequence Less Than or Equal to K

// Zeros are “free.”
// Adding a 0 to a binary string never changes its numeric value, so every zero you can keep only helps the length and never hurts the ≤ k condition.

// Among all 1-bits, the least-significant ones are cheapest.
// Including a 1 that sits p places from the right adds 2^p to the value. 
// A bit further left adds at least twice as much. Therefore, 
// if you want to squeeze in as many bits as possible without exceeding k, 
// it makes sense to take 1s starting with the right-most (cheapest) positions 
// and stop as soon as the running value would pass k.

// 1	Count every 0 in the string ― you can always keep those.
// 2	Scan the string right → left keeping a running number val (initially 0) and a power index pow (0,1,2,…). Whenever you see a 1, check if val + (1 « pow) ≤ k. If yes, include that 1 and add to val; if not, skip it.
// 3	Increment pow after looking at each position. (You can break early once 1 « pow > k, because any further left bit would already exceed k by itself.)
// 4	Return zerosKept + onesIncluded.

int longestSubsequence(string s, int k) {
    int val = 0;
    int taken = 0;
    int pow = 1;

    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == '0'){
            taken++;
        }
        else{
            //pow <= k, to avoid overflow
            if(pow <= k && val + pow <= k){
                taken++;
                val = val + pow;
            }
        }

        // check condition to avoid overflow
        if(pow <= k){
            pow = pow * 2;
        }
    }

    return taken;
}

int main(){
    return 0;
}