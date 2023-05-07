#include <bits/stdc++.h>

using namespace std;

int l[15],r[15],path[15][15],dp[15][15];

void prin(int l,int r){
    if(l==r){
        cout<<"A"<<l+1;
        return;
    }
    cout<<"(";
    prin(l,path[l][r]);
    cout<<" x ";
    prin(path[l][r]+1,r);
    cout<<")";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,now;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    for(int m=1;m<n;m++){
        for(int i=0;i+m<n;i++){
            int j=i+m;
            int mi=1<<30;
            for(int k=i;k<j;k++){
                now=dp[i][k]+dp[k+1][j]+l[i]*r[k]*r[j];
                if(now<mi){
                    mi=now;
                    path[i][j]=k;
                }
            }
            dp[i][j]=mi;
        }
    }
    cout<<dp[0][n-1]<<"\n";
    prin(0,n-1);
}
