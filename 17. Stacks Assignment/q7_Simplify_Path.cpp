#include<iostream>
#include<stack>
using namespace std;

void buildAns(stack<string>& st,string& ans){
    if(st.empty()){
        return;
    }

    string temp = st.top();
    st.pop();
    buildAns(st,ans);
    ans = ans + temp;
}

string simplifyPath(string path) {
    stack<string> st;

    int i = 0;
    while(i < path.size()){
        int start = i;
        int end = i+1;
        while(end < path.size()  &&   path[end] != '/'){
            end++;
        }

        string minPath = path.substr(start,end-start);
        i = end; //increament of i

        if(minPath == "/" || minPath == "/."){
            continue;
        }
        if(minPath == "/.." && !st.empty()){
            st.pop();
        }
        else if(minPath != "/.."){
            //strirg is like "/a" or "/b"
            st.push(minPath);
        }
    }
    string ans = st.empty() ? "/" : "";
    buildAns(st,ans);
    return ans;
}

int main(){
    string path = "/a/./b/../../c/";
    cout << simplifyPath(path);
    return 0;
}