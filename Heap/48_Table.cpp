#include <bits/stdc++.h>

using namespace std;

struct heap{
    int x,y,cnt,v;
    bool operator < (const heap &o) const{
        if(cnt!=o.cnt) return cnt>o.cnt;
        else if(x!=o.x) return x>o.x;
        return y>o.y;
    }
};

priority_queue <heap> pq;
priority_queue <heap> pq2;

int main(){
    int r,c,m,k,x,y,rr,cc,cnt;
    cin>>r>>c>>m;
    while(m--){
        cin>>k;
        if(k==1){ //setvalue
            cin>>rr>>cc>>x;
            pq.push({rr,cc,})
        }
        if(k==2){ //setrowvalue
            cin>>rr>>x;
        }
        if(k==3){ //getvalue
            cin>>rr>>cc;
        }
        if(k==4){ //getmin

        }
        cnt++;
    }
}
