#include <bits/stdc++.h>

using namespace std;

int a[100010],b[100010],ch[100010];

struct aa{
    int v,ind;
    bool operator < (const aa &o) const{
        if(v!=o.v)
            return v<o.v;
    }
};

priority_queue <aa> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q,n,k,i;
    cin>>q;
    while(q--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ch,0,sizeof(ch));
        int mx=-1e9,mn=1e9,ans=0;
        cin>>n>>k;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(i!=0){
                b[i]=abs(a[i]-a[i-1]);
                pq.push({b[i],i});
            }
        }
        for(i=1;i<k;i++){
            ch[pq.top().ind]=1;
            pq.pop();
        }
        while(!pq.empty()){
            pq.pop();
        }
        for(i=0;i<n;i++){
            if(ch[i]==1){
                ch[i]=0;
                ans+=mx-mn;
                mx=-1e9;
                mn=1e9;
            }
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        ans+=mx-mn;
        cout<<ans<<"\n";
    }
}
/*
2
9 3
2 2 4 5 6 8 10 11 17
9 3
97 99 101 50 54 45 20 17 14
*/
