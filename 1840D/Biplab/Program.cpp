#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    srand(time(NULL))
#define yes cout << "YES\n"
#define no cout << "NO\n"

using namespace std;
long long int mod = 1e9 + 7;

bool possible(vector<long long int> &v, long long int m) {
    int n = v.size();
    auto it = upper_bound(v.begin(), v.end(), v[0] + 2*m);
    if(it == v.end()) return true;
    it = upper_bound(v.begin(), v.end(), *it + 2*m);
    if(it == v.end()) return true;
    it = upper_bound(v.begin(), v.end(), *it + 2*m);
    return (it == v.end());
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<long long, bool> mp;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]] = true;
    }
    if (mp.size() <= 3)
    {
        cout << 0 << endl;
        return;
    }
    sort(v.begin(), v.end());
    long long l = 0, r = 1e9, ans = -1;

    while(l <= r) {
        long long int mid = (l + r) / 2;
        if(possible(v, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    } 

    cout << ans << endl;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}