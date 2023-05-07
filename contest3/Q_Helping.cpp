
#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100010];
int visited[100010];
queue <int> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n=0,m,k,s,i,u,v,cnt=0,qq,ch=0;
    cin>>qq;
    while(qq--){
        for(i=1;i<=n;i++){
            while(!adj[i].empty()){
                adj[i].pop_back();
            }
        }
        memset(visited,0,sizeof(visited));
        cnt=0,ch=0;
        cin>>n>>m>>k>>s;
        for(i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        q.push(s);
        while(!q.empty()){
            cnt++;
            u=q.front();
            q.pop();
            visited[u]++;
            if(visited[u]>=k){
                cout<<cnt<<" "<<u<<"\n";
                ch=1;
                break;
            }
            for(auto x:adj[u]){
                q.push(x);
            }
        }
        if(ch==0)
        cout<<"-1\n";
    }
}
/*
2
5 6 2 1
1 2
2 4
4 1
1 3
3 5
5 1
3 3 2 1
1 2
2 4
1 4
*/
