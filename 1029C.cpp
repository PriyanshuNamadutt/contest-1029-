#include<bits/stdc++.h>
using namespace std;

int findidx( int idx, unordered_set<int> &st, vector<int> &a ) {
    unordered_set<int> required = st;
    for ( int i = idx; i < a.size(); i++ ) {
        required.erase( a[i] );
        st.insert(a[i]);
        if ( required.empty() ) return i;
    }
    return -1;
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        unordered_set<int> st;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }
        st.insert(a[0]);
        int cnt = 1;
        int i = 1;

        while ( i < n ) {
            int idx = findidx( i , st , a );
            if ( idx == -1 ) break;
            else {
                i = idx + 1;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
