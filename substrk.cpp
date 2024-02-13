#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
    using namespace std;
    ll n,k,dp[MAXN];
    std::string s;
    void solve(){
        std::cin>>k;
        std::cin>>s;
        n = s.length();
        s = " " + s;
        dp[0] = 0;
        ll res = 0;
        for ( int i = 1 ; i <= n ; i++ ){
            if (s[i] == '1')
            dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i-1];
        }
        for ( int i = 0; i < n ; i++  ){
            int tmp = dp[i] + k;
            int left = std::lower_bound(dp+i+1,dp+n+1,tmp)-dp;
            if (left == n+1) continue;
            int right = std::upper_bound(dp+i+1,dp+n+1,tmp)-dp;
            res += right - left;
        }
        std::cout<<res;
    }
    int main(){
        solve();
        return 0;
    }
