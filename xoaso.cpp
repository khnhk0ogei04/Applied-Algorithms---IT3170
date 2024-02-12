#include<bits/stdc++.h>
const int MAXN = 100005;
#define ll long long
    using namespace std;
    int n,dp[3][MAXN],A[MAXN];
    std::string s;
    void solve(){
        std::cin>>s;
        n = s.length();
        s = " " + s;
        for ( int i = 1 ; i <= s.length(); i++ ){
            A[i] = s[i] - '0';
        }
        int sum = 0;
        for ( int i = n ; i > 0 ; i-- ){
            sum += A[i];
            int k = sum % 3;
            dp[k][i] = dp[k][i+1] + 1;
            dp[(k+1) % 3][i] = dp[(k+1) % 3][i+1];
            dp[(k+2) % 3][i] = dp[(k+2) % 3][i+1];
        }
        int res = dp[0][1];
        sum = 0;
        for ( int i = 1 ; i < n ; i++ ){
            sum += A[i];
            int k = sum % 3;
            if ( k == 0 ) res++;
            res += dp[(3-k) % 3][i+2];
        }
        std::cout<<res;
    }
    int main(){
        freopen("CAU3.INP","r",stdin);
        freopen("CAU3.OUT","w",stdout);
        solve();
        return 0;
    }
