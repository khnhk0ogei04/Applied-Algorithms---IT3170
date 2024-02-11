#include<bits/stdc++.h>
typedef long long ll;
const int MAXN = 100005;
using namespace std;
	
	int n;
	int res = 0,X[22];
	void PrintSolution(){
		res++;
		for ( int i = 1 ; i <= n ; i++ ){
			if (X[i] == 0)
				std::cout<<"(";
			else std::cout<<")";
		}
		std::cout<<endl;
	}
	void Try( int i, int cnt1, int cnt2, int diff ){
		if ( i == n + 1 && cnt1 == cnt2 ){
			PrintSolution();
			return;
		}
		if (cnt1 > n/2 || cnt2 > n/2) return;
		if (cnt1 < cnt2) return;
		for ( int j = 0 ; j <= 1 ; j++ ){
			X[i] = j;
			if (j == 0) Try(i+1,cnt1 + 1,cnt2,diff+1);
			else Try(i+1,cnt1,cnt2 + 1,diff-1);
		}
	}
	int main(){
		ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);
		std::cin>>n;
		Try(1,0,0,0);
		std::cout<<res;
		return 0;
	}
