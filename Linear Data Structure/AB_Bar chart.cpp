#include <bits/stdc++.h>

using namespace std;

int l[100100],r[100100],a[100100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,q,mx,i,ans;
    cin>>q;
    while(q--){
        mx=0;
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            l[i]=i-1;
            while(l[i]>0&&a[i]<=a[l[i]]){
                l[i]=l[l[i]];
            }
        }
        for(i=n;i>=1;i--){
            r[i]=i+1;
            while(r[i]<=n&&a[i]<=a[r[i]]){
                r[i]=r[r[i]];
            }
        }
        for(i=0;i<n;i++){
            ans=max(ans,a[i]*(r[i]-l[i]-1));
        }
        cout<<ans<<"\n";
    }
}
