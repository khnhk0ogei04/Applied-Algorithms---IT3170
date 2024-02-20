#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define MAXN 31
int t,n,result[MAXN],k = 0;
void solve(int N,int i){
	N = 1000 - N;
	result[++i] = 0;
	while(N){
		if (N >= 500){
			N -= 500;
			result[i]++;
		}
		else if (N >= 100){
			N -= 100;
			result[i]++;
		}
		else if (N >= 50){
			N -= 50;
			result[i]++;
		}
		else if (N >= 10){
			N -= 10;
			result[i]++;
		}
		else if (N >= 5){
			N -= 5;
			result[i]++;
		}
		else if (N >= 1){
			N -= 1;
			result[i]++;
		}
	}
}
	int main(int argc, const char**argv){
		scanf("%d", &t);
		int s = t;
		while(t--){
			scanf("%d",&n);
			solve(n,k);
			k++;
		}
		for ( int i = 1 ; i <= s ; i++ ){
			printf("%d\n",result[i]);
		}
		return 0;
	}
