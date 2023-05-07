#include <bits/stdc++.h>

using namespace std;

int x[1001000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int i,n,m,k,l,num,cnt,ii,jj,loop;
    cin>>n>>m>>k>>l;
    for(i=0;i<n;i++){
        cin>>x[i];
    }
    i=0;
    sort(x,x+n);
    while(k--){
        i=0;
        cnt=0;
        for(loop=0;loop<m;loop++){
            cin>>num;
            ii=lower_bound(&x[i],&x[i]+n-i,num-l)-x;
            if(x[ii]<num-l) ii++;
            jj=lower_bound(&x[i],&x[i]+n-i,num+l)-x;
            if(x[jj]>num+l||jj>=n) jj--;
            if(ii<=jj) cnt+=jj-ii+1;
            i=jj+1;
        }
        cout<<cnt<<"\n";
    }
}
