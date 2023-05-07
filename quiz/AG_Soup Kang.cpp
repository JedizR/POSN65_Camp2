#include <bits/stdc++.h>

using namespace std;

string t[100100];
int a[100100][100100],tr[100100][100100];
vector <pair<int,int>> adj[100100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c;
    char cc;
    cin>>r>>c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>cc;
            if(cc=='x'){
                tr[i][j]==1;
            }
        }
    }
}
