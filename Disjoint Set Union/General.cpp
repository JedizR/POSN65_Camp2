#include <bits/stdc++.h>

using namespace std;

int p[100100],v[100100];

int fr(int i){
    if(p[i]==i) return i;
    return p[i]=fr(p[i]);
}

int main(){
    int n,m,i,a,b,ra,rb;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>v[i];
        p[i]=i;
    }
    for(i=1;i<=m;i++){
        cin>>a>>b;
        ra=fr(a);
        rb=fr(b);
        if(ra==rb){
            cout<<"-1\n";
        }
        else if(v[ra]==v[rb]){
            if(ra<rb){
                v[ra]+=v[rb]/2;
                p[rb]=ra;
                cout<<ra<<"\n";
            }
            else{
                v[rb]+=v[ra]/2;
                p[ra]=rb;
                cout<<rb<<"\n";
            }
        }
        else if(v[ra]>v[rb]){
            v[ra]+=v[rb]/2;
            p[rb]=ra;
            cout<<ra<<"\n";
        }
        else if(v[ra]<v[rb]){
            v[rb]+=v[ra]/2;
            p[ra]=rb;
            cout<<rb<<"\n";
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
