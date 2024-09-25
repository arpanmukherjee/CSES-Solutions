#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 200005;
const int MOD = 1e9+7;

vector<int> tree[N];
int dp[N][2];
int n;

void dfs(int src, int par) {
    bool isLeaf = true;
    dp[src][0] = dp[src][1] = 0;
    for(int child: tree[src]) {
        if(child == par)
            continue;
        isLeaf = false;
        dfs(child, src);
    }
    if(isLeaf)
        return;

    int childValue;

    // Not taking any edge from src node
    for(int child: tree[src]) {
        if(child == par)
            continue;

        childValue = max(dp[child][0], dp[child][1]);
        dp[src][0] += childValue;
    }

    // Taking the only edge between src->child
        for(int child: tree[src]) {
        if(child == par)
            continue;

        childValue = max(dp[child][0], dp[child][1]);
        dp[src][1] = max(dp[src][1], (dp[src][0] - childValue) + 1 + dp[child][0]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b;
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}