/**
 * Problem Name: Number Spiral
 * Problem Link: https://cses.fi/problemset/task/1071
 * Author: @arpn
 */

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 100005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, x, y, ans, add;
    cin >> t;
    while(t--) {
        cin >> y >> x;

        if(y > x) {
            ans = (y-1) * (y-1);
            add = (y&1) ? x : (y<<1)-x;
        } else {
            ans = (x-1) * (x-1);
            add = (x&1) ? (x<<1)-y : y;
        }

        cout << (ans+add) << endl;
    }
    return 0;
}
