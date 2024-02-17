#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
#define MAXN 1005
#define inf 1e9 + 7
    using namespace std;
    int n,m,dp[MAXN];
    typedef struct seg{
        int a,b;
        int c;
    }seg;
    seg X[MAXN];
    void inp(){
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        X[i].a = u;
        X[i].b = v;
        X[i].c = w;
    }
}

        
    
    bool cmp( seg x, seg y ){
        if (x.b == y.b) return x.a < y.a;
        return x.b < y.b;
    }
    void solve(){
        std::sort(X+1,X+m+1,cmp);
        memset(dp,inf,sizeof(dp));
        dp[0] = 0;
        int res = inf;
        X[0].a = 0; X[0].b = 0; X[0].c = 0;
            for ( int i = 1 ; i <= m ; i++ ){
            for ( int j = 0 ; j < i ; j++ ){
                if (X[i].a <= X[j].b)
                dp[i] = std::min(dp[i],dp[j] + X[i].c);
            }
            if (X[i].b >= n) res = std::min(res,dp[i]);
        }
        std::cout<<res;
    }
    int main(int argc, const char** argv){
        inp();
        solve();
        return 0;
    }



/* 9 7
1 3 18
4 7 21
0 5 30
5 8 22
4 8 38
6 9 20
8 9 29 */
