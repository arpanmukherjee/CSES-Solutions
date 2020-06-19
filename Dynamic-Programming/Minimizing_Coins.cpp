#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 1000005;
const int MOD = 1e9+7;


int sum[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, n, k, x;
    vector<int> coins;

    cin >> n >> k;
    for(i = 1 ; i <= k ; i++)
        sum[i] = INF;
    for(i = 0 ; i < n ; i++) {
        cin >> x;
        coins.push_back(x);
        sum[x] = 1LL;
    }
    sort(coins.begin(), coins.end());
    sum[0] = 0LL;

    for(i = 1 ; i <= k ; i++) {
        for(int c: coins) {
            if(i - c >= 0)
                sum[i] = min(sum[i], 1 + sum[i - c]);
        }
    }
    if(sum[k] == INF)
        sum[k] = -1;
    cout << sum[k] << endl;
    return 0;
}
