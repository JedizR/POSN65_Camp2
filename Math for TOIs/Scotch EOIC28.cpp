#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a,b,n,sum=0,p,x,y,chk[4]={0};
    cin>>n>>a>>b;
    for(p=1;p<=n;p++){
        x=(p+a-1)/a,y=(p+b-1)/b;
        if(x%2==1||y%2==1) chk[0]++;
        if(x%2==1||y%2==0) chk[1]++;
        if(x%2==0||y%2==1) chk[2]++;
        if(x%2==0||y%2==0) chk[3]++;
    }
    for(p=1;p<=n;p++){
        x=(p+a-1)/a,y=(p+b-1)/b;
        if(x%2==1&&y%2==1) sum+=chk[0];
        if(x%2==1&&y%2==0) sum+=chk[1];
        if(x%2==0&&y%2==1) sum+=chk[2];
        if(x%2==0&&y%2==0) sum+=chk[3];
    }
    cout<<sum<<"\n";
}
