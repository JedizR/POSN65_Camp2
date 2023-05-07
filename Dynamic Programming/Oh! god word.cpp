#include <bits/stdc++.h>

using namespace std;

char str[1010];
int dp[1010][1010];

int main(){
    int len,maxlen=1,i,start=0,k,j;
    cin>>str;
    len=strlen(str);
    for(i=0;i<len;i++){
        dp[i][i]=1;
    }
    for(i=len-1;i>0;i--){
        if(str[i]==str[i-1]){
            dp[i-1][i]=1;
            start=i-1;
            maxlen=2;
        }
    }
    for(k=3;k<=len;++k){
        for(i=0;i<len-k+1;++i){
            j=i+k-1;
            if(dp[i+1][j-1]&&str[i]==str[j]){
                dp[i][j]=1;
                if(k>maxlen){
                    start=i;
                    maxlen=k;
                }
            }
        }
    }
    for(i=start;i<=start+maxlen-1;++i){
        cout<<str[i];
    }
}
