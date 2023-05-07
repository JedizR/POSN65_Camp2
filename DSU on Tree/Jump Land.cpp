#include <bits/stdc++.h>

using namespace std;

struct merge_t{
    int u,v;
    double t;
    bool operator < (const merge_t& o) const{
        return t<o.t;
    }
};

const int MxN=770;
int parent[MxN*MxN],sze[MxN*MxN],h[MxN*MxN],v[MxN*MxN];
int ans;

vector <merge_t> merge_time;
stack <pair<int,int>> opr;

int fr(int u){
    while(u!=parent[u]){
        u=parent[u];
    }
    return u;
}

void rollback(){
    while(!opr.empty()){
        pair<int,int> now=opr.top();
        opr.pop();
        sze[now.first]-=sze[now.second];
        parent[now.second]=now.second;
    }
}

void getMergeTime(int a,int b){
    if(v[a]!=v[b]){
        double t=(double)(h[b]-h[a])/(v[a]-v[b]);
        if(t<0){
            return;
        }
        merge_time.push_back({a,b,t});
    }
    else if(h[a]==h[b]){
        int ra=fr(a);
        int rb=fr(b);
        if(ra==rb) return;
        ans=max(ans,sze[ra]+sze[rb]);
        if(sze[ra]>sze[rb]){
            sze[ra]+=sze[rb];
            parent[rb]=ra;
        }
        else{
            sze[rb]+=sze[ra];
            parent[ra]=rb;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n*n;++i){
        cin>>h[i];
        parent[i]=i;
        sze[i]=1;
    }
    for(int i=0;i<n*n;++i){
        cin>>v[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i+1<n){
                getMergeTime(i*n+j,(i+1)*n+j);
            }
            if(j+1<n){
                getMergeTime(i*n+j,i*n+j+1);
            }
        }
    }
    merge_time.push_back({0,0,-1});
    sort(merge_time.begin(),merge_time.end());
    for(int i=1;i<(int)merge_time.size();++i){
        if(merge_time[i-1].t!=merge_time[i].t){
            rollback();
        }
        int ru=fr(merge_time[i].u);
        int rv=fr(merge_time[i].v);
        if(ru==rv) continue;
        ans=max(ans,sze[ru]+sze[rv]);
        if(sze[ru]>sze[rv]){
            sze[ru]+=sze[rv];
            parent[rv]=ru;
            opr.emplace(ru,rv);
        }
        else{
            sze[rv]+=sze[ru];
            parent[ru]=rv;
            opr.emplace(rv,ru);
        }
    }
    cout<<ans;
}
