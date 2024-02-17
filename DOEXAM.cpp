#include<bits/stdc++.h>
using namespace std;
#define MAXN 27
int n,k,A[MAXN],C[MAXN],x,res,X[MAXN];
void inp(){
	std::cin>>n>>k;
	for ( int i = 1 ; i <= n ; i++ ){
		std::cin>>A[i];
	}
    x = std::min(2*k,n);
}
	void Try( int i, int sum, int p ){
		if ( i == x + 1 || p == 0 ){
			if (sum > res){
				res = max(res,sum);
				for ( int i = 1 ; i <= n ; i++ ){
					X[i] = C[i];
				}
			}
			return;
		}
		
		for ( int j = 1; j >= 0 ; j-- ){
			C[i] = j;
			if (C[i-1] == 1) {
				if (C[i] == 0) Try(i+1,sum,p);
				else Try(i+1,sum + A[i], p - 1);
			}
			else {
				Try(i + 1,sum + A[i],p - 1);	
			}
		}
	}
	int main( int argc, const char** argv ){
		inp();
		res = 0;
		C[1] = 1;
		Try(2,A[1],k-1);
		C[1] = 0;
		Try(2,0,k);
		for ( int i = 1 ; i <= n ; i++ ){
			std::cout<<X[i]<<" ";
		} 
		std::cout<<std::endl; 
		std::cout<<res;
		return 0;
	}
