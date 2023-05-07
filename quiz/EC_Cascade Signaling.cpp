#include <bits/stdc++.h>

using namespace std;

int a[2020][2020];
string s[2020][2020];

void recur(int x,int y){

}

int main(){
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>s[i][j];
            if(s[i][j]=='#'){
                a[i][j]=-99;
            }
        }
    }
    cin>>q;
    while(q--){
        cin>>i>>j>>w;
        a[i][j]=w;
        for(ii=1;ii<=w;ii++){
            if(a[i+ii][j])
                a[i+ii][j]=1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=n;j++){
            if(a[i][j]!=0){

            }
        }
    }
}
