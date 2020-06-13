#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 10005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int i, n, ans;
    cin >> n;
    for(i = 1 ; i <= n ; i++) {
        ans = (i - 1)*(i + 4)*((i*i) - (3*i) + 4);
        cout << ans/2 << endl;
    }
    return 0;
}
