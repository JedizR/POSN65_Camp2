#include <bits/stdc++.h>

using namespace std;

stack <char> st;
int lv[1000100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int n,i,j,k=0,cnt=1,mxcnt=0;
    cin>>n;
    cin>>s;
    int len=s.length();
    for(i=0;i<len;i++){
        if(s[i]=='('){
            st.push(s[i]);
            k++;
        }
        else if(s[i]==')'){
            int mx=0;
            while(st.top()!='('){
                int a=st.top();
                mx=max(mx,a);
                st.pop();
            }
            lv[mx+1]++;
            st.pop();
            st.push(mx+1);
            mxcnt=max(mxcnt,mx+1);
        }
    }
    cout<<k<<"\n"<<mxcnt<<"\n";
    for(i=1;i<=mxcnt;i++){
        cout<<lv[i]<<" ";
    }
}
