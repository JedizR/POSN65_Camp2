#include <bits/stdc++.h>

using namespace std;

long long a[1001000],b[1001000];

int main(){
    long long n,q,i,k,mn=1e18;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    b[n+1]=1e18;
    for(i=n;i>=1;i--){
        b[i]=min(b[i+1],a[i]);
    }
    while(q--){
        cin>>k;
        cout<<upper_bound(b+1,b+n+1,k)-(b+1)<<"\n";
    }
}
