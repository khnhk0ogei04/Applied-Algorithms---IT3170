#include<stdio.h>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#define ll long long
#define MAXN 101
#define inf 1e9 + 7
int n,m,numpas = 0,A[MAXN][MAXN],min1 = 1e9 + 7;
int X[MAXN],sum[MAXN],res = inf,Xopt[MAXN];
bool visited[MAXN];

void Try( int k ){
	for ( int v = 1 ; v <= 2*n; v++ ){
		if (!A[X[k-1]][v]) continue;
		if (!visited[v]){
			if ( v <= n ){
				if (numpas < m) {
					numpas++;
					visited[v] = true;
					X[k] = v;
					sum[k] = sum[k-1] + A[X[k-1]][v];
					if (sum[k] + min1*(2*n+1-k) < res)
					Try(k+1);
					numpas--;
					visited[v] = false;
				}
			}
			else{
				if (visited[v-n]){
					X[k] = v;
					visited[v] = true;
					numpas--;
					sum[k] = sum[k-1] + A[X[k-1]][v];
					if (k == 2*n){
						if (sum[k] + A[X[k]][0] < res){
						for ( int i = 0; i <= k ; i++ ){
							Xopt[i] = X[i];
						}
						Xopt[k+1] = 0;
						res = sum[k] + A[X[k]][0];
					}
				}
					else if (sum[k] + min1*(2*n+1-k) < res){
						Try(k+1);
					}
					visited[v] = false;
					numpas++;
				}
			}
		}
		
	}
}
int main(int argc, const char**argv){
	scanf("%d %d",&n,&m);
	memset(visited,false,sizeof(visited));
	for ( int i = 0 ; i <= 2*n ; i++ ){
		for ( int j = 0 ; j <= 2*n ; j++ ){
			scanf("%d",&A[i][j]);
			if (A[i][j] < min1) min1 = A[i][j];
		}
	}
	X[0] = 0;
	sum[0] = 0;
	Try(1);
	printf("%d\n",res);
	for (int i = 0; i <= 2*n + 1; i++){
		printf("%d ",Xopt[i]);
	}
	return 0;
}
/* 10 4
0 8 5 1 10 5 9 9 3 5 6 6 2 8 2 2 6 3 8 7 2
5 0 4 3 3 2 7 9 6 8 7 2 9 10 3 8 10 6 5 4 2
3 4 0 5 2 2 4 9 8 5 3 8 8 10 4 2 10 9 7 6 1
3 9 7 0 3 5 9 7 6 1 10 1 1 7 2 4 9 10 4 5 5
7 1 7 7 0 9 5 10 7 4 8 9 9 3 10 2 4 6 10 9 5
1 8 7 4 7 0 6 5 3 1 10 8 4 8 3 7 1 2 7 6 8
6 5 2 3 1 1 0 5 7 1 8 2 8 8 8 8 4 4 6 10 10
9 2 9 3 7 7 1 0 9 1 2 3 6 1 10 5 8 9 4 6 2
3 1 2 7 5 1 7 2 0 10 9 5 2 5 4 10 9 9 1 9 8
8 9 4 9 4 8 2 1 8 0 5 10 7 6 2 1 10 10 7 9 4
5 9 5 10 10 3 6 6 4 4 0 8 5 4 9 1 9 9 1 7 9
2 10 9 10 8 3 3 9 3 9 10 0 8 9 2 6 9 7 2 3 5
3 6 9 7 3 7 6 4 10 3 5 7 0 9 3 2 2 10 8 7 3
10 6 3 1 1 4 10 2 9 2 10 6 4 0 6 3 6 9 7 8 8
3 3 10 5 2 10 7 10 9 3 6 6 5 10 0 3 6 1 9 4 10
4 10 7 8 10 10 8 7 10 4 6 8 7 7 6 0 3 6 5 5 2
7 2 7 4 4 6 6 4 3 9 3 6 4 7 2 9 0 3 2 5 7
3 10 2 6 1 4 7 5 10 3 10 4 5 5 1 6 10 0 4 5 3
9 9 8 6 9 2 3 6 8 5 5 5 5 5 3 10 4 1 0 8 9
8 4 1 4 9 3 6 3 1 4 8 3 10 8 6 4 5 4 3 0 2
4 3 6 4 6 2 3 3 3 7 5 1 8 1 4 5 1 1 6 4 0
37
0 3 9 7 13 4 1 11 19 8 18 6 5 14 17 2 10 15 20 16 12 0 */
