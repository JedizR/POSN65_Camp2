#include <bits/stdc++.h>

using namespace std;

typedef pair <int,int> pii;

priority_queue <pii> h;

int dp[500100];

int main(){
    int n,k,a,i,num;
    cin>>n>>k;
    cin>>a;
    dp[1]=a;
    h.push({-a,1});
    for(i=2;i<=n;i++){
        cin>>num;
        while(!h.empty()&&i-h.top().second>k){
            h.pop();
        }
        dp[i]=-(h.top().first)+num;
        h.push({-dp[i],i});
    }
    cout<<dp[n];
}
