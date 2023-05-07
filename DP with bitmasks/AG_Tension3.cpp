#include <bits/stdc++.h>

using namespace std;

const int MXN=1e4+10;
int d[(1<<8)][MXN];

struct graph{
    int v,w,st;
    bool operator < (const graph &o) const{
        return w>o.w;
    }
};
vector <graph> adj[MXN];
priority_queue <graph> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,s,q;
    cin>>n>>m>>s>>q;
    for(int i=0;i<(1<<8);++i){
        for(int j=0;j<=n;++j){
            d[i][j]=1e9;
        }
    }
    d[0][s]=0;
    while(m--){
        int u,v,w,k;
        cin>>u>>v>>w>>k;
        adj[u].push_back({v,w,1<<(k-1)});
        adj[v].push_back({u,w,1<<(k-1)});
    }
    pq.push({s,0,0});
    while(!pq.empty()){
        int u=pq.top().v,w=pq.top().w,st=pq.top().st;
        pq.pop();
        for(auto x : adj[u]){
            if(d[st|x.st][x.v]>w+x.w){
                d[st|x.st][x.v]=w+x.w;
                pq.push({x.v,w+x.w,st|x.st});
            }
        }
    }
    while(q--){
        int e,k,num=0;
        cin>>e>>k;
        for(int i=0,x;i<k;++i){
            cin>>x;
            num|=1<<(x-1);
        }
        int mn=1e9;
        for(int i=0;i<(1<<8);++i)
            if((num&i)==0&&d[i][e]!=1e9) mn=min(mn,d[i][e]);
        cout<<(mn!=1e9?mn:-1)<<"\n";
    }
}
