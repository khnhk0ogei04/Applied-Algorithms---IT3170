#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
typedef std::vector<int> vi;
    using namespace std;
    int t;
    void solve(){
        int n,ok = 0;
        std::queue<pair<int,int>>q;
        std::cin>>n;
        q.push({n,0});
        while (!q.empty()){
            int u = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if ( u == 1 ){
                std::cout<<cnt<<std::endl;
                ok = 1;
                break;
            }
            q.push({u-1,cnt+1});
            if (u % 3 == 0) {
                q.push({u/3,cnt+1});
                continue;
            }
            if ( u % 2 == 0 ){
                q.push({u/2,cnt+1});
                continue;
            }
        }
    }
    int main(){
        std::cin>>t;
        while (t--){
            solve();
        }
        return 0;
    }
