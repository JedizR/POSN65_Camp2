#include <bits/stdc++.h>

using namespace std;

queue <pair<int,int>> q;
char t[2020][2020];
int di[8]={-1,-1,-1,0,1,1,1,0},dj[8]={-1,0,1,1,1,0,-1,-1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int m,n,i,j,ans=0;
    cin>>m>>n;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>t[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(t[i][j]=='1'){
                ans++;
                q.push({i,j});
                while(!q.empty()){
                    int x=q.front().first,y=q.front().second;
                    q.pop();
                    if(t[x][y]=='0'){
                        continue;
                    }
                    t[x][y]='0';
                    for(int k=0;k<8;k++){
                        int ii=x+di[k],jj=y+dj[k];
                        if(ii<0||ii>=m||jj<0||jj>=n) continue;
                        if(t[ii][jj]=='1'){
                            q.push({ii,jj});
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
}
/*
4 5
10011
00001
01100
10011
*/
