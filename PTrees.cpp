#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,A[MAXN];
void solve(){
	std::cin>>n;
	for ( int i = 1 ; i <= n ; i++ ){
		std::cin>>A[i];
	}
	std::sort(A+1,A+n+1,std::greater<int>());
	int smax = 0;
	for (int i = 1; i <= n ; i++){
		if (A[i] + i > smax){
			smax = A[i] + i;
		}
	}
	std::cout<<smax+1;
}
int main(int argc, const char**argv){
	solve();
	return 0;
}
