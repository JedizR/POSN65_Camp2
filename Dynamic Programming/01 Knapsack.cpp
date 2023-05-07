#include <bits/stdc++.h>

using namespace std;

int w[200],v[200],dp[200][20000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(j<w[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
}
