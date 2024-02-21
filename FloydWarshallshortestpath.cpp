#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<queue>
#include<stdlib.h>
#define ll long long
#define MAXN 10005
#define inf 1e9 + 7
using namespace std;
int V,E;
int dp[MAXN][MAXN];
int nextNode[MAXN];

//Functions
void floydWarshall(){

    for (int k = 1; k <= V; ++k)
        for (int u = 1; u <= V; ++u) if ( u != k )
            for (int v = 1; v <= V; ++v) if ( v != u && v != k )
                dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
         
       
    
}

void trace(int u, int v){

    for (int k = 1; k <= V; ++k){

        if (u == k || k == v)  continue;

        if (dp[u][v] == dp[u][k] + dp[k][v]){

            nextNode[u] = k;
            nextNode[k] = v;

            trace(u, k);

            trace(k, v);
        }
    }
}

void printAnswer(int s, int t){

    cout << dp[s][t] << endl;

    int u = s;

    while (u != -1){

        cout << u << " ";

        u = nextNode[u];
    }
}

void solve(){

    int s, t; cin >> s >> t;

    nextNode[s] = t; 
    nextNode[t] = -1;

    floydWarshall();

    trace(s , t);

    printAnswer(s, t);
}

//
int main(int argc, char **argv){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
	memset(dp,inf,sizeof(dp));
    for (int i = 0; i < E; ++i){

        int u, v, weight;  cin >> u >> v >> weight;

        dp[u][v] = weight;
    }

    solve();    

    return 0;
}
