#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 1000005;
const int MOD = 1e9+7;

int dp[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, j, n;
    cin >> n;
    dp[0] = dp[1] = 1LL;
    for(i = 2 ; i <= n ; i++) {
        dp[i] = 0LL;
        for(j = 1 ; j <= 6 ; j++) {
            if(i-j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
                if(dp[i] < 0)
                    dp[i] += MOD;
            }
            else
                break;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
