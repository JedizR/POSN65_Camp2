#include <bits/stdc++.h>

using namespace std;

int g[510][510];

int main(){
    int n,m,i,j,k,s,e,w;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            g[i][j]=200000000;
        }
    }
    while(m--){
        cin>>s>>e>>w;
        if(w<g[s][e]){
            g[s][e]=w;
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<n;j++){
            (g[i][j]==200000000)?cout<<"0 ":cout<<g[i][j]<<" ";
        }
        (g[i][j]==200000000)?cout<<"0\n":cout<<g[i][j]<<"\n";
    }
}
