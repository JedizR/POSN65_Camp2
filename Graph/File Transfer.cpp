#include <bits/stdc++.h>

using namespace std;

int visited[100100];
vector <int> adj[100100];

void dfs(int u){
    visited[u]=1;
    for(auto x: adj[u]){
        if(!visited[x])
            dfs(x);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,q,s,e,i;
    cin>>n>>m>>q;
    for(i=0;i<m;i++){
        cin>>s>>e;
        adj[s].push_back(e);
    }
    for(i=0;i<q;i++){
        cin>>s>>e;
        memset(visited,0,sizeof(visited));
        visited[s]=1;
        dfs(s);
        if(visited[e]==1) cout<<"Yes\n";
        else cout<<"No\n";

    }
}
/*
5 5 3
1 2
2 3
1 4
4 5
3 4
3 5
1 3
3 1
*/
