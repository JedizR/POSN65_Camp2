#include <bits/stdc++.h>
using namespace std;
struct A{
    int i,j,num;
};
queue <A> p;
int di[]={0,1,-1,0,0};
int dj[]={0,0,0,1,-1};
int dis[2010][2010];
char a[2010][2010];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,i,j,sum=0,cnt=0;
    memset(dis,127,sizeof dis);
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]=='X'){
                dis[i][j]=0;
                p.push({i,j,0});
            }
        }
    }
    while(!p.empty()){
        int ni=p.front().i;
        int nj=p.front().j;
        int now=p.front().num;
        p.pop();

        if(a[ni][nj]=='A') cnt++,sum+=now*2;
        for(int k=1;k<=4;k++){
            int ii=ni+di[k];
            int jj=nj+dj[k];

            if(ii<1||ii>n||jj<1||jj>m) continue;
            if(a[ii][jj]=='W') continue;
            if(dis[ni][nj]+1<dis[ii][jj]){
                dis[ii][jj]=dis[ni][nj]+1;
                p.push({ii,jj,now+1});
            }
        }
    }
    cout << cnt << ' ' << sum << '\n';
    return 0;
}
