#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
typedef std::vector<int> vi;
    using namespace std;
    int n;
    char a,b,c;
    void Tower( int n, char a, char b, char c ){
        if ( n == 1 ){
            std::cout<<a<<"->"<<c<<"\n";
            return;
        }
        Tower(n-1,a,c,b);
        Tower(1,a,b,c);
        Tower(n-1,b,a,c);
    }
    int main(int argc, const char** argv){
        std::cin>>n;
        a = 'A', b = 'B', c = 'C';
        Tower(n,a,b,c);
        return 0;
    }
