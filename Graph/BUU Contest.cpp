#include <bits/stdc++.h>

using namespace std;

struct a{
    int power;
    bool operator < (const a &o) const{
        if(power!=o.power)
            return power<o.power;
    }
};

priority_queue <a> pq;

int main(){
    int n,b,a,i,j,ans=0,k,day;
    cin>>day>>k;
    for(i=0;i<day;i++){
        cin>>n>>b;
        for(j=0;j<n;j++){
            cin>>a;
            pq.push({a-k*i});
        }
        for(j=0;j<b;j++){
            ans+=pq.top().power+k*i;
            pq.pop();
        }
    }
    cout<<ans;
}
/*
3 10
5 2
8 4 5 1 10
4 3
14 4 9 14
2 1
20 7
*/
