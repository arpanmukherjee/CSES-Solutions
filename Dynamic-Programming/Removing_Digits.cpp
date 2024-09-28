/**
 * Problem Name: Removing Digits
 * Problem Link: https://cses.fi/problemset/task/1637
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

int n;
int dp[N];

int solve(int num) {
    if(num == 0) {
        return dp[num] = 0;
    } else if(dp[num] != -1) {
        return dp[num];
    }

    int val, ans, digit;
    val = num;
    ans = INT_MAX;
    while (val) {
        digit = val % 10;
        val /= 10;
        if(digit)
            ans = min(ans, 1 + solve(num-digit));
    }

    return dp[num] = ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
