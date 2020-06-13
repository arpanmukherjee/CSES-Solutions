#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 100005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x, ans, temp;
    cin >> n;
    cin >> temp;
    ans = 0;
    n--;
    while(n--) {
        cin >> x;
        ans += max(0LL, temp - x);
        temp = max(temp, x);
    }
    cout << ans << endl;
    return 0;
}
