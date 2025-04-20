#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Leetcode 901
//Online stock span

//see notes
//here we use concept of monotonic stack

//method 1
// class StockSpanner {
// public:
//     vector<int> v;
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         int count = 0;
//         v.push_back(price);
//         for(int i=v.size()-1; i>=0; i--){
//             if(v[i] <= price){
//                 count++;
//             }
//             else{
//                 break;
//             }
//         }
//         return count;
//     }
// };

//method 2
class StockSpanner {
    public:
        stack<pair<int,int>> st;

        StockSpanner() {
            
        }
        
        int next(int price) {
            int span = 1;
            while(!st.empty() && st.top().first <= price){
                span = span + st.top().second;
                st.pop();
            }
            st.push({price,span});
            return span;
        }
};
int main(){
    return 0;
}