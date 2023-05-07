#include <bits/stdc++.h>

using namespace std;

int p[100100];

int fr(int i){
    if(p[i]==i) return i;
    return p[i]=fr(p[i]);
}

int main(){
    char c;
    int n,q,a,b,i,ra,rb;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        p[i]=i;
    }
    while(q--){
        cin>>c>>a>>b;
        ra=fr(a);
        rb=fr(b);
        if(c=='c'){
            p[rb]=ra;
        }
        else{
            if(ra==rb) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
}
/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1
*/
