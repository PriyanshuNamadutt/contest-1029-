#include<iostream>
#include<vector>
using namespace std;

bool solve( vector<int> &a ) {
    int n = a.size();

    int r = ( 2*a[0] - a[1]) % (n+1);
    if ( r != 0 ) return false;
    else {
        int y = ( 2*a[0] - a[1])/(n+1);
        int x = a[0] - n*y;

        if ( min(x,y) < 0 ) return false;

        for ( int i = 2; i < n; i++ ) {
            if ( a[i] != (i+1)*x + (n-i)*y ) return false;
        }
        return true;
    }
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }

        cout << ( solve(a) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
