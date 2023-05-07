#include <bits/stdc++.h>

using namespace std;

priority_queue <int> q;
vector <int> g[50010];
int ans[50010],dgin[50010];

void add(int u,int v){
    ++dgin[v],g[u].push_back(v);
}

void solve(){
    int n,m,sw=-1,cnt=0,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>v>>u,add(u,v);
    for(int i=1;i<=n;i++){
        if(!dgin[i]) q.push(-i);
    }
    while(!q.empty()){
        int nowi=q.top();
        q.pop();
        nowi*=-1;
        if(q.size()>=1) sw=nowi;
        ans[++cnt]=nowi;
        for(auto x:g[nowi]){
            --dgin[x];
            if(!dgin[x]) q.push(-x);
        }
    }
    if(cnt!=n){
        cout<<"Never\n";
    }
    else{
        (sw==-1)?cout<<"Same ":cout<<"Different ";
        for(int i=n;i>=1;i--) if(sw==ans[i]) swap(ans[i],ans[i+1]);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    while(!q.empty()) q.pop();
    memset(dgin,0,sizeof dgin);
    memset(ans,0,sizeof ans);
    for(int i=1;i<=n;i++) g[i].clear();
}
int main(){
    int q;
    cin>>q;
    while(q--)
        solve();
}
