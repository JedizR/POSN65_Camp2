#include <bits/stdc++.h>

using namespace std;

int a[510][510];

int main(){
    int n,i,j,k;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j]=a[i][j]|(a[i][k]&a[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            (j!=n)?cout<<a[i][j]:cout<<a[i][j]<<"\n";
        }
    }
}
