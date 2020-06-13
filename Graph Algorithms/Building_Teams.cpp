#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 100005;


int n, m;
int ans[N];
bool vis[N], flag;
vector<int> adj[N];

void dfs(int u, int par) {
    ans[u] = par;
    vis[u] = true;
    for(int v: adj[u]) {
        if(!vis[v])
            dfs(v, 1^par);
        flag &= (ans[u] != ans[v]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    flag = true;
    memset(vis, false, sizeof(vis));
    int i, u, v, d;

    cin >> n >> m;
    for(i = 0 ; i < m ; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i = 1 ; i <= n ; i++) {
        if(!vis[i])
            dfs(i, 1);
    }
    if(!flag)
        cout << "IMPOSSIBLE\n";
    else {
        for(i = 1 ; i <= n ; i++)
            cout << ans[i] + 1 << " ";
    }
    return 0;
}