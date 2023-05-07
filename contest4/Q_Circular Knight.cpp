#include <bits/stdc++.h>

using namespace std;

long long a[100100],dp[100100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long n,i,mn=1e9,ch=0,sum=0,total=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=a[i]+dp[i-1];
        mn=min(mn,dp[i]);
    }
    for(i=n;i>0;i--){
        if(ch==1&&dp[i]>=0){
            total=mn-dp[i];
            break;
        }
        if(dp[i]==mn){
            ch=1;
        }
    }
    //cout<<total<<" "<<ans<<"\n";
    cout<<dp[n]-2*total;
}
