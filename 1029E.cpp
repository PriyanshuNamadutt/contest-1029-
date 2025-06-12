#include<iostream>
#include<vector>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a(n) , b(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }
        for ( int i = 0; i < n; i++ ) {
            cin >> b[i];
        }
        if ( a[n-1] == b[n-1] ) cout << n << endl;
        else {
            int ans = -1;
            vector<bool> vis(n+1);
            for ( int i = n-2; i >= 0; i-- ) {
                if ( a[i] == b[i] || a[i] == a[i+1] || b[i] == b[i+1] || vis[a[i]] || vis[b[i]] ) {
                    ans = i;
                    break;
                }
                vis[a[i+1]] = true , vis[b[i+1]] = true;
            }
            cout << ans+1 << endl;
        } 
    }
    return 0;
}
