#include<stdio.h>
#include<math.h>
#include<stdlib.h>

	int X[16];
	int n,k,cnt;
	void PrintSolution(){
		cnt++;
		for ( int i = 1 ; i <= k ; i++ ){
			printf("%d ",X[i]);
		}
		printf("\n");
	}
	void Try( int i ){
		for ( int j = X[i-1] + 1 ; j <= n - k + i ; j++ ){
			X[i] = j;
			if ( i == k ){
				PrintSolution();
			}
			else Try(i+1);
		}
	}
	int main(int argc, const char**argv ){
		int t;
		scanf("%d",&t);
		while (t--){
			cnt = 0;
			X[0] = 0;
			scanf("%d %d", &n, &k);
			Try(1);
			printf("%d\n",cnt);
		}
		return 0;
	}
