#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
typedef std::vector<int> vi;
    using namespace std;
    int parent[MAXN],n,m,k,sz[MAXN];
    typedef struct edge{
        int u,v;
        int w;
    }edge;
    std::vector<edge> canh;
    void init(){
        for ( int i = 1; i <= n ; i++ ){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int Find( int u ){
        if ( u == parent[u] ) return u;
        return parent[u] = Find(parent[u]);
    }
    bool Union( int u, int v ){
        u = Find(u);
        v = Find(v);
        if ( u == v ) return false;
        if (sz[u] > sz[v]) parent[v] = u;
        else{
            parent[u] = v;
            if (sz[u] == sz[v]) sz[v] += 1;
        }
        return true;
    }
    bool cmp( edge a, edge b ){
        return a.w < b.w;
    }
    void inp(){
        std::cin>>n>>m>>k;
        for ( int i = 1 ; i <= m ; i++ ){
            int x,y,z;
            std::cin>>x>>y>>z;
            edge e;
            e.u = x; e.v = y; e.w = z;
            canh.push_back(e);
        }
    }
    void solve(){
        inp();
        init();
        int ans = 0;
        std::vector<std::pair<int,int>>v;
        std::sort(canh.begin(),canh.end(),cmp);
        for ( int i = 0 ; i < m ; i++ ){
            int x = canh[i].u;
            int y = canh[i].v;
            int z = canh[i].w;
            if (v.size() == k){
                std::cout<<ans<<std::endl;
                break;
            }
            if (Union(x,y)){
                ans += z;
                v.push_back({x,y});
            }
        }
        for ( auto x: v ){
            std::cout<<x.first<<" "<<x.second;
            std::cout<<std::endl;
        }
    }
    int main(){
        solve();
        return 0;
    }
