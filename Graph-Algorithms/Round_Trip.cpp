#include <bits/stdc++.h>
using namespace std;

#define INF 1LL << 60
#define int long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << endl

const int N = 100005;

int n, m;
int root, leaf;
int par[N];
bool vis[N], flag;
vector<int> adj[N];

void dfs(int u, int p) {
    cout << u << " " << p << endl;
    par[u] = p;
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v])
            dfs(v, u);
        else {
            root = v;
            leaf = u;
            flag = true;
            return;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    flag = false;
    memset(vis, false, sizeof(vis));
    int i, u, v;
    vector<int> ans;

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        vis[i] = false;
        adj[i].clear();
    }
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(int v: adj[i])
            cout << v << " ";
        cout << endl;
    }
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, -1);
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    deb(root);
    memset(vis, false, sizeof(vis));
    dfs(root, -1);
    ans.push_back(root);
    while (leaf != root)
    {
        ans.push_back(leaf);
        leaf = par[leaf];
    }
    cout << ans.size() << endl;
    for (int v : ans)
        cout << v << " ";
    cout << endl;
    return 0;
}
