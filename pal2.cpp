#include<bits/stdc++.h>
#define ll long long
#define MAXN 1e5 + 5
    long long dp[205][205],n;
    void solve(){
        std::string s;
        std::cin>>s;
        n = s.length();
        s = " " + s;
        long long cnt = 0;
        memset(dp,0,sizeof(dp));
        for ( int i = 1 ; i <= n ; i++ ) {
            dp[i][i] = 1;
            cnt++;
        }
        for ( int i = 2 ; i <= n ; i++ ) dp[i][i-1] = 0;
        for ( int len = 1; len <= n-1 ; len++ ){
            for ( int i = 1 ; i <= n - len ; i++ ){
                int j = i + len;
                if (len == 1){
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                        cnt++;
                }
            }
                else{
                    if (s[i] == s[j] && dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        cnt++;
                    }
                }
        }
    }
        std::cout<<cnt;
    }
    int main(){
        solve();
        return 0;
    }
