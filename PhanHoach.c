#include<stdio.h>
#include<math.h>
#include<vector>
#include<stdlib.h>
#define MAXN 100005
typedef long long ll;
	std::vector<std::vector<int>> res;
	int n,count = 0;
	int A[MAXN];
	void backtrack( int sum, int pos, int cnt ){
		if (sum == n){
			std::vector<int>tmp;
			for ( int i = 0 ; i < cnt ; i++ ){
				tmp.push_back(A[i]);
			}
			res.push_back(tmp);
			count++;
			return;
		}
		for ( int j = pos ; j >= 1 ; j-- ){
			if ( sum + j <= n ){
				A[cnt] = j;
				backtrack(sum + j, j, cnt + 1);
			}
		}
	}
	int main(){
		scanf("%d", &n);
		backtrack(0,n,0);
		printf("%d\n",count);
		for ( auto x : res ){
			for ( int i = 0 ; i < x.size() ; i++ )
			printf("%d ",x[i]);
			printf("\n");
		}
		return 0;
	}
