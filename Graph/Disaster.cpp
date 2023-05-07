#include <bits/stdc++.h>
using namespace std;
int mark[3333][3333];
vector <int> g[3333],v;
int m,dg[3333];
void dfs(int now){
    //cout << (char)(now+'A') << " " << st.size() << '\n';
    v.push_back(now);
    if(v.size()==m+1){
        for(auto x : v){
            cout << (char)(x+'A') << " ";
            //cout << "hiii";
        }
        exit(0);
    }
    for(auto x : g[now]){
        if(mark[now][x]) continue;
        mark[now][x]=1;
        mark[x][now]=1;

        dfs(x);
        mark[now][x]=0;
        mark[x][now]=0;

    }v.pop_back();
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int i,mx=0;
    char stt;
    cin >> m;
    for(i=1;i<=m;i++){
        char u,v;
        cin >> u >> v;
        g[u-'A'].push_back(v-'A');
        g[v-'A'].push_back(u-'A');
        dg[u-'A']++;
        dg[v-'A']++;
    }
    int ch=0;

    for (i=0;i<=25;i++)   sort(g[i].begin(),g[i].end());
    for(i=0;i<=25;i++){
        if(dg[i]%2==1){
            stt=i;
            ch=1;
            break;
        }
    }
    if(!ch){
        for(i=0;i<=25;i++){
            if(dg[i]%2==0&&dg[i]>0){
                stt=i;
                break;
            }
        }
    }
    //v.push_back(stt);

    dfs(stt);
    return 0;
}
/*
4
AB
DA
BC
DC
*/
