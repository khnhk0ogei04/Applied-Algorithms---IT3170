#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int n,m,u,v,s,t;
std::queue<std::pair<int,int>>q;
bool visited[MAXN][MAXN];
std::pair<int,int> parent[MAXN][MAXN];
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
bool insize(int x, int y){
	return (1 <= x && x <= n) && (1 <= y && y <= m);
}
std::vector<std::pair<int,int>>path;
int ans;
void solve(){
	std::cin>>n>>m>>u>>v>>s>>t;
	q.push({u,v});
	visited[u][v] = true;
	parent[u][v] = {0,0};
		while (!q.empty()){
			std::pair<int,int> p = q.front();
			int x = p.first;
			int y = p.second;
			q.pop();
			if (x == s && y == t) {
    			while (x != 0 || y != 0) { 
        			path.push_back({x, y});
        			int u = parent[x][y].first;
        			int v = parent[x][y].second;
        			x = u;
        			y = v;
    			}
    			break;
			}
			for (int i = 0 ; i < 8 ; i++){
				int x1 = x + dx[i];
				int y1 = y + dy[i];
				if (!visited[x1][y1] && insize(x1,y1)){
					visited[x1][y1] = true;
					parent[x1][y1] = {x,y};
					q.push({x1,y1});
				}
			}
		}
		reverse(path.begin(),path.end());
		ans = path.size() - 1;
		std::cout<<ans<<std::endl;
		for (auto x: path){
			std::cout<<x.first<<" "<<x.second<<std::endl;
		}
	}
int main(int argc, const char** argv){
	solve();
	return 0;
}