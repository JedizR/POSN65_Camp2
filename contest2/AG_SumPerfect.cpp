#include <bits/stdc++.h>

using namespace std;

struct a{
    unsigned long long v;
    bool operator < (const a &o) const{
        return v>o.v;
    }
};

priority_queue <a> pq;
string s;

stack <unsigned long long> st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    unsigned long long q,n,x,y,i,aa;
    cin>>q;
    while(q--){
        while(!st.empty()){
            st.pop();
        }
        cin>>n;
        for(i=0;i<n;i++){
            cin>>aa;
            pq.push({aa});
        }
        while(!pq.empty()){
            x=pq.top().v;
            //cout<<x;
            pq.pop();
            if(pq.empty()){
                st.push({x});
            }
            if(x==pq.top().v){
                pq.pop();
            }
            else{
                st.push(x);
            }
        }
        cout<<st.top()+1-st.size()<<"\n";

        //cout<<st.top().v*-1<<"\n";

    }
}
