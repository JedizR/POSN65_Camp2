#include <bits/stdc++.h>

using namespace std;

int p[100100]

int fr(int i){
    if(p[i]==i) return i;
    return p[i]=fr(p[i]);
}

int main(){
    int opr,x,y,i,n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        p[i]=-1;
    }
    for(i=1;i<=m;i++){
        cin>>opr>>x>>y;
        fx=fr[x];
        fy=fr[y];
        if(opr==1){
            if(fx==-1&&fy==-1){
                fx=1;
            }
        }
        else{

        }
    }
}
