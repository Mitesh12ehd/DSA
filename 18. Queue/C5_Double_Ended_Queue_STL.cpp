#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> q;
    
    q.push_front(10);
    q.push_front(20);
    q.push_back(30);
    q.push_back(40);

    cout << "size = " << q.size() << endl;

    q.pop_front();
    q.pop_back();

    cout << "size = " << q.size() << endl;
    cout << q.empty() << endl;
    return 0;
}