#include <bits/stdc++.h>
using namespace std;

string s;
unordered_map<long long, long long> f;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n,k,cnt=0,ans=0;
    cin>>n>>k>>s;
    s=" "+s;
    for (int i = 1; i <= n; ++i) {
    if (s[i] == 'R')
      cnt -= k;
    else
      ++cnt;
    if (f[cnt] == 0 && cnt != 0)
      f[cnt] = i;
    else
      ans = max(ans, i - f[cnt]);
  }
  cout<<ans;
}


