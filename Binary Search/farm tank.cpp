#include <bits/stdc++.h>

using namespace std;

int a[1001000];

int main(){
    long long i,n,m,l=0,r=1e18,mid,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(l<r){
        mid=(l+r)/2;
        ans=0;
        for(int i=0;i<n;i++){
            ans+=mid/a[i];
        }
        if(ans>=m) r=mid;
        if(ans<m) l=mid+1;
    }
    cout<<l;
}
