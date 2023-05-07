#include <bits/stdc++.h>

using namespace std;

queue <int> st;
int lv[1000100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,cnt=0;
    string s;
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++){
        if(s[i]=='('){
            st.push(s[i]);
            cnt++;
        }
        else if(s[i]==')'){
            int mx=0;
            if(st.top()=='('){
                st.pop();
                st.push();
            }
        }
    }
}
