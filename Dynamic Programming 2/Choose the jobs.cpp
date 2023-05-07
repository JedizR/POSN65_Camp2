#include <bits/stdc++.h>

using namespace std;

struct A{
    int s,e,w;
    bool operator < (const A &o) const{
        return e<o.e;
    }
};

A a[100100];
int dp[100100],b[100100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].s>>a[i].e>> a[i].w;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        b[i]=a[i].e;
    }
    for(i=1;i<=n;i++){
        int ind=lower_bound(b+1,b+1+n,a[i].s)-b-1;
        dp[i]=max(dp[i-1],dp[ind]+a[i].w);
    }
    cout<<dp[n];
}
