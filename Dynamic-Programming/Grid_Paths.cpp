/**
 * Problem Name: Grid Paths
 * Problem Link: https://cses.fi/problemset/task/1638
 * Author: @arpn
 */

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 1005;
const int MOD = 1e9+7;

int n;
int ways[N][N];
string grid[N];


bool isValid(int x, int y) {
    return (x >= 0 and y >= 0 and x < n and y < n);
}

int solve(int x, int y) {
    if(!isValid(x, y)) {
        return 0;
    } else if(grid[x][y] == '*') {
        return ways[x][y] = 0;
    } else if(x == n-1 and y == n-1) {
        return ways[x][y] = 1;
    } else if(ways[x][y] != -1) {
        return ways[x][y];
    }
    int ans = (solve(x+1, y) + solve(x, y+1)) % MOD;
    return ways[x][y] = ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(ways, -1, sizeof(ways));
    cin >> n;
    for(int ind = 0; ind < n; ind++)
        cin >> grid[ind];

    cout << solve(0, 0) << endl;
    return 0;
}
