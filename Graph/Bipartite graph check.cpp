#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200100];
int c[200100];

queue<int> q;

int main() {
    int n,m,i,u,v,st,qq,ch;
    cin>>qq;
    while(qq--)
    {
        ch=1;
        cin >>n>>m;
        for (i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(u%2==1){
                st=u;
            }
        }
        memset(c, -1, sizeof(c));
        while(!q.empty()){
            q.pop();
        }
        q.push(st);
        c[st]=0;
        while (!q.empty()) {
        int uu = q.front();
            q.pop();
            for (auto x : adj[uu]){
                if (c[x]==-1) {
                    c[x]=1-c[uu];
                    q.push(x);
                }
                else if(c[x]==c[uu]&&c[x]!=-1){
                    ch=0;
                }
            }
        }
        if(ch) cout<<"yes\n";
        else cout<<"no\n";
        memset(adj,0,sizeof(adj));
    }
}
/*
2
4 4
1 2
2 3
3 4
4 1
3 3
1 2
2 3
3 1
*/

