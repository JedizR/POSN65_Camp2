#include <bits/stdc++.h>

using namespace std;

int a[1010][1010],dp[1010][1010];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int m,n,i,j,k,mx=-1e9;
    cin>>m>>n>>k;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
            dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            if(i>=k&&j>=k){
                mx=max(mx,dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
            }
        }
    }
    /*for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<mx;
}
/*
5 10
2
5 9 2 9 1 2 8 9 1 6
9 1 3 9 8 4 2 1 5 7
2 7 9 3 8 5 2 7 6 8
1 6 2 1 7 7 1 9 4 1
8 5 2 3 9 8 5 6 3 3
*/
