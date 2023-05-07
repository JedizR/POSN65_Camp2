#include <bits/stdc++.h>
using namespace std;
long long a[100010];
vector<int> g[100010];
long long sum,mn;
void dfs(int now,int last){
    //cout << "HIII\n";
    for(auto x: g[now]){
        if(x==last) continue;
        dfs(x,now);
        a[now]+=a[x];
    }
    mn=min(mn,abs(sum-(2*a[now])));
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q,i;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        sum=0,mn=1e18;
        for(i=1;i<=n-1;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(i=1;i<=n;i++){
            cin >> a[i];
            sum+=a[i];
        }
        dfs(1,0);
        cout << mn << '\n';
        for(i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}
