#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 200005;
const int MOD = 1e9+7;

// https://codeforces.com/blog/entry/79048

int n;
int f[N], g[N];
vector<int> tree[N];

pii bfs(int src) {
    pii ans;
    queue<pii> Q;
    int node, dist;
    vector<bool> vis(n+1, false);

    Q.push({src, 0});
    ans = {src, 0};
    vis[src] = true;
    while(!Q.empty()) {
        node = Q.front().first;
        dist = Q.front().second;
        if(dist > ans.second)
            ans = Q.front();
        Q.pop();
        for(int child: tree[node]) {
            if(!vis[child]) {
                vis[child] = true;
                Q.push({child, dist+1});
            }
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pii ans;
    int a, b;
    cin >> n;
    for(int ind = 1; ind < n; ind++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    pii end1 = bfs(1);
    pii end2 = bfs(end1.first);

    cout << end2.second << endl;
    return 0;
}
