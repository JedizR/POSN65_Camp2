#include <bits/stdc++.h>

using namespace std;

priority_queue <int> h;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int i,n,num;
    char a;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        if(a=='B'){
            if(!h.empty()){
                cout<<h.top()*-1<<"\n";
                h.pop();
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(a=='A'){
            cin>>num;
            h.push(num*-1);
        }
    }
}
