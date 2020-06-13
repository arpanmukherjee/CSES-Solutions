#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 100005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, x, y, ans;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        if(x == 1 and y == 1) {
            cout << 1 << endl;
            continue;
        }
        if(x&1)
            ans = ((x - 1) * (x - 1)) + 1;
        else
            ans = x * x;
        cout << ans << endl;
    }
    return 0;
}
