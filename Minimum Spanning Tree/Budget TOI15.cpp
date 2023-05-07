#include <bits/stdc++.h>

using namespace std;

const int M=5e5+5;

struct A{
    long long i,j,w,use;
    bool operator < (const A &o) const{
        return w<o.w;
    }
};

A p[M];

pair <long long, long long> roof[300005];
long long cost[1000005],f[5005];
long long fin(long long i){
    if(f[i]==i) return i;
    return f[i]=fin(f[i]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long n,m,r,ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++) f[i]=i;
    for(long long i=1;i<=m;i++){
        cin>>p[i].i>>p[i].j>>p[i].w>>p[i].use;
        if(p[i].use){
            long long ru=fin(p[i].i),rv=fin(p[i].j);
            if(ru!=rv) f[ru]=rv;
        }
    }
    cin>>r;
    for(long long i=1;i<=r;i++){
        cin>>roof[i].first>>roof[i].second;
    }
    sort(roof+1,roof+r+1);
    memset(cost,127,sizeof cost);
    roof[r+1].second=1e9;
    for(long long i=r;i>=1;i--){
        roof[i].second=min(roof[i].second,cost[roof[i].first]);
        cost[roof[i].first]=min(roof[i].second,cost[roof[i].first]);
    }
    for(long long i=1000000;i>=1;i--){
        cost[i]=min(cost[i],cost[i+1]);
    }
    sort(p+1,p+m+1);
    for(long long i=1;i<=m;i++){
        long long ru=fin(p[i].i),rv=fin(p[i].j);
        if(ru!=rv) ans+=cost[p[i].w],f[ru]=rv;
    }
    cout<<ans<<"\n";
}
