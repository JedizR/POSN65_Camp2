#include <bits/stdc++.h>

using namespace std;

vector <long long> v,u,ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long n,i,j,anss=0,a,b;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(i=0;i<n;i++){
        cin>>b;
        u.push_back(b);
    }
    sort(u.begin(),u.end());
    for(i=0;i<n;i++){
        ans.push_back(u[i]+v[i]);
    }
    sort(ans.begin(),ans.end());
    for(i=1;i<n;i++){
        anss+=ans[i]-ans[i-1];
    }
    cout<<anss;

}
