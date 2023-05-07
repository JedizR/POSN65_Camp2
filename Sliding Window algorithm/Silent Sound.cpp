#include <bits/stdc++.h>

using namespace std;

int a[1001000];
deque <int> mx,mn;
queue <int> ans;

int main(){
    int n,m,c,i;
    cin>>n>>m>>c;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        while(!mx.empty()&&mx.front()<i-m+1) mx.pop_front();
        while(!mn.empty()&&mn.front()<i-m+1) mn.pop_front();
        while(!mx.empty()&&a[mx.back()]<=a[i]) mx.pop_back();
        while(!mn.empty()&&a[mn.back()]>=a[i]) mn.pop_back();
        mx.push_back(i);
        mn.push_back(i);
        if(i>=m){
            if(a[mx.front()]-a[mn.front()]<=c){
                ans.push(i-m+1);
            }
        }
    }
    if(ans.size()==0) cout<<"NONE\n";
    else{
        while(!ans.empty()){
            cout<<ans.front()<<"\n";
            ans.pop();
        }
    }
}
