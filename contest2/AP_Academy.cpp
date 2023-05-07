#include <bits/stdc++.h>

using namespace std;

int dp[1001000],dp2[1001000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long n,k,p,mx=-1e9,i,a,b,q;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a>>b;
        mx=max(mx,b);
        dp[a]++;
        dp[b+1]--;
        dp2[b+1]++;
    }
    for(i=1;i<=mx+2;i++){
        dp[i]+=dp[i-1];
        dp2[i]+=dp2[i-1];
    }
    /*for(i=1;i<=mx+2;i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    for(i=1;i<=mx+2;i++){
        cout<<dp2[i]<<" ";
    }*/
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<dp[b]+(dp2[b]-dp2[a])<<"\n";
    }
}
/*
4
1 4
3 5
4 8
7 10
4
4 4
1 10
5 8
1 3
*/
