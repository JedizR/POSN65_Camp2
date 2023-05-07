#include <bits/stdc++.h>

using namespace std;

long long dp[100100];

pair<long long,long long> a[100100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long q,n,i;
    cin>>q;
    while(q--){
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>a[i].first>>a[i].second;
            a[i].second*=-1;
        }
        sort(a+1,a+1+n);
        long long mx=0,idx;
        for(long long i=1;i<=n;i++){
            idx=upper_bound(dp,dp+mx,a[i].second)-dp;
            if(mx==idx) mx++;
            dp[idx]=a[i].second;
        }
        cout<<mx;
        memset(dp,0,sizeof dp);
    }
}
