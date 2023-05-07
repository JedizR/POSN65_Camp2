#include <bits/stdc++.h>

using namespace std;

int dp[2020][2020],path[2020][2020];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int i,j;
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    a=" "+a;
    b=" "+b;
    for(i=1;i<=n;++i){
        for(j=0;j<=m;++j){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                path[i][j]=1;
            }
            else if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                path[i][j]=2;
            }
            else{
                dp[i][j]=dp[i][j-1];
                path[i][j]=3;
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    i=n,j=m;
    if(dp[i][j]==0){
        cout<<"No Roma word";
        return 0;
    }
    vector <char> ans;
    while(i>0&&j>0){
        if(path[i][j]==1){
            ans.push_back(a[i]);
            i--,j--;
        }
        else if(path[i][j]==2){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x;
    }
    cout<<"\n";
}
