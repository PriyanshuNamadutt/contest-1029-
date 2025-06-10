#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int N = 2e5 + 5;
vector<int> power(N);

void dfs( int node, unordered_map<int,list<int>> &adj, int parent, int depth, int &lca, vector<int> &leaf ) {
    if ( adj[node].size() > 2 ) lca = depth;

    bool check = true;
    for( auto it : adj[node] ) {
        if ( it != parent ) {
            dfs(it, adj, node, depth+1, lca, leaf );
            check = false;
        }
    }
    if (check) leaf.push_back(depth);
}

int main () {
    
    power[0] = 1;
    for ( int i = 1; i < N; i++ ) {
        power[i] = (power[i-1]*2) % mod;
    }

    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        unordered_map<int,list<int>> adj;
        for ( int i = 0; i < n-1; i++ ) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        adj[1].push_back(0);
        int lca = 0;
        vector<int> leaf;
        dfs( 1 , adj , 0 , 1 , lca , leaf );

        if ( leaf.size() > 2 ) cout << 0 << endl;
        else if ( leaf.size() == 1 ) cout << power[n] << endl;
        else {
            int diff = abs( leaf[0] - leaf[1] );
            int num = diff + lca;
            if ( diff ) cout << ( power[num] + power[num-1] ) % mod << endl;
            else cout << ( 2*power[num] ) % mod << endl;
        }
    }
    return 0;
}
