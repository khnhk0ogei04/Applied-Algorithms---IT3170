#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define MAXN 31
int H,W,n,h[MAXN],w[MAXN],busy[MAXN][MAXN];
int res = 0;
int check(int i,int j,int k){
	for ( int u = i ; u < i + w[k] ; u++ ){
		for (int v = j; v < j + h[k]; v++){
			if (busy[u][v])
			return 0;
		}
	}
	return 1;
}
void marked(int i,int j,int k,int s){
	for (int u = i; u < i + w[k]; u++ ){
		for (int v = j; v < j + h[k]; v++){
			busy[u][v] = s;
		}
	}
}

void Try(int k){
	if (res){
		return;
	}
	for ( int i = 0 ; i <= W - w[k] ; i++ ){
		for (int j = 0; j <= H - h[k]; j++){
			if (check(i,j,k)){
				marked(i,j,k,1);
				if ( k == n ){
					res = 1;
				}
				else Try(k+1);
				marked(i,j,k,0);
			}
		}
	}
}

int main(int argc,const char**argv){
	scanf("%d %d",&H,&W);
	scanf("%d",&n);
	for ( int i = 1; i <= n ; i++ ){
		scanf("%d %d",&h[i],&w[i]);
	}
	Try(1);
	if (res) printf("1");
	else printf("0");
	return 0;
}