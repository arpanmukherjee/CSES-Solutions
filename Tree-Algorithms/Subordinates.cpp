#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 200005;
const int MOD = 1e9+7;

int sub[N];
vector<int> tree[N];

void dfs(int src) {
    sub[src] = 0;
    for(int child: tree[src]) {
        dfs(child);
        sub[src] += (1 + sub[child]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, a;
    cin >> n;
    for(int ind = 2; ind <= n; ind++) {
        cin >> a;
        tree[a].push_back(ind);
    }
    dfs(1);
    for(int ind = 1; ind <= n; ind++)
        cout << sub[ind] << " ";
    cout << endl;
    return 0;
}
