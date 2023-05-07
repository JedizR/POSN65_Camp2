#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,ans;
    int q,i,j,len;
    cin>>q;
    while(q--){
        ans="";
        cin>>s;
        if(s[0]=='0'){
            cout<<"0\n";
            continue;
        }
        len=s.length();
        for(i=s.length()-1;i>=0;i--){
            if(s[i]=='0') ans=ans+"1";
            else break;
        }
        if(ans==""){
            cout<<"0\n";
        }
    else cout<<ans<<"\n";
    }
}
