#include<bits/stdc++.h>
#include<algorithm>
#define MAXN 101
	using namespace std;
	typedef pair<int,int> pii;
	typedef bool visited[MAXN];
	typedef bool GRAPH[MAXN][MAXN];
	void nhap(int n, int m, GRAPH G){
		std::cin>>n>>m;
		int u,v;
		for ( int i = 0 ; i < n ; i++ ){
			for ( int j = 0; j < n ; j++ ){
				G[i][j] = false;
			}
		}
		for ( int i = 0 ; i < m ; i++ ){
			std::cin>>u>>v;
			G[u][v] = G[v][u] = true;
		}
	}
	bool KiemTra( int n, int p[MAXN], GRAPH G, GRAPH H ){
		for ( int i = 0 ; i < n - 1 ; i++ ){
			for ( int j = i + 1 ; j < n ; j++ ){
				if (G[i][j] != H[p[i]][p[j]])
				return false;
			}
		}
		return true;
	}
	bool KiemTraDangCau( int n, GRAPH G, GRAPH H ){
		int p[MAXN];
		for ( int i = 0 ; i < n ; i++ ){
			p[i] = i;
		}
		do {
			if (KiemTra(n,p,G,H)) return true;
		} while(std::next_permutation(p,p+n));
		return false;
	}
	int main(){
		int n,m;
		GRAPH G,H;
		nhap(n,m,G);
		nhap(n,m,H);
		if (KiemTraDangCau(n,G,H)) std::cout<<"YES";
		else std::cout<<"NO";
		return 0;
	}
	
