#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 100005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, odd, even;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    else if(n == 2 or n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if(n&1) {
        odd = n;
        even = n - 1;
    }
    else {
        even = n;
        odd = n - 1;
    }
    while(odd > 0) {
        cout << odd << " ";
        odd -= 2;
    }
    while(even > 0) {
        cout << even << " ";
        even -= 2;
    }
    cout << endl;
    return 0;
}
