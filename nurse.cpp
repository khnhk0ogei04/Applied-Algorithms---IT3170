#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int n,k1,k2,k,res = 0,A[MAXN],dp[MAXN];
	void nurse( int A[], int x ){
		if ( x == n ){
			if ((dp[x-1] >= k1 && dp[x-1] <= k2) || dp[x-1] == 0){
				res++;
				for ( int i = 0 ; i < n ; i++ ){
					std::cout<<A[i]<<" ";
				}
				std::cout<<std::endl;
			}
		}
		
		else {
			if (dp[x-1] < k2){
				A[x] = 1;
				dp[x] = dp[x-1] + 1;
				nurse(A,x+1);
			}
			if (dp[x-1] >= k1){
				A[x] = 0;
				dp[x] = 0;
				nurse(A,x+1);
			}
		}
	}
		int main( int argc, const char** argv ){
			std::cin>>n>>k1>>k2;
			fill(dp,dp+n,0);
			A[0] = 1;
			dp[0] = 1;
			nurse(A,1);
			fill(dp,dp+n,0);
			A[0] = 0;
			dp[0] = 0;
			nurse(A,1);
			std::cout<<res;
			return 0;
		}
