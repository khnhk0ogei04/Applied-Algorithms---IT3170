#include<bits/stdc++.h>
const int MAXN = 100005;
using namespace std;
    int main(){
        int n,q,A[MAXN];
        std::cin>>n>>q;
        for ( int i = 1 ; i <= n ; i++ ){
            std::cin>>A[i];
        }
        std::sort(A+1,A+n+1);
        int res = 0;
        for ( int i = 1 ; i <= n ; i++ ){
            int k = q - A[i];
            int left = std::lower_bound(A+i+1,A+n+1,k)-A;
            if (A[left] != k) continue;
            int right = std::upper_bound(A+i+1,A+n+1,k)-A;
            res += right - left;
        }
        std::cout<<res;
        return 0;
    }
