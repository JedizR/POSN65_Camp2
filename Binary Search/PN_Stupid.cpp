#include <bits/stdc++.h>

using namespace std;

int main(){
    long long q,s,p,i;
    cin>>q;
    long long l=0,r=1e18,mid,a,b,ch;
    while(q--){
        cin>>s>>p;
        r=s/2+1;
        ch=0;
        l=0,r=s/2+1;
        while(l<r){
            mid=(l+r)/2;
            a=mid;
            b=s-mid;
            if(a*b/b!=a) r=mid;
            else if(a*b<p) l=mid+1;
            else r=mid;
            if(a*b==p){
                ch=1;
                break;
            }
        }
        if(ch==1){
            cout<<mid<<" "<<s-mid<<"\n";
        }
        else cout<<"No answer\n";
    }
}
