#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100100];
int visited[100100],cnt=0;
string s="2";


vector <int> ve;

void dfs(int i, int p){
    visited[i]=1;
    for(auto x:adj[i]){
        if(!visited[x]){
            s+=to_string(x);
            dfs(x,i);
            s.pop_back();
        }
        if(x==2){
            s+="2";
            ve.push_back(stoi(s));
            s.pop_back();
            cnt++;
            //cout<<s+"2"<<"\n";
        }
    }
    visited[i]=0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,i,u,v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i=0;i<n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    dfs(2,2);
    sort(ve.begin(),ve.end());
    for(i=0;i<cnt;i++){
        cout<<ve[i]<<"\n";
    }
}
/*
6
1 2
1 3
1 4
2 3
3 4
3 5
*/
