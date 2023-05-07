#include <bits/stdc++.h>

using namespace std;

long long a[2001000],b[2001000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long n,mx= 0,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    long long l=0,r=mx,mid,idx,ch;
    while(l<r){
        mid=(l+r)/2,idx=1,ch=1;
        for(i=1;i<=n;i++){
            if(a[i]<=mid) continue;
            b[idx++]=a[i];
        }
        for(i=1;i<idx;i+=2){
            if(b[i]!=b[i+1]){
                ch=0;
                break;
            }
        }
        if(ch) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
}
