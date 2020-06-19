#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 100005;
const int MOD = 1e9+7;

int n, m;
bool cycle;
int c_beg, c_end;
vector<int> ans;
int vis[N], par[N], lvl[N];
vector<int> adj[N];

bool dfs(int u, int dist) {
    vis[u] = 1;
    lvl[u] = dist;
    for(int v: adj[u]) {
        if(!vis[v]) {
            par[v] = u;
            if(dfs(v, dist + 1))
                return true;
        }
        else if(v == par[u])
            continue;
        else if(vis[v] == 1 and (lvl[u] - lvl[v]) >= 2) {
            c_beg = v;
            c_end = u;
            return true;
        }
    }
    vis[u] = 2;
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, x, y;
    c_beg = -1;
    memset(vis, 0, sizeof(vis));
    memset(lvl, 0, sizeof(lvl));
    memset(par, -1, sizeof(par));

    cin >> n >> m;
    for(i = 0 ; i < m ; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i = 1 ; i <= n ; i++) {
        if(!vis[i])
            if(dfs(i, 0))
                break;
    }
    if(c_beg == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    ans.push_back(c_beg);
    while(c_end != c_beg) {
        ans.push_back(c_end);
        c_end = par[c_end];
    }
    ans.push_back(c_beg);
    cout << ans.size() << endl;
    for(int x: ans)
        cout << x << " ";
    return 0;
}
