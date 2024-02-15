#include<bits/stdc++.h>
#define N 11
#define inf 1e9 + 7
using namespace std;
int dp[N][N],n,k;
int res = inf;
std::vector<int>X(N);
std::vector<int>C(N),arr_res(N);
void floyd(){
	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j = 1 ; j <= n ; j++ ) 
//		if ( j != i )
			for ( int k = 1 ; k <= n ; k++ ){
	//			if ( k != i && k != j )
				dp[j][k] = std::min(dp[j][k],dp[j][i] + dp[i][k]);
			}
	}
}
void Process(){
	std::vector<int> dd(n+1);
	fill(dd.begin(),dd.end(),0);
	for ( int i = 1; i <= k ; i++ ){
		dd[X[i]] = 1;
	}
	int tmpmax = 0;
	for ( int j = 1 ; j <= n ; j++ ){
		if (dd[j] == 0){
			int tmp = inf;
			for ( int i = 1 ; i <= k ; i++ ){
				if ( j != X[i] ) 
				tmp = std::min(tmp,dp[X[i]][j]);
			}
			tmpmax = std::max(tmp,tmpmax);
		}
	}
	if( res > tmpmax ){
		res = tmpmax;
		arr_res = X;
	}
}


void Try( int i ){
	for ( int j = X[i-1] + 1 ; j <= n - k + i; j++ ){
		if (C[j] == 0){
			C[j] = 1;
			X[i] = j;
			if ( i == k ) Process();
			else Try(i+1);
			C[j] = 0;
		}
	}
}
int main(){
	std::cin>>n>>k;
	X[0] = 0;
	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j = 1 ; j <= n ; j++ ){
			std::cin>>dp[i][j];
		}
	}
	floyd();
//	std::cout<<dp[2][3];
	Try(1);
	std::cout<<res<<std::endl;
	for ( int i = 1 ; i <= k ; i++ ){
		std::cout<<arr_res[i]<<" ";
	}
	return 0;
}
