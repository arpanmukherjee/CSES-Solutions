#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 10005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, n, s1, s2, ans;
    vector<int> a;
    vector<int> b;
    cin >> n;
    ans = (n*(n+1)) / 2;
    if(ans&1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    s1 = s2 = 0;
    for(i = 1 ; i <= n ; i++) {
        if(s1 <= s2) {
            s1 += i;
            a.push_back(i);
        }
        else {
            s2 += i;
            b.push_back(i);
        }
    }
    cout << a.size() << endl;
    for(int x: a)
        cout << x << " ";
    cout << endl;
    cout << b.size() << endl;
    for(int x: b)
        cout << x << " ";
    cout << endl;
    return 0;
}
