#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 100005;

int n, m;
bool vis[N];
vector<int> ans;
vector<int> adj[N];

void dfs(int u) {
    vis[u] = true;
    for(int v: adj[u]) {
        if(!vis[v])
            dfs(v);
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(vis, false, sizeof(vis));
    int i, u, v;
    cin >> n >> m;
    for(i = 0 ; i < m ; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i = 1 ; i <= n ; i++) {
        if(!vis[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for(i = 0 ; i < ans.size() - 1 ; i++)
        cout << ans[i] << " " << ans[i+1] << endl;
    return 0;
}
