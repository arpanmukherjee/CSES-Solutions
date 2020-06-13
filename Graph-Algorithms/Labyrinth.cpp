#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 1005;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
string dir = "LRUD";

int n, m;
string a[N];
bool vis[N][N];
pii par[N][N];
char whr[N][N];

bool valid(int x, int y) {
    if(x<0 or y<0 or x>=n or y>=m)
        return false;
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    bool flag;
    string ans;
    int i, j, x, y, sx, sy, tx, ty;
    queue<pii> q;
    ans = "";
    flag = false;
    cin >> n >> m;
    for(i = 0 ; i < n ; i++)
        cin >> a[i];
    for(i = 0 ; i < n ; i++) {
        for(j = 0 ; j < m ; j++) {
            vis[i][j] = false;
            if(a[i][j] == 'A') {
                sx = i;
                sy = j;
            }
        }
    }
    q.push(make_pair(sx, sy));
    par[sx][sy] = make_pair(-1, -1);
    whr[sx][sy] = ' ';

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        x = it.first;
        y = it.second;
        if(a[x][y] == 'B') {
            flag = true;
            break;
        }
        for(i = 0 ; i < 4 ; i++) {
            tx = x + dx[i];
            ty = y + dy[i];
            if(valid(tx, ty) and !vis[tx][ty] and (a[tx][ty] == '.' or a[tx][ty] == 'B')) {
                whr[tx][ty] = dir[i];
                vis[tx][ty] = true;
                par[tx][ty]  = make_pair(x, y);
                q.push(make_pair(tx, ty));
            }
        }
    }
    if(!flag) {
        cout << "NO\n";
        return 0;
    }
    while(whr[x][y] != ' ') {
        ans += whr[x][y];
        tx = x;
        ty = y;
        x = par[tx][ty].first;
        y = par[tx][ty].second;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
