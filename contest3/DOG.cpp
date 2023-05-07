#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    int n,q,idx,a,i;
    cin>>n>>q;
    cin>>s;
    s=" "+s;
    for(i=1;i<=n;i++){
        if(s[i]=='D') idx=i;
    }
    while(q--){
        cin>>a;
        if(a<idx){
            cout<<0<<"\n";
        }
        else if(a==idx){
            cout<<1<<"\n";
        }
        else{
            cout<<2<<"\n";
        }
    }
}
