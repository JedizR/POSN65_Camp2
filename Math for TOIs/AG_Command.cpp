#include <bits/stdc++.h>

using namespace std;

vector <int> a;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int i,j,n,t;
    cin>>t>>n;
    a.clear();
    while(n%4==0){
        n/=4;
        a.push_back(4);
    }
    while(n%6==0){
        n/=6;
        a.push_back(6);
    }
    for(i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            a.push_back(i);
        }
    }
    if(n!=1) a.push_back(n);
    sort(a.begin(),a.end());
    for(auto x:a){
        cout<<"AC";
        for(i=0;i<x;i++) cout<<"V";
    }
    cout<<"\n";
}
