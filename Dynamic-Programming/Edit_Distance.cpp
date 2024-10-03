/**
 * Problem Name: Edit Distance
 * Problem Link: https://cses.fi/problemset/task/1639
 * Author: @arpn
 */

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 5005;
const int MOD = 1e9+7;

int dp[N][N];
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    for(int i = 1; i <= s.size(); i++)
        dp[i][0] = i;
    for(int j = 1; j <= t.size(); j++)
        dp[0][j] = j;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] : 1 + dp[i-1][j-1];
            dp[i][j] = min(dp[i][j], min(1 + dp[i-1][j], 1 + dp[i][j-1]));
        }
    }
    cout << dp[s.size()][t.size()];
    return 0;
}
