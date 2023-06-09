#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define x first
#define y second
#define pt pair<int, int>
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL))
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

using namespace std;
long long int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int arr[n+2] = {0};
    for(int i = 1; i <= n; i++) cin >> arr[i];
    arr[n+1] = n+1;
    int dp[n+2][n+1] = {0};
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = n + 1;
        }
    }
    for(int  i = 0; i <= n; i++) dp[0][i] = 0;
    // dp[0][i] = 0
    /*
    dp[i][j] = dp[i-1][j] when arr[i-1] < arr[i]
             = dp[k][j] + (i - k - 1) when arr[k] < arr[i]
    */
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 0; j <= n; j++) {
            if(j) dp[i][j] = n+1;
            if(arr[i-1] < arr[i]) dp[i][j] = dp[i-1][j];
            if(j)
                for(int k = 0; k < i; k++) {
                    if(arr[k] < arr[i])
                        dp[i][j] = min(dp[i][j], dp[k][j - 1] + i - k - 1);
                }
        }
    }
    for(int j = 1; j <= n; j++) cout << dp[n + 1][j] <<" ";
    cout << endl;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}