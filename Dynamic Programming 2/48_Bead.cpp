#include <bits/stdc++.h>

using namespace std;

int n,c[110][110],dp[110][110];

int main(){
    int i,j,k,l,temp,run,q,mn;
    cin>>q;
    while(q--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>c[i][i];
        }
        for(l=2;l<=n;l++){
            for(i=0;i<n-l+1;i++){
                j=i+l-1,mn=2100000000;
                for(k=i;k<=j-1;k++){
                    temp=dp[i][k]+dp[k+1][j]+c[i][k]*c[k+1][j];
                    if(temp<mn){
                        c[i][j]=(c[i][k]+c[k+1][j])%100;
                        mn=temp,dp[i][j]=mn;
                    }
                }
            }
        }
        cout<<dp[0][n-1]<<"\n";
    }
}
