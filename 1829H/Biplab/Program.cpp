#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
long long int mod = 1e9 + 7;

int countSetBits(int n){
    int set = 0;
    for(int i = 7; i >=0 ; i--){
        if((n >> i) & 1) set++;
    }
    return set;
}

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    vector<vector<long long int>> dp(n+1, vector<long long int>(64, 0));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        // start fresh
        dp[i][v[i]]++;
        for(int j = 0; j <=63; j++){
            // when v[i] excluded
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            // including v[i]
            dp[i][v[i] & j] = (dp[i][v[i] & j] + dp[i-1][j]) % mod;
        }
    }
    long long int ans = 0;
    for(int i = 0; i <= 63; i++){
        if(countSetBits(i)==k) ans += dp[n][i];
        ans = ans % mod;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}