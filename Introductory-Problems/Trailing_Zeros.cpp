/**
 * Problem Name: Trailing Zeros
 * Problem Link: https://cses.fi/problemset/task/1618
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
    cin >> n;
    ans = 0;
    for(int ind = 5; n / ind >= 1; ind*=5)
        ans += (n/ind);
    cout << ans << endl;
    return 0;
}
