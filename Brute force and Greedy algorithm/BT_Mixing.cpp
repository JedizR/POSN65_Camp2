#include <bits/stdc++.h>

using namespace std;

long long a[1000010];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long q,n,k,i;
    cin>>q;
    while(q--){
        long long ans=0;
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        for(i=2;i<=n;i++){
            ans+=max(a[i],a[i-1]);
        }
    cout<<ans<<"\n";
    }
}
