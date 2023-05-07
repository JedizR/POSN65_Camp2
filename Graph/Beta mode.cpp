#include <bits/stdc++.h>

using namespace std;

int dp[10100][10100];

int main(){
    string s1,s2;
    int i,j,ei,ej,ans,mx=0;
    cin>>s1>>s2;
    int len1=s1.length(),len2=s2.length();
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>mx){
                    mx=max(mx,dp[i][j]);
                    ei=i;
                }
            }
        }
    }
    for(i=ei-mx;i<ei;i++){
        cout<<s1[i];
    }
}
/*
abcdefabc
bacdefabcde
*/
