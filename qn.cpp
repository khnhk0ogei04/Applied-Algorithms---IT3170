#include<bits/stdc++.h>
using namespace std;
	std::string s;
	void solve(){
		int l1 = -1,r1 = -1,l2 = -1,r2 = -1,ans;
		std::cin>>s;
		for ( int i = 0 ; i < s.length(); i++ ){
			if (s[i] == '0') {
			    l1 = i;
			    break;
			}
		}
		for ( int i = s.length() - 1 ; i >= 0 ; i-- ){
			if (s[i] == '0') {
			    r1 = i - 1;
			    break;
			}
		}
		for ( int i = 0 ; i < s.length(); i++ ){
			if (s[i] == '1') {
			    l2 = i;
			    break;
			}
		}
		for ( int i = s.length() - 1 ; i >= 0 ; i-- ){
			if (s[i] == '1') {
			       r2 = i - 1;
			       break;
			}
		}
		if (r2 - l2 > r1 - l1) std::cout<<l2<<" "<<r2<<" "<<l2+1<<" "<<r2+1;
		else std::cout<<l1<<" "<<r1<<" "<<l1+1<<" "<<r1+1;
		
	}
	int main( int argc, const char** argv ){
		solve();
		return 0;
	}
	
