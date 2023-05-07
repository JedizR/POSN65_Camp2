#include <bits/stdc++.h>
using namespace std;
queue <pair<int,int>> p,po,p3;
int a[155][155],mark[155][155],dis[155][155],mark2[155][155];
int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
int cnt=0,mn=1e9,ei,ej,n,m;
void play(int i,int j)
{
    p3.push({i,j});
    while (!p3.empty())
    {
        int ni=p3.front().first;
        int nj=p3.front().second;
        p3.pop();
        if (ni==ei&&nj==ej)
        {
            cnt++;
            mn = min(mn,dis[ni][nj]);
        }
        for (int k=0;k<4;k++)
        {
            int ii = ni+di[k];
            int jj = nj+dj[k];
            if (a[ii][jj]==0) continue;
            if (ii>n||ii<1||jj>m||jj<1) continue;
            if (mark2[ii][jj]) continue;
            mark2[ii][jj]=1;
            dis[ii][jj]=dis[ni][nj]+1;
            p3.push({ii,jj});
            /*for(i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                {
                    cout << dis[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "-------------------------------++\n";*/
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int si,sj,i,j;
    cin >> n >> m;
    cin >> si >> sj;
    cin >> ei >> ej;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    memset(dis,-1,sizeof dis);
    dis[si][sj]=1;
    mark[si][sj]=1;
    p.push({si,sj});
    while (!p.empty())
    {
        int ni=p.front().first;
        int nj=p.front().second;
        p.pop();
        for (int k=0;k<4;k++)
        {
            int ii = ni+di[k];
            int jj = nj+dj[k];
            if (ii>n||ii<1||jj>m||jj<1) continue;
            if (mark[ii][jj]) continue;
            mark[ii][jj]=1;
            dis[ii][jj]=dis[ni][nj]+1;
            if (a[ii][jj]==1) p.push({ii,jj});
            else if(a[ii][jj]==0) po.push({ii,jj});
            /*for(i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                {
                    cout << dis[i][j] << " ";
                }
                cout << "\n";
                }
                cout << "-------------------------------\n";*/
        }
    }
    while (!po.empty())
    {
        int ni=po.front().first;
        int nj=po.front().second;
        po.pop();
        memset(mark2,0,sizeof mark2);
        play(ni,nj);
    }
    cout << cnt << "\n" << mn << "\n";
    /*for(i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }*/
    return 0;
}
