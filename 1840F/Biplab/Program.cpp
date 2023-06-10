#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back
#define rep(i, s, e) for(int i = s; i < e; i++)
#define rrep(i, e, s) for(int i = e; i > s; i--)
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL))
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pt pair<int, int>
#define vi vector<int>
#define vll vector<long long>

using namespace std;
long long int mod = 1e9 + 7;

void solve()
{
    int n, m, r, t, d, coord;
    cin >> n >> m >> r;
    bool blocked[n + 1][m + 1][r + 1];
    memset(blocked, false, sizeof blocked);

    rep(i, 0, r) {
        cin >> t >> d >> coord;
        if(d == 1) {
            rep(j, 0, m + 1) {
                // charecter wait in position (coord, j) until this shoot
                // time spend before coming here is (j + coord)
                if(t - coord - j >= 0 && t - coord - j <= r) {
                    blocked[coord][j][t - coord - j] = true;    
                }
            }
        }
        else {
            rep(j, 0, n + 1) {
                // charecter wait in position (coord, j) until this shoot
                // min time spend before coming here is (j + coord)
                if(t - coord - j >= 0 && t - coord - j <= r) {
                    blocked[j][coord][t - coord - j] = true;
                }
            }
        }
    }
    bool dp[n + 1][m + 1][r + 1];
    memset(dp, false, sizeof dp);
    dp[0][0][0] = true;
    rep(i, 0, n + 1) {
        rep(j, 0, m + 1) {
            rep(k, 0, r + 1) {
                if(i + j + k == 0) continue;
                if(!blocked[i][j][k]) {
                    dp[i][j][k] = (i > 0 && dp[i - 1][j][k]) || 
                                    (j > 0 && dp[i][j - 1][k]) || 
                                    (k > 0 && dp[i][j][k - 1]);
                }
            }
        }
    }
    int ans = -1;
    rrep(k, r, -1) {
        if(dp[n][m][k]) ans = n + m + k;
    }
    cout << ans << endl;
}

int main()
{
    fast;
    #ifndef ONLINE_JUDGE
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}