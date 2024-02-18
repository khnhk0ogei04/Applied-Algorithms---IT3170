#include<bits/stdc++.h>
#define MAXN 200001
#define ll long long
	using namespace std;
	std::vector<int>adj[MAXN];
	int n,root,A[MAXN],dp1[MAXN],dp0[MAXN];
	void dfs(int u, int parent){
		dp0[u] = 0; // deo chon u
		dp1[u] = A[u]; // chon u
		for ( int v: adj[u] ){
			if ( v != parent ){
				dfs(v,u);
				dp0[u] += std::max(dp0[v],dp1[v]);
				dp1[u] += dp0[v];
			}
		}
	}
	int main( int argc, const char** argv ){
		ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);
		std::cin>>n;
		for ( int i = 1 ; i<= n ; i++ ){
			std::cin>>A[i];
		}
		for ( int i = 1 ; i <= n ; i++ ){
			int u;
			std::cin>>u;
			adj[u].push_back(i);
			adj[i].push_back(u);
		}
		dfs(1,0);
		std::cout<<std::max(dp0[1],dp1[1]);
		return 0;
	}