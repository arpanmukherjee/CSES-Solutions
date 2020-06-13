#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 1005;

string a[N];
int n, m;
bool vis[N][N];

void dfs(int x, int y) {
    if(x<0 or y<0 or x>=n or y>=m)
        return;
    if(vis[x][y] or a[x][y] == '#')
        return;
    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, j, ans;
    ans = 0;
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for(i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(i = 0 ; i < n ; i++) {
        for(j = 0 ; j < m ; j++) {
            if(a[i][j] == '.' and !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
