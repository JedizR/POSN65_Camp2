#include <bits/stdc++.h>

using namespace std;

int l[100100],r[100100],a[100100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q,n,i,sum,ans,mx;
    cin>>q;
    while(q--){
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        mx=ans=-1e9;
        for(i=1,sum=0;i<=n;i++){
            sum+=a[i];
            sum=max(sum,0);
            mx=max(sum,mx);
            l[i]=mx;
        }
        mx=ans=-1e9;
        for(i=n,sum=0;i>=1;i--){
            sum+=a[i];
            sum=max(sum,0);
            mx=max(sum,mx);
            r[i]=mx;
        }
        for(i=1;i<=n;i++){
            ans=max(ans,l[i]+r[i+1]);
        }
        cout<<ans<<"\n";
    }
}
