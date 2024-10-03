/**
 * Problem Name: Array Description
 * Problem Link: https://cses.fi/problemset/task/1746
 * Author: @arpn
 */

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 100005;
const int MOD = 1e9+7;

int n, m;
vector<int> ar;
int dp[N][105];

bool isValid(int x) {
    return (x > 0 and x <= m);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    ar.resize(n);
    for(auto& x: ar)
        cin >> x;

    if(ar[0] == 0) {
        for(int num = 1; num <= m; num++)
            dp[0][num] = 1;
    } else {
        dp[0][ar[0]] = 1;
    }
    for(int ind = 1; ind < n; ind++) {
        if (ar[ind] == 0) {
            for(int num = 1; num <= m; num++) {
                dp[ind][num] = dp[ind-1][num];
                dp[ind][num] += (isValid(num-1) ? dp[ind-1][num-1] : 0);
                dp[ind][num] += (isValid(num+1) ? dp[ind-1][num+1] : 0);
                dp[ind][num] %= MOD;
            }
        } else {
            dp[ind][ar[ind]] = dp[ind-1][ar[ind]];
            dp[ind][ar[ind]] += (isValid(ar[ind]-1) ? dp[ind-1][ar[ind]-1] : 0);
            dp[ind][ar[ind]] += (isValid(ar[ind]+1) ? dp[ind-1][ar[ind]+1] : 0);
            dp[ind][ar[ind]] %= MOD;
        }
    }
    int ans = 0;
    for(int num = 1; num <= m; num++)
        ans = (ans + dp[n-1][num]) % MOD;
    cout << ans << endl;
    return 0;
}


