#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 100005;


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    int i, j, ans;
    cin >> s;
    i = ans = 0;
    while(i < s.size()) {
        j = i + 1;
        while(j < s.size() and s[i] == s[j])
            j++;
        ans = max(ans, j - i);
        i = j;
    }
    cout << ans << endl;
    return 0;
}
