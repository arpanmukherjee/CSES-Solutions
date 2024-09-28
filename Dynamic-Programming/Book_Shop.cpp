/**
 * Problem Name: Book Shop
 * Problem Link: https://cses.fi/problemset/task/1158
 * Author: @arpn
 */

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>
#define deb(x)  cout << #x << ": " << x << endl

const int N = 1000005;
const int MOD = 1e9+7;

vector<int> prices, pages;
int n, maxPrice, dp[N];

int solve() {
    int bookPage, bookPrice;
    for(int ind = 0; ind < n; ind++) {
        bookPage = pages[ind];
        bookPrice = prices[ind];
        for(int price = maxPrice; price >= bookPrice; price--)
            dp[price] = max(dp[price], dp[price-bookPrice] + bookPage);
    }
    return dp[maxPrice];
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> maxPrice;
    prices.resize(n), pages.resize(n);

    for(auto &price: prices)    cin >> price;
    for(auto &page: pages)      cin >> page;

    cout << solve() << endl;

    return 0;
}
