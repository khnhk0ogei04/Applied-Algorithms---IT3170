#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
typedef std::vector<int> vi;
    using namespace std;
    int n,k,s,ans;
    int A[MAXN],X[MAXN];
    void init(){
        for ( int i = 1 ; i <= n ; i++ ){
            A[i] = i;
        }
    }
    vector<vector<int>>v;
    void backtrack( int cnt, int last, int temp ){
    //    std::cout<<cnt<<" "<<last<<" "<<temp<<" "<<std::endl;
        if ( cnt == k + 1){
            if ( temp == s ){
                ans++;
                vi q;
                for ( int i = 1; i <= k ; i++ ){
                    q.push_back(X[i]);
                }
                v.push_back(q);
            }
        }
            else {
                for ( int j = last + 1 ; j <= n ; j++ ){
                    if (temp + A[j] <= s){
                        X[cnt] = A[j];
                        backtrack(cnt + 1,j,temp + A[j]);
                    }
                }
                
            }
        }
    
    void solve(){
        std::cin>>n>>k>>s;
        init();
        ans = 0;
        backtrack(1,0,0);
        std::cout<<ans<<std::endl;
        for ( auto x: v ){
            for ( int i = 0 ; i < x.size() ; i++ ){
                std::cout<<x[i]<<" ";
        }
        std::cout<<std::endl;
    }
    }
    int main(){
        solve();
        return 0;
    }
