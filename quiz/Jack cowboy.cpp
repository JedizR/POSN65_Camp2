#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100000];
int visited[100100],root[100000];

int fr(int i){
    if(p[i]==i) return i;
    return p[i]=fr(p[i]);
}

void dfs(int u,int p){
    fr[u]=fr[p];
    for(auto x:adj[u]){
        dfs(x,u);
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q,i,a,b;
    cin>>n>>q;
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);

    }
    for(i=0;i<q;i++){
        memset(visited,0,sizeof(visited));
        cin>>a;
        if(a==0){
            cin>>b;
            dfs(b,b);
        }
        else{
            cin>>b;

        }
    }
}
/*
9 6
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8
1 3
0 8
1 6
1 7
0 2
1 9
*/
