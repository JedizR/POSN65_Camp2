#include <bits/stdc++.h>

using namespace std;

int visited[1010][1010],di[4]={-1,0,1,0},dj[4]={0,1,0,-1},r,c;


queue <pair<int,int>> q;


char t[1010][1010];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int qq,i,j,ie,je;
    cin>>qq;
    while(qq--){
        while(!q.empty()){
            q.pop();
        }
        memset(visited,-1,sizeof(visited));
        cin>>r>>c;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin>>t[i][j];
                if(t[i][j]=='A'){
                    q.push({i,j});
                    visited[i][j]=0;
                    //cout<<q.top().first<<q.top().second;
                }
                if(t[i][j]=='B'){
                    ie=i,je=j;
                }
            }
        }
        /*for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cout<<visited[i][j];
            }
            cout<<"\n";
        }*/
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                if(t[x+di[k]][y+dj[k]]=='#'||x+di[k]<0||x+di[k]>=r||y+dj[k]<0||y+dj[k]>=c) continue;
                if(visited[x+di[k]][y+dj[k]]!=-1) continue;
                q.push({x+di[k],y+dj[k]});
                visited[x+di[k]][y+dj[k]]=visited[x][y]+1;
            }
        }
        cout<<visited[ie][je]<<"\n";
    }
}
/*
2
4 5
#A.#.
..#.B
.#..#
....#
4 5
#A.#.
..#.B
.#..#
..#.#
*/
