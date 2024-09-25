#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 100005;

int n, m;
int par[N];
bool vis[N];
vector<int> adj[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(vis, false, sizeof(vis));
    bool flag = false;
    queue<pii> q;
    vector<int> ans;
    int i, u, v, d;

    cin >> n >> m;
    for(i = 0 ; i < m ; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    par[1] = -1;
    vis[1] = true;
    q.push(make_pair(1, 1));
    while (!q.empty())
    {
        u = q.front().first;
        d = q.front().second;
        q.pop();
        if(u == n) {
            flag = true;
            break;
        }
        for(int v: adj[u]) {
            if(!vis[v]) {
                par[v] = u;
                vis[v] = true;
                q.push(make_pair(v, d + 1));
            }
        }
    }
    if(!flag)
        cout << "IMPOSSIBLE\n";
    else {
        cout << d << endl;
        while(par[u] != -1) {
            ans.push_back(u);
            u = par[u];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for(int u: ans)
            cout << u << " ";
    }
    return 0;
}
