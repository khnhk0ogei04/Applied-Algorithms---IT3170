#include<bits/stdc++.h>
#include<iostream>
typedef std::pair<int,int> pii;
const int MAXN = 1e6 + 5;
	using namespace std;
	bool checknguyenam( char s ){
		if ( s == 'e' || s == 'u' || s == 'o' || s == 'a' || s == 'i' )
		return true;
		return false;
	}
	std::string s;
	int cnt[2][MAXN];
	int res[2];
	// cnt[0][i]: So nguyen am nam ben trai s[i]( tinh ca s[i])
	// cnt[1][i]: So phu am nam ben trai s[i] (tinh ca s[i])
	// res[0]: So xau con co dit la nguyen am
	// res[1]: So xau con co dit la phu am
	void solve(){
		std::cin>>s;
		if (checknguyenam(s[0]) == true) cnt[0][0] = 1;
		else cnt[1][0] = 1;
		for ( int i = 1 ;i < s.length() ; i++ ){
			if (checknguyenam(s[i])){
				res[0] += cnt[1][i-1];
				cnt[1][i] = cnt[1][i-1];
				cnt[0][i] = cnt[0][i-1] + 1;
			}
			else {
				res[1] += cnt[0][i-1];
				cnt[0][i] = cnt[0][i-1];
				cnt[1][i] = cnt[1][i-1] + 1;
			}
		}
		std::cout<<res[0] + res[1];
		
	}
	int main(){
		freopen("CAU4.INP","r",stdin);
	    freopen("CAU4.OUT","w",stdout);
		solve();
		return 0;
	}
	
	// Khong dung QHD
 /* #include<bits/stdc++.h>
#include<iostream>
typedef std::pair<int,int> pii;
const int MAXN = 100005;
	using namespace std;
	bool checknguyenam( char s ){
		if ( s == 'e' || s == 'u' || s == 'o' || s == 'a' || s == 'i' )
		return true;
		return false;
	}
	int main(){
	std::string s;
	std::cin>>s;
	int cnt1[MAXN],cnt2[MAXN],key = 0;
	if (checknguyenam(s[0])) cnt1[0] = 1;
	else cnt2[0] = 1;
	for ( int i = 1 ; i < s.length(); i++ ){
		if (checknguyenam(s[i])){
			cnt1[i] = cnt1[i-1] + 1;
			key += cnt2[i-1];
			cnt2[i] = cnt2[i-1];
		}
		else{
			cnt2[i] = cnt2[i-1] + 1;
			key += cnt1[i-1];
			cnt1[i] = cnt1[i-1];
		}
	}
	std::cout<<key;
	return 0;
}
 */
