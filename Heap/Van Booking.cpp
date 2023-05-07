#include <bits/stdc++.h>

using namespace std;

struct van{
    int id,value;
    bool operator < (const van &o) const{
        if(value!=o.value)
            return value>o.value;
        return id>o.id;
    }
};

priority_queue <van> heap;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,i,a;
    cin>>n>>k;
    for(i=1;i<=k;i++){
        heap.push({i,0});
    }
    for(i=0;i<n;i++){
        cin>>a;
        int b=heap.top().value+a;
        int id=heap.top().id;
        heap.pop();
        heap.push({id,b});
        cout<<id<<"\n";
    }
}
