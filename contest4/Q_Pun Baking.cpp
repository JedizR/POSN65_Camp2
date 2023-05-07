#include <bits/stdc++.h>

using namespace std;

struct A{
    int v,w;
    bool operator < (const A &o) const{
        if(w!=o.w) return w>o.w;
    }
};

vector <A> adj[50050];

priority_queue <A> pq;

int pp[30];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,p,k,i,j;
    cin>>n>>m>>p>>k;
    for(i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(i=0;i<p;i++){
        cin>>pp[i];
    }
}
