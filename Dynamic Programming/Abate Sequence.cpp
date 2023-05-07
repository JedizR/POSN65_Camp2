#include <bits/stdc++.h>

using namespace std;

int a[100100],lis[100100];
vector <int> v[100100],ans;

int main(){
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        a[i]*=-1;
    }
    int maxx=0,ind;
    for(i=1;i<=n;i++){
        ind=lower_bound(lis,lis+maxx,a[i])-lis;
        if(ind==maxx) maxx++;
        lis[ind]=a[i];
        v[ind].push_back(a[i]);
    }
    int last=v[maxx-1][0];
    ans.push_back(last);
    for(i=maxx-2;i>=0;i--){
        for(j=0;j<v[i].size();j++){
            if(v[i][j]<last){
                ans.push_back(v[i][j]);
                last=v[i][j];
                break;
            }
        }
    }
    cout<<maxx<<"\n";
    for(i=ans.size()-1;i>=0;i--){
        cout<<ans[i]*-1<<" ";
    }
}
