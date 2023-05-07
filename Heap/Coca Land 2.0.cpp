#include <bits/stdc++.h>

using namespace std;

struct a{
    int id,bu,rip,mu;
    bool operator < (const a &o) const{
        if(bu!=o.bu)
            return bu>o.bu;
        return id>o.id;
    }
};

priority_queue <a> pq;

int main(){
    int p,opr,i,b,a,c;
    cin>>p;
    for(i=0;i<p;i++){
        cin>>opr;
        if(opr==1){
            cin>>a>>b;
            pq.push({2,a,b,0});
        }
        if(opr==2){
            cin>>a;
            pq.push({3,a,p+1,0});
        }
        if(opr==3){
            cin>>a>>b>>c;
            pq.push({1,a,b,c});
        }
        if(opr==4){
            if(pq.empty()){
                cout<<"GREAN\n";
                continue;
            }
            while(i>=pq.top().rip){
                if(pq.top().id==1){
                    a=pq.top().mu;
                    pq.pop();
                    pq.push({1,a,p+1,0});
                }
                else{
                    pq.pop();
                }
            }
            cout<<pq.top().bu<<"\n";
            pq.pop();
        }
    }
}
