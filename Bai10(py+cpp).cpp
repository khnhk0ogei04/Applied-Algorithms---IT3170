#include<bits/stdc++.h>
#define ll long long
typedef std::pair<int,int> pii;
#define MAXN 1005
    using namespace std;
    int n;
    string s;
    ll f[MAXN][MAXN], g[MAXN][MAXN];
    // f[i][j]: do dai xau con dai nhat co ki tu dau va ki tu cuoi la nguyen am khi xet xau bat dau tu i, ket thuc o j
    // g[i][j]: do dai xau con dai nhat co ki tu dau va ki tu cuoi la phu am khi xet xau bat dau tu i, ket thuc o j
    // dap an la n - std::max(f[1][n],g[1][n])
    bool check ( char s ){
        if ( s == 'a' || s == 'e' || s == 'u' || s == 'o' || s == 'i' )
        return true;
        return false;
    }
    void solve(){
        std::cin>>s;
        n = s.length();
        s = " " + s;
        for ( int i = 1 ; i <= n - 1 ; i++ ){
            if (check(s[i]) == true && check(s[i+1]) == true) f[i][i+1] = 2;
            else
            if (check(s[i]) == false && check(s[i+1]) == false) g[i][i+1] = 2;
        }
        for ( int len = 2 ; len <= n - 1 ; len++ ){
            for ( int i = 1 ; i <= n - len ; i++ ){
                int j = i + len;
                f[i][j] = std::max(f[i+1][j],f[i][j-1]);
                g[i][j] = std::max(g[i+1][j],g[i][j-1]);
                if (check(s[i]) == true && check(s[j]) == true)
                    f[i][j] = std::max(f[i][j], g[i+1][j-1] + 2);
                else if (check(s[i]) == false && check(s[j]) == false)
                    g[i][j] = std::max(g[i][j], f[i+1][j-1] + 2);
            } 
        }
        std::cout<<f[1][n]<<" "<<g[1][n]<<" ";
        std::cout<<n - std::max(f[1][n],g[1][n]);
        
    }
        int main(){
            solve();
            return 0;
        }
