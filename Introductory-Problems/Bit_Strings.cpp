/**
 * Problem Name: Bit Strings
 * Problem Link: https://cses.fi/problemset/task/1617
 * Author: @arpn
 */

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 1000005;
const int MOD = 1e9+7;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, ans;
    ans = 1L;
    cin >> n;
    while(n--) {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
