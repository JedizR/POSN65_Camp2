#include <bits/stdc++.h>

using namespace std;

queue <int> q;
queue <int> q2;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,i,j,cnt=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        q.push(i);
    }
    while(!(q.empty()&&q2.empty())){
        while(!q.empty()){
            cnt++;
            if(cnt%m!=0) q2.push(q.front());
            else cout<<q.front()<<" ";
            q.pop();
        }
        while(!q2.empty()){
            cnt++;
            if(cnt%m!=0) q.push(q2.front());
            else cout<<q2.front()<<" ";
            q2.pop();
        }
    }
}
