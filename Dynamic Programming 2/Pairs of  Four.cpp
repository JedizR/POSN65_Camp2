#include <bits/stdc++.h>

using namespace std;

char a[1010];
int dp[1010][1010];

int divide(int l,int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    if(a[l]==a[r]) return dp[l][r]=1+divide(l+1,r-1);
    for(int k=l;k<r;++k){
        dp[l][r]=max(dp[l][r],divide(l,k)+divide(k+1,r));
    }
    return dp[l][r];
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<divide(1,n);
}
