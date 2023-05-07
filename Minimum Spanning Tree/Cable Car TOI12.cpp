#include <bits/stdc++.h>

using namespace std;

struct A{
    int u,v,w;
    bool operator <(const A &o)const{
        return w>o.w;
    }
};
A a[1000010];
int p[2600];

int fr(int i){
    if(p[i]==i) return i;
    else return p[i]=fr(p[i]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,u,v,w,st,en,i;
    double pp;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        p[i]=i;
    }
    for(i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    cin>>st>>en>>pp;
    sort(a+1,a+m+1);
    int mn=1e9;
    for(i=1;i<=m;i++){
        int ru=fr(a[i].u);
        int rv=fr(a[i].v);
        if(ru!=rv){
            p[ru]=rv;
            mn=min(mn,a[i].w);
        }
        if(p[fr(st)]==p[fr(en)]){
            double res=pp/(mn-1);
            cout<<fixed<<setprecision(0)<<ceil(res)<<"\n";
            break;
        }
    }
}
