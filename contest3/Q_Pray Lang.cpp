
#include <bits/stdc++.h>

using namespace std;

//vector <pair<string,string>> dic;
map <string,string> mp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a;
    string b,c;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mp[a]=b;
    }
    for(int i=0;i<m;i++){
        cin>>c;
        cout<<mp[c] <<" ";
        //string d=dic.at(c);
        //cout<<d<<" ";
    }
}
/*
5 6
tan is
yatch not
icy gay
kim Pray
wachi or
kim tan icy wachi yatch icy
*/
