#include<bits/stdc++.h>
const int MAXN = 100005;
using namespace std;
	int n,m,bk,res = 0,key = 0;
	int X[MAXN],Y[MAXN];
	int C[MAXN],P[MAXN];
	void inp(){
		std::cin>>n>>m;
		for ( int i = 1; i <= n ; i++ ){
			std::cin>>X[i]>>Y[i];
		}
		bk = m;
	}
	void Try( int i ){
		int j = 1;
		if ( i == n + 1 ){
			if ( res > key ){
				key = res;
				for ( int j = 1; j <= n ; j++ ){
					P[j] = C[j];
				}
			}
			return;
		}

		for ( int t = 0 ; t <= j ; t++ ){
			C[i] = t;
			int tmp1 = bk, tmp2 = res;
			if ( t == 1 ){
				if (bk - t*X[i] >= 0){
				bk = tmp1 - t*X[i];
				res = tmp2 + t*Y[i];
				}
			}
			Try(i+1);
			bk = tmp1 + t*X[i];
			res = tmp2 - t*Y[i];
		}
	
	}
		int main(){
			inp();
			Try(1);
			std::cout<<key<<std::endl;
			for ( int i = 1 ; i <= n ; i++ ){
				if (P[i]) std::cout<<i<<" ";
			} 
			return 0;
		}
