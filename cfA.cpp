#include<bits/stdc++.h>
#define MAXN 10005
#define ll long long
using namespace std;
	void solve(){
		std::string s;
		char p[MAXN];
		std::cin>>s;
		int cnt = s.length()/2 - 1;
		for ( int i = 0 ; i < s.length() ; i++ ){
			if (s[i] == '?'){
				if (cnt > 0) {
					cnt--;
					p[i] = '(';
				}
				else p[i] = ')';
			}
			else p[i] = s[i];
		}
		int bal = 0, minbal = 0;
		for ( int i = 0 ; i < s.length(); i++ ){
			if (p[i] == '('){
				bal++;
			}
			else bal--;
			minbal = std::min(bal,minbal);
		}
		if (bal == 0 && minbal == 0) std::cout<<"YES"<<std::endl;
		else std::cout<<"NO"<<std::endl;
	}
	int main(){
		ll t;
		std::cin>>t;
		while (t--){
			solve();
		}
		return 0;
	}
