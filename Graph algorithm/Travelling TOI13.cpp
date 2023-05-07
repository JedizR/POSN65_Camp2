#include <bits/stdc++.h>

using namespace std;

struct A{
    int v,w;
    bool operator < (const A &o) const{
        return w>o.w;
    }
};

A now;
priority_queue <A> pq;
vector <A> g[10100];
int dis[10100],disR[10100];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,u,v,w,st,en,limit;
    cin>>n>>m>>st>>en>>limit;
    while(m--){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<n;i++){
        dis[i]=1e9;
    }
    dis[st]=0;
    pq.push({st,0});
    while(!pq.empty()){
        now=pq.top();
        pq.pop();
        for(auto x: g[now.v]){
            if(now.w+x.w<dis[x.v]){
                dis[x.v]=now.w+x.w;
                pq.push({x.v,dis[x.v]});
            }
        }
    }
    int res=dis[en];
    if(dis[en]<=limit){
        cout<<en<<" "<<dis[en]<<" 0\n";
        return 0;
    }
    int minn=1e9,pos=en;
    for(int i=0;i<n;i++){
        disR[i]=1e9;
    }
    disR[en]=0;
    pq.push({en,0});
    while(!pq.empty()){
        now=pq.top();
        pq.pop();
        for(auto x: g[now.v]){
            if(now.w+x.w<disR[x.v]){
                disR[x.v]=now.w+x.w;
                pq.push({x.v,disR[x.v]});
                if(disR[x.v]<=minn&&dis[x.v]<=limit){
                    if(disR[x.v]==minn) pos=min(pos,x.v);
                    else pos=x.v;
                    minn=min(minn,disR[x.v]);
                }
            }
        }
    }
    cout<<pos<<" "<<dis[pos]<<" "<<minn<<"\n";
}
