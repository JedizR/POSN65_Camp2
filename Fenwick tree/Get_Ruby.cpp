#include <bits/stdc++.h>

using namespace std;

char opr[5];
int tree[750100];

void update(int idx,int v){
    while(idx<=750003){
        tree[idx]+=v;
        idx+=idx&-idx;
    }
}

int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx&-idx;
    }
    return sum;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>opr>>a>>b;
        if(opr[0]=='B'){
            update(b,a);
        }
        else{
            cout<<query(b)-query(a-1)<<"\n";
        }
    }
}
