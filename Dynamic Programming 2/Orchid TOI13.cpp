#include <bits/stdc++.h>

using namespace std;                                                                                                                          ;

int  a[1001000],dp[1001000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,mx=0,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        int idx=upper_bound(dp,dp+mx,a[i])-dp;
        if(idx==mx) mx++;
        dp[idx]=a[i];
    }
    cout<<n-mx<<"\n";
}
