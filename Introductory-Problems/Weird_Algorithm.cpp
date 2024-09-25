#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 100005;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while(n > 1) {
        cout << n << " ";
        if(n&1) {
            n *= 3;
            n += 1;
        }
        else
            n >>= 1;
    }
    cout << n << endl;
    return 0;
}
