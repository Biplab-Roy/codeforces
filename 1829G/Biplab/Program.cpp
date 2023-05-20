#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int

using namespace std;
long long int mod = 1e9 + 7;

vector<pair<long long int, long long int>> dp(1e6+10, {0, 0});
long long int lim = 4, r = 3;

void pre_compute(int n){
    long long int i = (r*(r+1)) / 2, j;
    while(lim <= n) {
        dp[lim].first = dp[lim - r + 1].first + lim*lim;
        dp[lim].second = dp[lim - r + 1].first;
        for(j = lim + 1; j < lim + r - 1; j++) {
            if(j > 1e6) return;
            dp[j].first = dp[j - r].first + dp[j - r + 1].first - dp[j - r].second + j*j;
            dp[j].second = dp[j - r + 1].first;
        }
        dp[j].first = dp[j - r].first + j*j;
        j++;
        r++;
        lim = j;
    }
}

void init(){
    dp[1] = {1, 0};
    dp[2] = {5, 1};
    dp[3] = {10, 0};
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n].first << endl;
}


int main()
{
    init();
    pre_compute(1000000);
    int t;
    cin >> t;
    while (t--)
        solve();
}