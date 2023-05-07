#include <bits/stdc++.h>

using namespace std;

map<int,int> m;
long long w[100100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    for(int c=1;c<=n;c++){
        cin>>a>>b;
        m[a]++,m[b+1]--;
    }
    long long ans=0,work=0,last=0;
    for(auto p : m){
        if(work>1){
            ans+=(long long)(p.first-last)*(work-1);
        }
        work+=p.second;
        last=p.first;
    }
    cout<<ans<<"\n";
}
