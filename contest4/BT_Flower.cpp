#include <bits/stdc++.h>

using namespace std;

stack <int> st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q,a,b;
    cin>>q;
    while(q--){
        cin>>a;
        if(a==1){
            cin>>b;
            st.push(b);
        }
        if(a==2){
            if(!st.empty()){
                cout<<st.top()<<"\n";
                st.pop();
            }
            else{
                cout<<"-1\n";
            }
        }
    }
}
/*
15
1 7
2
2
1 11
1 8
1 9
2
2
1 10
2
2
1 7
1 6
2
2
*/
