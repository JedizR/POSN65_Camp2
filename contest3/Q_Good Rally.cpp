#include <bits/stdc++.h>

using namespace std;

int cnt[100100];



stack <pair<int,int>> st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,i,j,a,b,cnt=0,temp;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b;
        if(a==b){
            continue;
        }
        if(!st.empty()&&st.top().second==a){
            temp=st.top().first;
            st.pop();
            if(temp!=b){
                st.push({temp,b});
            }
        }
        else{
            st.push({a,b});
        }
    }
    while(!st.empty()){
        cnt++;
        st.pop();
    }
    cout<<cnt;
}
