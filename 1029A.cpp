#include<iostream>
#include<vector>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, x;
        cin >> n >> x;
        int cnt = 0;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            if ( a[i] == 1 ) cnt++;
        }    
        if ( cnt > x ) cout << "NO" <<endl;
        else {
            int i = 0;
            while( i < n ) {
                if ( a[i] == 1 )break;
                i++;
            }
            int j = n-1;
            while ( j >= 0 ) {
                if ( a[j] == 1 ) break;
                j--;
            }
            cout << ( j-i+1 <= x ? "YES" : "NO" ) <<endl;   
        }
    }
    return 0;
}
