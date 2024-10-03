/**
 * Problem Name: Two Sets
 * Problem Link: https://cses.fi/problemset/task/1092
 * Author: @arpn
 */

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cerr << #x << ": " << x << endl

const int N = 10005;

void printSet(unordered_set<int> s) {
    cout << s.size() << endl;
    for(int num: s)
        cout << num << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, sum;
    cin >> n;
    sum = (n*(n+1)) / 2;
    if(sum&1) {
        cout << "NO" << endl;
        return 0;
    }

    sum >>= 1;
    unordered_set<int> s1, s2;
    int ind = n;
    while(ind) {
        if(sum >= ind) {
            s1.insert(ind);
            sum -= ind;
        } else {
            s2.insert(ind);
        }
        ind--;
    }
    cout << "YES" << endl;
    printSet(s1);
    printSet(s2);
    return 0;
}


