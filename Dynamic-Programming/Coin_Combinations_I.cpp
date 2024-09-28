/**
 * Problem Name: Coin Combinations I
 * Problem Link: https://cses.fi/problemset/task/1635
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

int n, sum;
int dp[N];
vector<int> coins;

int solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int ind = 1; ind <= sum; ind++) {
        for(int coin: coins) {
            if (ind - coin >= 0)
                dp[ind] += dp[ind-coin];
            else
                break;
        }
        dp[ind] %= MOD;
    }
    return dp[sum];
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int coin;
    cin >> n >> sum;
    for(int ind = 0; ind < n; ind++) {
        cin >> coin;
        coins.push_back(coin);
    }
    sort(coins.begin(), coins.end());
    cout << solve() << endl;
    return 0;
}
