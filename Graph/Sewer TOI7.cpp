#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[105][105];
char a[105][105];
int b[105][105];
queue <pair<int,int>> p;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,i,j;
    cin >> n >> m;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            cin >> a[i][j];
            if (a[i][j]=='N') continue;
            else if (a[i][j]=='B'){
                g[i][j].push_back({i+1,j});
                g[i][j].push_back({i,j+1});
                g[i+1][j].push_back({i,j});
                g[i][j+1].push_back({i,j});
            }
            else if(a[i][j]=='D'){
                g[i][j].push_back({i+1,j});
                g[i+1][j].push_back({i,j});
            }
            else if(a[i][j]=='R'){
                g[i][j].push_back({i,j+1});
                g[i][j+1].push_back({i,j});
            }
        }
    }
    memset(b,-1,sizeof b);
    b[1][1]=1;
    p.push({1,1});
    int mn=1e9,ai,aj;
    while(!p.empty())
    {
        int ni=p.front().first;
        int nj=p.front().second;
        p.pop();
        for (auto x : g[ni][nj])
        {
           // cout << ni << " " << nj << " : " << x.first << " " << x.second << "\n";
            if (b[ni][nj]+1>b[x.first][x.second]&&b[x.first][x.second]!=-1) continue;
            if (b[ni][nj]+1==b[x.first][x.second])
            {
                cout << b[x.first][x.second] << "\n" << x.first << " " << x.second;
                return 0;
            }
            b[x.first][x.second]=b[ni][nj]+1;
            p.push({x.first,x.second});
        }
    }
    cout << mn << "\n" << ai << " " << aj;
    return 0;
}
