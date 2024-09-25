#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 200005;
const int MOD = 1e9+7;


/**
 * For each node, we want to calculate maximum distance to another node.
 * Previously we saw that that if we start a BFS from any node, we end up on either of the diametric end.
 * We can use this fact to efficiently compute the answer.
 * Let's calculate distances of each node from both the ends of the diameter.
 *
 * Then maximum distance of each node can be calculated as:
 * max_distance[u] = max(distance_from_diametric_end1[u], distance_from_diametric_end2[u])
*/

int n, ans[N];
vector<int> tree[N];


int bfs(int src) {
    pii end;
    queue<pii> Q;
    int node, dist;
    vector<bool> vis(n+1, false);

    Q.push({src, 0});
    end = {src, 0};
    vis[src] = true;
    while(!Q.empty()) {
        node = Q.front().first;
        dist = Q.front().second;
        if(dist > end.second) {
            end = Q.front();
        }
        Q.pop();
        for(int child: tree[node]) {
            if(!vis[child]) {
                vis[child] = true;
                ans[child] = max(ans[child], dist + 1);
                Q.push({child, dist+1});
            }
        }
    }
    return end.first;
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

    // Find first end of the diameter
    int end1 = bfs(1);

    // Find second end of the diameter
    int end2 = bfs(end1);

    // Run one more bfs from end2 to calculate effective distance
    bfs(end2);

    for(int ind = 1; ind <= n; ind++)
        cout << ans[ind] << " ";
    cout << endl;
    return 0;
}
