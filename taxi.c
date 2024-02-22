#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXN 31
#define ll long long
#define inf 1e9 + 7
int A[MAXN][MAXN],n;
int X[MAXN],smin;
int sum[MAXN],res;
bool visited[MAXN];
	void init(){
		scanf("%d", &n);
		smin = inf;
		for ( int i = 0 ; i <= 2*n ; i++ )
			for ( int j = 0 ; j <= 2*n ; j++ )
				A[i][j] = inf;
		
		for ( int i = 0 ; i <= 2*n ; i++ ){
			for ( int j = 0 ; j <= 2*n ; j++ ){
				scanf("%d",&A[i][j]);			
				if (A[i][j] < smin) smin = A[i][j];
			}
		}
		res = inf;
	}
	void Try(int i, int tt){
		for ( int v = 1 ; v <= 2*n ; v++ ){
			if (!A[X[i-1]][v]) continue;
			if (!visited[v]){
				if (v <= n){
					if (!tt){
						tt++;
						visited[v] = true;
						X[i] = v;
						sum[i] = sum[i-1] + A[X[i-1]][v];
						if (sum[i] + smin*(2*n+1-i) < res)
						Try(i+1,tt);
						tt--;
						visited[v] = false;
					}
					
				}
				else{
					if (tt && visited[v-n]){
						tt--;
						visited[v] = true;
						X[i] = v;
						sum[i] = sum[i-1] + A[X[i-1]][v];
						if ( i == 2*n ){
							if (sum[i] + A[X[i]][0] < res)
							res = sum[i] + A[X[i]][0];
						}
						else if (sum[i] + smin*(2*n+1-i) < res)
						Try(i+1,tt);
						tt++;
						visited[v] = false;
					}
				}
			}
	}
}
int main(int argc, const char**argv){
	init();
	memset(visited,false,sizeof(visited));
	Try(1,0);
	printf("%d",res);
	return 0;
}
