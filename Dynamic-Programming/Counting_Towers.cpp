/**
 * Problem Name: Counting Towers
 * Problem Link: https://cses.fi/problemset/task/2413
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


//                                      _  _
// dp[i][1] = last blocks are separate | || |
//                                   _ _
// dp[i][2] = last blocks are fused |   |

// transition:
//              _  _    _  _    _  _    _  _     _ _
//  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
// | || | =>   | || |, | || |, | || |, | || |,  | | |
//              _ _    _ _    _ _
//  _ _        |   |  |_|_|  |_ _|
// |   |  =>   |   |, |   |, |   |

// dp[i][1] = dp[i-1][1]*4 + dp[i-1][2]
// dp[i][2] = dp[i-1][1] + dp[i-1][2]*2

int dp[N][3];

void preCompute() {
    dp[1][1] = dp[1][2] = 1;
    for(int ind = 2; ind < N; ind++) {
        dp[ind][1] = ((dp[ind-1][1] << 2) + dp[ind-1][2]) % MOD;
        dp[ind][2] = (dp[ind-1][1] + (dp[ind-1][2] << 1)) % MOD;
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    preCompute();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (dp[n][1] + dp[n][2]) % MOD << endl;
    }

    return 0;
}
