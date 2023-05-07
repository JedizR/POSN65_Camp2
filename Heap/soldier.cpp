#include <bits/stdc++.h>

using namespace std;

struct a{
    int id,rk,day;
    bool operator < (const a &o) const{
        if(rk!=o.rk)
            return rk<o.rk;
        return day>o.day;
    }
};

priority_queue <a> pq;

int main(){
    long long n,r,a,id,rk,day=0;
    cin>>n>>r;
    while(n--){
        cin>>a;
        if(a==1){
            cin>>id>>rk;
            pq.push({id,rk,day});
            day++;
        }
        if(a==2){
            if(!pq.empty()){
                cout<<pq.top().id<<"\n";
                pq.pop();
            }
            else{
                cout<<"-1\n";
            }
        }
    }
}
