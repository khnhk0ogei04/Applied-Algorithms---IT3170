#include<bits/stdc++.h>
#define MAXN 200001
#define ll long long
int n,dp[MAXN],A[MAXN];
	using namespace std;
	vector<int>adj[MAXN];
	void dfs(int u, int parent){
		dp[u] = A[u];
		for ( int v: adj[u] ){
			if ( v != parent ){
				dfs(v,u);
				dp[u] = std::max(dp[u],dp[v]+A[u]);
			}
		}
	}
	int main( int argc, const char** argv ){
		ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);
		std::cin>>n;
		for ( int i = 1 ; i <= n ; i++ ){
			std::cin>>A[i];
		}
		for ( int i = 1 ; i <= n ; i++ ){
			int u;
			std::cin>>u;
			if ( u == 0 ) continue;
			adj[u].push_back(i);
			adj[i].push_back(u);
		}
		dfs(1,0);
		std::cout<<dp[1];
		return 0;
	}
/* 14
3 2 1 10 1 3 9 1 5 3 4 5 9 8
0 1 1 1 2 2 3 4 4 4 5 5 7 7 
*/
