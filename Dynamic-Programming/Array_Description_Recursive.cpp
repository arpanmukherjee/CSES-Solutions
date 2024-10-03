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

int solve(int ind, int num) {
    if(ind == n-1) {
        if (ar[ind]) {
            return dp[ind][num] = (ar[ind] == num);
        } else {
            return dp[ind][num] = (num > 0 and num <= m);
        }
    } else if(num > m or num <= 0) {
        return 0;
    } else if(dp[ind][num] != -1) {
        return dp[ind][num];
    } else if(ar[ind] and ar[ind] != num) {
        return dp[ind][num] = 0;
    }

    int ans = solve(ind+1, num) + solve(ind+1, num+1) + solve(ind+1, num-1);
    ans %= MOD;

    return dp[ind][num] = ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    ar.resize(n);
    for(auto& x: ar)
        cin >> x;

    int ans = 0;
    for(int ind = 1; ind <= m; ind++){
        ans += solve(0, ind);
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
