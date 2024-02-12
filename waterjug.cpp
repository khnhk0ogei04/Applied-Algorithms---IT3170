#include<bits/stdc++.h>
#define ll long long
const int MAXN = 1005;
	using namespace std;
	int a,b,c,ok = 0;
	int level[MAXN][MAXN];
	std::queue<std::pair<int,int>>q;
	void solve(){
		std::cin>>a>>b>>c;
		memset(level,0,sizeof(level));
		q.push({0,0});
		level[0][0] = 0;
		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			std::cout<<x<<" "<<y<<" "<<level[x][y]<<std::endl;
			q.pop();
			if ( x == c || y == c ){
				std::cout<<level[x][y];
				ok = 1;
				break;
			}
			if ( level[a][y] == 0 ){
				level[a][y] = level[x][y] + 1;
				q.push({a,y});
			}
			if ( level[x][b] == 0 ){
				level[x][b] = level[x][y] + 1;
				q.push({x,b});
			}
			if ( level[0][y] == 0 ){
				level[0][y] = level[x][y] + 1;
				q.push({0,y});
			}
			if ( level[x][0] == 0 ){
				level[x][0] = level[x][y] + 1;
				q.push({x,0});
			}
			if ( x + y >= a ){
				if (level[a][x+y-a] == 0){
					level[a][x+y-a] = level[x][y] + 1;
					q.push({a,x+y-a});
				}
			}	else 
				if (level[x+y][0] == 0){
				level[x+y][0] = level[x][y] + 1;
				q.push({x+y,0});
			
		}
			if (x + y >= b ){
				if ( level[x+y-b][b] == 0 ){
					level[x+y-b][b] = level[x][y] + 1;
					q.push({x+y-b,b});
				}
			}   else 
				if (  level[0][x+y] == 0 ){
				level[0][x+y] = level[x][y] + 1;
				q.push({0,x+y});
			}
			
		}
			if (!ok) std::cout<<"-1";
		}
		int main(){
			solve();
			return 0;
		}
	
