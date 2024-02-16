#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int main( int argc, const char** argv ){
	std::stack<int>st;
	std::map<char,int>m;
	std::string s;
	int sum[MAXN];
	m['('] = 1;
	m[')'] = -1;
	m['['] = 2;
	m[']'] = -2;
	std::cin>>s;
	if ( s[0] == '[' ) sum[0] = 1;
	else sum[0] = 0;
	for ( int i = 1; i < s.length() ; i++ ){
		sum[i] = sum[i-1] + (s[i] == '[');
	}
	for ( int i = 0 ; i < s.length(); i++ ){
		if (s[i] == '(' || s[i] == '[' || st.empty())
			st.push(i);
		else if (m[s[i]] + m[s[st.top()]] == 0)
			st.pop();
		else st.push(i);
	}
	std::cout<<st.size();
	if (st.empty()){
		int ans = sum[s.length()-1];
		std::cout<<ans<<std::endl;
		if (ans) {
			std::cout<<s;
		}
	}
	else{
		int ans = 0;
		int ss,e,ns,ne;
		e = s.length() - 1;
		if (sum[e] - sum[st.top()] > ans){
			ans = sum[e] - sum[st.top()];
			ne = e;
			ns = st.top() + 1;
		}
		while (st.size() > 1){
			e = st.top() - 1;
			st.pop();
			ss = st.top();
			if (sum[e] - sum[ss] > ans){
				ans = sum[e] - sum[ss];
				ne = e;
				ns = ss + 1;
			}
		}
		e = st.top();
		if (st.top() > 0) e -= 1;
		if ( e == 0 ) sum[0] = 0;
		if (sum[e] > ans){
			ans = sum[e];
			ns = 0;
			ne = e;
		}
		if (ans) {
			std::cout<<ans<<std::endl;
		for ( int i = ns ; i <= ne ; i++ ){
			std::cout<<s[i];
		}
	}
	else std::cout<<"0"<<std::endl;
	}
	return 0;
}