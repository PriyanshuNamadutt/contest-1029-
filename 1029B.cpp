#include<iostream>
#include<vector>
using namespace std;

int main () {
    int t; cin >> t;
    while( t-- ) {
        int n; cin >> n;
        vector<int> a(n);
        int i = 0, start = 1;
        while( start <= n ) {
            a[i++] = start;
            start += 2;
        }
        int j = n-1, end = 2;
        while ( end <= n ) {
            a[j--] = end;
            end += 2;
        }

        for ( int k = 0; k < n; k++ ) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
    return 0;
}
