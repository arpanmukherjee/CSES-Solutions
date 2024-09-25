#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 200005;
const int MOD = 1e9+7;

// https://codeforces.com/blog/entry/20935

int n, diameter;
int f[N], g[N];
vector<int> tree[N];

void dfs(int src, int par) {
    f[src] = g[src] = 0;
    vector<int> fValues;
    for(int child: tree[src]) {
        if(child == par)
            continue;
        dfs(child, src);
        fValues.push_back(f[child]);
    }

    sort(fValues.begin(), fValues.end());

    if(fValues.size() >= 1)
        f[src] = 1 + fValues.back();

    if(fValues.size() >= 2)
        g[src] = 2 + fValues.back() + fValues[fValues.size()-2];
    else
        g[src] = f[src];
    diameter = max(diameter, max(f[src], g[src]));
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b;
    cin >> n;
    for(int ind = 1; ind < n; ind++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    diameter = 0;
    dfs(1, -1);
    cout << diameter << endl;
    return 0;
}
