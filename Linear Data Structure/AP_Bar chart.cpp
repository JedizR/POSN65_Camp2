#include <bits/stdc++.h>

using namespace std;

int l[100100],r[100100],n,q;
long long a[100100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int i;
    cin>>q;
    while(q--){
        cin>>n;
        long long mx=0;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        for(i=1;i<=n;i++){
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
        for(i=1;i<=n;i++){
            mx=max(mx,a[i]*(r[i]-l[i]-1));
        }
        cout<<mx<<"\n";
    }
}
