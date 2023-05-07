#include <bits/stdc++.h>

using namespace std;

int dp[1000100],a[1000100];

int main(){
    int c,m,i,j;
    cin>>c>>m;
    for(i=1;i<=c;i++){
        cin>>a[i];
    }
    for(i=1;i<=m;i++){
        dp[i]=1e9;
        for(j=1;j<=c;j++){
            if(i-a[j]<0) continue;
            dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
    }
    if(dp[m]==1e9) dp[m]=0;
    cout<<dp[m];
}
