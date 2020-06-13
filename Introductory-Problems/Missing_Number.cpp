#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 100005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int i, x, n, ans;
    cin >> n;
    ans = (n*(n+1))>>1;
    for(i = 1 ; i < n ; i++) {
        cin >> x;
        ans -= x;
    }
    cout << ans << endl;
    return 0;
}
